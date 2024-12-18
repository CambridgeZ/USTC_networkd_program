#define _GNU_SOURCE 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <fcntl.h>
#include <assert.h>
#include <poll.h>
#include <string>

#define BUFFER_SIZE 64
#define USER_LIMIT 5
#define FD_LIMIT 65535

struct client_data{
    sockaddr_in address;
    char* write_buf;
    char buf[BUFFER_SIZE];
};

int setnonblocking(int fd){
    int old_option = fcntl(fd,F_GETFL);
    int new_option = old_option | O_NONBLOCK;
    fcntl(fd,F_SETFL,new_option);
    return old_option;
}

int main(int argc, char *argv[]){
    if(argc <= 2){
        printf("usage: %s ip_address port_number\n",basename(argv[0]));
        return 1;
    }
    const char* ip = argv[1];
    int port = atoi(argv[2]);

    int ret = 0;
    struct sockaddr_in address;
    bzero(&address,sizeof(address));
    address.sin_family = AF_INET;
    inet_pton(AF_INET,ip,&address.sin_addr);
    address.sin_port = htons(port);

    int listenfd = socket(PF_INET,SOCK_STREAM,0);
    assert(listenfd >= 0);

    ret = bind(listenfd,(struct sockaddr*)&address,sizeof(address));
    assert(ret != -1);

    ret = listen(listenfd,5);
    assert(ret != -1);

    client_data* users = new client_data[FD_LIMIT];//分配FD_LIMIT个client_data结构体
    pollfd fds[USER_LIMIT+1];//分配USER_LIMIT+1个pollfd结构体
    /*
        pollfd结构体:
        struct pollfd{
            int fd;//文件描述符
            short events;//请求的事件
            short revents;//返回的事件
        };
    */
    int user_counter = 0;
    for(int i = 1;i <= USER_LIMIT;++i){
        fds[i].fd = -1;//初始化为-1
        fds[i].events = 0;//初始化为0
    }
    fds[0].fd = listenfd;
    fds[0].events = POLLIN | POLLERR;
    fds[0].revents = 0;

    while(1){
        /*
            poll函数:
            int poll(struct pollfd fds[],nfds_t nfds,int timeout);
            fds:指向一个结构体数组的指针
            nfds:数组中结构体的数量
            timeout:超时时间
            返回值:就绪的文件描述符的数量
            作用：等待一组文件描述符的事件
        */
        ret = poll(fds,user_counter+1,-1);//阻塞
        if(ret < 0){
            printf("poll failure\n");
            break;
        }
        for(int i=0; i<user_counter+1; i++){
            /*
                遍历fds数组，处理每一个就绪的文件描述符
            */
            if((fds[i].fd == listenfd) && (fds[i].revents & POLLIN)){
                //有新的连接
                struct sockaddr_in client_address;
                socklen_t client_addrlength = sizeof(client_address);
                int connfd = accept(listenfd,(struct sockaddr*)&client_address,&client_addrlength);
                if(connfd < 0){
                    printf("errno is: %d\n",errno);
                    continue;
                }
                if(user_counter >= USER_LIMIT){
                    //连接太多
                    const char* info = "too many users\n";
                    printf("%s",info);
                    send(connfd,info,strlen(info),0);
                    close(connfd);
                    continue;
                }
                user_counter++;
                users[connfd].address = client_address;//保存客户端地址
                setnonblocking(connfd);// 设置非阻塞
                fds[user_counter].fd = connfd;//将新的连接加入到fds数组中
                fds[user_counter].events = POLLIN | POLLRDHUP | POLLERR;//监听可读、对端关闭、错误事件
                fds[user_counter].revents = 0;//初始化为0
                printf("comes a new user,now have %d users\n",user_counter);
            }else if(fds[i].revents & POLLERR){
                //出错
                printf("get an error from %d\n",fds[i].fd);
                char errors[100];
                memset(errors,'\0',100);
                socklen_t length = sizeof(errors);
                if(getsockopt(fds[i].fd,SOL_SOCKET,SO_ERROR,&errors,&length) < 0){
                    //获取socket选项失败
                    printf("get socket option failed\n");
                }
                continue;
            }else if(fds[i].revents & POLLRDHUP){
                //客户端关闭连接
                users[fds[i].fd] = users[fds[user_counter].fd];//将最后一个用户的数据拷贝到当前位置
                close(fds[i].fd);//关闭当前位置的文件描述符
                fds[i] = fds[user_counter];//将最后一个文件描述符的数据拷贝到当前位置
                i--;
                user_counter--;
                printf("a client left\n");
            }else if(fds[i].revents & POLLIN){//可读事件
                //处理客户端数据
                int connfd = fds[i].fd;
                
                memset(users[connfd].buf,'\0',BUFFER_SIZE);
                char from_which_client[100] = "from ";
                strcat(from_which_client,inet_ntoa(users[connfd].address.sin_addr));
                strcat(from_which_client,":");
                strcat(from_which_client,std::to_string(ntohs(users[connfd].address.sin_port)).c_str());
                strcat(from_which_client,": ");
                strcat(users[connfd].buf,from_which_client);
                ret = recv(connfd,users[connfd].buf + strlen(from_which_client),BUFFER_SIZE-1,0);
                printf("get %d bytes of client data %s from %d\n",ret,users[connfd].buf,connfd);
                if(ret < 0){
                    if(errno != EAGAIN){
                        close(connfd);
                        users[fds[i].fd] = users[fds[user_counter].fd];
                        fds[i] = fds[user_counter];
                        i--;
                        user_counter--;
                    }
                }else if(ret == 0){
                    //对端关闭连接
                    printf("code should not come to here\n");
                }else{
                    //将数据发送给其他客户端
                    for(int j=1;j<=user_counter;j++){
                        // if(fds[j].fd == connfd){
                        //     //跳过自己
                        //     continue;
                        // }
                        fds[j].events |= ~POLLIN; //取消监听可读事件
                        fds[j].events |= POLLOUT; //监听可写事件
                        users[fds[j].fd].write_buf = users[connfd].buf;
                    }
                }
            }else if(fds[i].revents & POLLOUT){
                //可写事件
                int connfd = fds[i].fd;
                if(!users[connfd].write_buf){
                    continue;
                }
                ret = send(connfd,users[connfd].write_buf,strlen(users[connfd].write_buf),0);
                users[connfd].write_buf = NULL;
                fds[i].events |= ~POLLOUT;
                fds[i].events |= POLLIN;
            }
        }
    }
    delete [] users;
    close(listenfd);
    return 0;
}
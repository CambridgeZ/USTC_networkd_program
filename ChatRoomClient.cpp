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

#define BUFFER_SIZE 64
int main(int argc,char* argv[]){
    if(argc <= 2){
        printf("usage: %s ip_address port_number\n",basename(argv[0]));
        return 1;
    }
    const char* ip = argv[1];
    int port = atoi(argv[2]);

    struct sockaddr_in server_address;
    bzero(&server_address,sizeof(server_address));
    server_address.sin_family = AF_INET;
    inet_pton(AF_INET,ip,&server_address.sin_addr);
    server_address.sin_port = htons(port);

    int sockfd = socket(PF_INET,SOCK_STREAM,0);
    assert(sockfd >= 0);
    if(connect(sockfd,(struct sockaddr*)&server_address,sizeof(server_address)) < 0){
        printf("connection failed\n");
        close(sockfd);
        return 1;
    }
    pollfd fds[2];//0是标准输入，1是socket
    /*
        注册文件描述符0和文件描述符sockfd上的可读事件
    */
    fds[0].fd = 0;
    fds[0].events = POLLIN;//标准输入
    fds[0].revents = 0;
    fds[1].fd = sockfd;
    fds[1].events = POLLIN | POLLRDHUP;//socket
    fds[1].revents = 0;

    char read_buf[BUFFER_SIZE];//读缓冲区
    int pipefd[2];//管道
    int ret = pipe(pipefd);//创建管道 
    assert(ret != -1);

    while(1){
        ret = poll(fds,2,-1);
        if(ret < 0){
            printf("poll failure\n");
            break;
        }
        if(fds[1].revents & POLLRDHUP){
            //服务器端关闭连接
            printf("server close the connection\n");
            break;
        }else if(fds[1].revents & POLLIN){
            //服务器发来数据
            memset(read_buf,'\0',BUFFER_SIZE);
            recv(fds[1].fd,read_buf,BUFFER_SIZE-1,0);
            printf("%s\n",read_buf);
        }
        if(fds[0].revents & POLLIN){
            //使用splice将用户输入的数据直接写到sockfd上（零拷贝）
            ret = splice(0,NULL,pipefd[1],NULL,32768,SPLICE_F_MORE | SPLICE_F_MOVE);//从标准输入读取数据到管道
            ret = splice(pipefd[0],NULL,sockfd,NULL,32768,SPLICE_F_MORE | SPLICE_F_MOVE);//从管道读取数据到sockfd
            /*
                splice函数的作用是将数据从一个文件描述符移动到另一个文件描述符，零拷贝
                splice(int fd_in, loff_t *off_in, int fd_out, loff_t *off_out, size_t len, unsigned int flags);
                fd_in：输入文件描述符
                off_in：输入文件描述符的偏移量
                fd_out：输出文件描述符
                off_out：输出文件描述符的偏移量
                len：要移动的字节数
                flags：标志位
            */
        }
    }
    close(sockfd);
    return 0;
}
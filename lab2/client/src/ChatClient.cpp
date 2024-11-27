#include "ChatClient.hpp"


ChatClient::ChatClient(const char* ip,int port):socket(port,ip){
    fds[0].fd = 0;
    fds[0].events = POLLIN;
    fds[0].revents = 0;
    fds[1].fd = socket.getFd();
    fds[1].events = POLLIN | POLLRDHUP;
    fds[1].revents = 0;

    // 创建管道
    int ret = pipe(pipefd);
    assert(ret != -1);
}

void ChatClient::run(){
    while(1){
        int ret = poll(fds,2,-1);
        if(ret < 0){
            printf("poll failure\n");
            break;
        }
        if(fds[1].revents & POLLRDHUP){
            // 服务器端关闭连接
            printf("server close the connection\n");
            break;
        }else if(fds[1].revents & POLLIN){
            // 服务器发来数据
            memset(read_buf,'\0',BUFFER_SIZE);
            recv(fds[1].fd,read_buf,BUFFER_SIZE-1,0);
            printf("%s\n",read_buf);
        }


        if(fds[0].revents & POLLIN){
            //使用splice将用户输入的数据直接写到sockfd上（零拷贝）
            ret = splice(0,NULL,pipefd[1],NULL,32768,SPLICE_F_MORE | SPLICE_F_MOVE);//从标准输入读取数据到管道
            ret = splice(pipefd[0],NULL,socket.getFd(),NULL,32768,SPLICE_F_MORE | SPLICE_F_MOVE);//从管道读取数据到sockfd
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
}
#include <sys/types.h> 
#include <sys/time.h>
#include <sys/select.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <arpa/inet.h>

int main(){
    int lfd = socket(AF_INET, SOCK_STREAM, 0);

    struct sockaddr_in serv_addr;
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(8888);
    serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);

    int ret = bind(lfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr));

    ret = listen(lfd, 128);

    fd_set readfds;
    FD_ZERO(&readfds);
    FD_SET(lfd, &readfds);

    int maxfd = lfd;

    while(1){
        fd_set tmpfds = readfds;
        struct timeval timeout;
        timeout.tv_sec = 5;
        timeout.tv_usec = 0;

        ret = select(maxfd+1, &tmpfds, NULL, NULL, &timeout);
        if(ret == -1){
            perror("select error");
            exit(1);
        }else if(ret == 0){
            printf("timeout\n");
        }else{
            if(FD_ISSET(lfd, &tmpfds)){
                struct sockaddr_in client_addr;
                socklen_t client_addr_len = sizeof(client_addr);
                int cfd = accept(lfd, (struct sockaddr*)&client_addr, &client_addr_len);
                FD_SET(cfd, &readfds);
                maxfd = maxfd > cfd ? maxfd : cfd;
            }else{
                for(int i = lfd+1; i <= maxfd; i++){
                    if(FD_ISSET(i, &tmpfds)){
                        char buf[1024] = {0};
                        int len = read(i, buf, sizeof(buf));
                        if(len == -1){
                            perror("read error");
                            exit(1);
                        }else if(len == 0){
                            printf("client closed\n");
                            close(i);
                            FD_CLR(i, &readfds);
                        }else{
                            printf("buf = %s\n", buf);
                        }
                    }
                }
            }
        }

    }

    close(lfd);

    return 0;

}
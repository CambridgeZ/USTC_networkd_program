#include <iostream>
#include <sys/select.h>
#include <sys/time.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>


int main(){
    // 设置超时时间
    struct timeval timeout;
    timeout.tv_sec = 2;
    timeout.tv_usec = 0;

    fd_set readfds;
    FD_ZERO(&readfds);
    FD_SET(0, &readfds);

    int ret = select(1, &readfds, NULL, NULL, &timeout);
    if(ret == -1){
        perror("select error");
        exit(1);
    }else if(ret == 0){
        printf("no data within 2 seconds\n");
    }else{
        if(FD_ISSET(0, &readfds)){
            char buf[1024] = {0};
            read(0, buf, sizeof(buf));
            printf("buf = %s\n", buf);
        }
    }

    return 0;

}
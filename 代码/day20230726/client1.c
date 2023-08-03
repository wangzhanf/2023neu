//client1.c
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main()
{
        int c_fd;
        int n_read;
        char readBuf[128];

        char *msg = "来自客户端的信息";
        struct sockaddr_in c_addr;

        memset(&c_addr,0,sizeof(struct sockaddr_in));

        //1.socket
        c_fd = socket(AF_INET, SOCK_STREAM,0);
        if(c_fd == -1){
                perror("socket");
                exit(-1);
        }

        c_addr.sin_family = AF_INET;//
        c_addr.sin_port = htons(8888);//转换字节序设置端口号
        inet_aton("172.20.92.231",&c_addr.sin_addr);

        //2.connect
        if(connect(c_fd,(struct sockaddr *)&c_addr,sizeof(struct sockaddr)) == -1){
                perror("connect");
                exit(-1);
        }

        //3.send
        write(c_fd,msg,strlen(msg));

        //4.read
        n_read = read(c_fd,readBuf,128);
        if(n_read == -1 ){
                perror("read");
        }else{
                printf("获得消息 :%d,%s\n",n_read,readBuf);
        }

        return 0;
}

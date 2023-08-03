//client2.c
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>



int main(int argc,char **argv)
{
        int c_fd;
        int n_read;
        char readBuf[128];

        char msg[128] = {0};

        struct sockaddr_in c_addr;
        if(argc != 3){
                printf("param is not good\n");
                exit(-1);
        }
        memset(&c_addr,0,sizeof(struct sockaddr_in));

        //1.socket
        c_fd = socket(AF_INET, SOCK_STREAM,0);
        if(c_fd == -1){
                perror("socket");
                exit(-1);
        }
 		c_addr.sin_family = AF_INET;//
        c_addr.sin_port = htons(atoi(argv[2]));
        inet_aton(argv[1],&c_addr.sin_addr);

        //2.connect
        if(connect(c_fd,(struct sockaddr *)&c_addr,sizeof(struct sockaddr)) == -1){
                perror("connect");
                exit(-1);
        }
		while(1){

                if(fork() == 0 ){
                        while(1){
                                memset(msg,0,sizeof(msg));
                                printf("input: ");
                                gets(msg);
                                //3.send
                                write(c_fd,msg,strlen(msg));
                        }
                }
                while(1){
                        memset(readBuf,0,sizeof(readBuf));
                        //4.read
                        n_read = read(c_fd,readBuf,128);
                        if(n_read == -1 ){
                                perror("read");
                        }else{
                                printf("get message from :%d,%s\n",n_read,readBuf);
                        }
                }
        }


        return 0;
}

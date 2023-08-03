//server3.c
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
        int s_fd;
        int c_fd;
        int n_read;
        char readBuf[128];
	int mark = 0;
        char msg[128] = {0};
        struct sockaddr_in s_addr;
        struct sockaddr_in c_addr;

        if(argc != 3){
                printf("需要传入ip和端口参数\n");
                exit(-1);
        }

        memset(&s_addr,0,sizeof(struct sockaddr_in));
        memset(&c_addr,0,sizeof(struct sockaddr_in));
        //1.socket
        s_fd = socket(AF_INET, SOCK_STREAM,0);
        if(s_fd == -1){
                perror("socket");
                exit(-1);
        }

        s_addr.sin_family = AF_INET;//
        s_addr.sin_port = htons(atoi(argv[2]));
        inet_aton(argv[1],&s_addr.sin_addr);

        //2.bind
        bind(s_fd,(struct sockaddr *)&s_addr,sizeof(struct sockaddr_in));

        //3. listen
        listen(s_fd,10);//监听数量
 //4.accept
        int clen = sizeof(struct sockaddr_in);
        while(1){

                c_fd = accept(s_fd,(struct sockaddr *)&c_addr,&clen);//
                if(c_fd == -1){
                        perror("accept");
                }
				mark ++;
                printf("get connect :%s\n",inet_ntoa(c_addr.sin_addr));//转换

                if(fork() == 0){//子进程干活

                        if(fork() == 0){
                                while(1){
                                        memset(msg,0,sizeof(msg));
                              			sprintf(msg,"Welcome NO.%d client",mark);
                                        //6.write
                                        write(c_fd,msg,strlen(msg));
                                        sleep(3);
                                        }
                                }
                        //5.read
                        while(1){
                                memset(readBuf,0,sizeof(readBuf));
                                n_read = read(c_fd,readBuf,128);
                                if(n_read == -1 ){
                                        perror("read");
                                }else{
                                        printf("get message:%d,%s\n",n_read,readBuf);
                                }
                        }
                        break;
                }
        }
        return 0;
}

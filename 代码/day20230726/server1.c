//server1.c
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
        int s_fd;
        int n_read;
        char readBuf[128];

        char *msg = "服务器发出的信息";
        struct sockaddr_in s_addr;
        struct sockaddr_in c_addr;

        memset(&s_addr,0,sizeof(struct sockaddr_in));
        memset(&c_addr,0,sizeof(struct sockaddr_in));

        //1.socket
        //1.创建套接字---socket()
        s_fd = socket(AF_INET, SOCK_STREAM,0);
        if(s_fd == -1){
                perror("socket");
                exit(-1);
        }
        s_addr.sin_family = AF_INET;//
        s_addr.sin_port = htons(8888);//转换大端字节序  //8888端口号
        inet_aton("172.20.92.231",&s_addr.sin_addr);//字符串格式转换为网络格式
        //2.bind
        //2.为套接字添加信息（IP地址和端口号）---bind()
        bind(s_fd,(struct sockaddr *)&s_addr,sizeof(struct sockaddr_in));
        //3. listen
        //3.监听网络连接---listen()
        listen(s_fd,10);//监听
        //4.accept
        //4.监听到有客户端接入，接受一个连接---accept()
        int clen = sizeof(struct sockaddr_in);
        int c_fd = accept(s_fd,(struct sockaddr *)&c_addr,&clen);//
        if(c_fd == -1){
                perror("accept");
        }
        printf("get connect :%s\n",inet_ntoa(c_addr.sin_addr));//网络格式转换为字符串格式
        //5.read
        //5.数据交互
        n_read = read(c_fd,readBuf,128);
        if(n_read == -1 ){
                perror("read");
        }else{
                printf("get message:%d,%s\n",n_read,readBuf);
        }
        
        //6.write
        //数据交互
        write(c_fd,msg,strlen(msg));

        return 0;
}

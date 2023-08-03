//文件的基本操作，遵循   打开     操作    关闭 
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
    //打开文件读取信息
    int  fd;//文件描述符
    fd = open("./my.txt",O_RDONLY);//返回-1代表打开文件失败
    char buf[512];//缓冲区
    ssize_t nread;
    if(fd == -1)
        return 126;//不推荐，可以使用 exit(-1)  
    else{
        //对文件操作，   读取内容
        nread  = read(fd,buf,512);
	write(1,"read succ\n",10);
        if(nread == -1)
            exit(8);
    }
        
    //关闭文件
    close(fd);
    return 0;
}

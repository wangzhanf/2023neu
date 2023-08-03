#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv)
{
	if(argc != 2){
		perror("eg.   ./myStat 文件名");
		exit(9);
	}else{
		int ret;
		struct stat statbuf;//用以封装获取的属性信息
		ret = stat(argv[1],&statbuf);
		//展示文件的属性信息
		printf("The %s Size is %ld\n",argv[1],statbuf.st_size);
	        printf("inode: %ld\n", statbuf.st_ino);
		switch(statbuf.st_mode & S_IFMT){
			case S_IFREG:
				printf("普通文件\n");
				break;
			default:
				printf("不是普通文件\n");
		}	

		if((statbuf.st_mode & S_IWOTH) == S_IWOTH)
			printf("其他用户可以对该文件写入\n");
	}
	return 0;
}

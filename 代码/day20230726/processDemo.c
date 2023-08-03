#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
	printf("当前进程编号：  %d\n",getpid());
	printf("当前进程的父进程编号：  %d\n",getppid());
	
	pid_t pid;
	char* message;
	int n;

	pid = fork();//派生进程：
	switch(pid){
		case -1:
			perror("fork failed");
			exit(9);
		case 0:
			message = "我是子进程\n";
			n = 3;
			break;
		default:
			message = "我是父进程\n";
			n = 5;
			break;
	}
	for(;n > 0;n--){
		puts(message);
		sleep(1);
	}
	//printf("通过fork派生了新的进程,返回的pid是：%d\n",pid);


	return 0;
}

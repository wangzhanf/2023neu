#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
int main(int argc,char *argv[])
{        
	int choice;        
	// 文件名
	char filename[512];
	while(1){
		printf("请选择想要使用的查找方式：\n1：使用自己编写的程序查看文件状态\n2：使用系统stst命令查看文件状态\n我的选择是：");
		scanf("%d",&choice);
		if (choice==1){
			printf("请输入文件名：");
			scanf("%s", filename);
			if(fork()==0){
				//子进程调用自己的mystat查看        
				execlp("mystat","./mystat",filename,NULL);        
				perror("execl failed");        
			}        
		}else if(choice==2){        
			printf("请输入文件名：");
			scanf("%s", filename);
			if(fork()==0){        
				//子进程调用系统stat查看        
				execlp("stat","stat",filename,NULL);        
				perror("execl failed");        
			}	
		}else{        
			printf("输入无效数字，退出程序。");        
			exit(9);        
		}        
		wait(NULL);        
		printf("子进程已结束\n");        
	}        
	return 0;
}

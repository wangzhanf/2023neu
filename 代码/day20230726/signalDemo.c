#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void sigint_handler(int signum)
{
	printf("欢迎下次再来,%d\n",signum);
	signal(SIGINT,SIG_DFL);
}


int main()
{
	signal(SIGINT,sigint_handler);
	while(1){
		printf("Hi!\n");
		sleep(1);
	}
	return 0;
}


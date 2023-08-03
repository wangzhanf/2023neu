#include <unistd.h>
#include <stdio.h>

int main()
{
	printf("当前进程的pid：%d\n",getpid());

	//exec系统调用
	execlp("ps","ps","-aux",0);

	printf("exec执行结束\n");
	return 0;
}

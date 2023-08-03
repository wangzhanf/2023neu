#include <stdio.h>
//客户端程序，调用库完成功能
#include "calc.h"
int main()
{
	int a = 5;
	int b = 3;
	int ret = add(a,b);
	printf("ret %d\n",ret);
	return 0;
}

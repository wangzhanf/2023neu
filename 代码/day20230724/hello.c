#include <stdio.h>

#define MAX 999     //不推荐

int gAge = 100;

void test01()
{
//	age = 100;  //error
	gAge = 100;
	int count;
}

enum CSIZE{
	M,
	XXXXL = 9
};

void test02()
{
	//常量演示
	const int MIN = 1;
	//
	int a = 0;
	scanf("%d",&a);
	if(a == XXXXL){
		//
	}
}

void test03()
{
	//已有代码段, 理解字符串的构造形式
	char strArr[] = {'c',':','\','u','s'};
	printf("%s\n",strArr);
	printf("c:\users\wangzhanf\n");
}

int main()
{
	//数据类型演示代码
//	char age = 18;
//	printf("age size: %d\n",sizeof(int));
//	printf("age:%d\n",age);

	//课堂练习代码   ，随机抽查    
	int age = 18;//  局部变量【函数内】
	char* pAge = (char*)&age;
	printf("%d\n",*pAge);
	printf("%d\n",*(pAge+1));
	printf("换行符是 \\n");
	
	
	//变量作用域
	test01();
	

	
 
	return 0;
}


#include <stdio.h>
#include <string.h>


//独立的声明文件     Person.h
#define MAXNAMELEN 20
typedef struct _Person{
	char name[MAXNAMELEN];
	int age;
	void (*printMe)(void);
	void (*add)(void);
}Person;


//初始化函数，形成正确的调用关系
void initPerson();

void PrintMe(void);
void Add(void);

//声明一个当前对象
Person person;

//独立的定义文件    Person.c

void PrintMe(void)
{
	printf("%s,%d\n",person.name,person.age);
	return;
}

void Add(void)
{
	char tempName[MAXNAMELEN] = {'0'};
	int tempAge = 1;
	printf("Please input name(1-19 character):");
	gets(tempName);
	printf("Please input age(1-99 Integer):");
	scanf("%d",&tempAge);
	strcpy(person.name,tempName);
	person.age = tempAge;
	return;
}

void initPerson()
{
	person.printMe = PrintMe;
	person.add = Add;
}

//独立的客户端代码文件    main.c
int main()
{
	initPerson();
	
	person.add();
	person.printMe();
	return 0;
}
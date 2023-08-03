#include <iostream>
//#include <string.h>


//独立的声明文件     Person.h
#define MAXNAMELEN 20
class Person{
	char name[MAXNAMELEN];
	int age;
public:
	Person(){
		
	}
	void printMe(){
			printf("%s,%d\n",this->name,this->age);
			return;
	};
	void add(void);
};


//独立的定义文件    Person.c



void Person::add(void)
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


//独立的客户端代码文件    main.c
int main()
{
	Person person;
	person.add();
	person.printMe();
	return 0;
}
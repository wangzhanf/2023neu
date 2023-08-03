#include <iostream>
using namespace std;

//类声明    studnet.h
class Student{
	private:
		int m_age;
	public:
		double m_score = 0.0;
		Student(){
		}
		Student(int age,double score):m_age(age),m_score(score){
		}
		void setAge(int age){//setter
			this->m_age = age;//this  调用者自身
		}
		int getAge(){//getter
			return this->m_age + 1;//虚岁
		}
		virtual void printMe();
};
//演示继承关系
class Doctor:public Student{
	private:
		float m_article = 3.2F;
	public:
		virtual void printMe();//可能会产生覆写
};


//类定义   student.cpp
void Student::printMe()
{
	cout << "age:" << this->getAge() << ",score:" << this->m_score << endl;
}

void Doctor::printMe()
{
	cout << "age:" << this->getAge() << ",score:" << this->m_score << ",article:" << this->m_article << endl;
}

//客户端代码   application.cpp

int main(int argc,char* argv[])
{
//	Student student(18,59.5);//19,59.5
//	student.printMe();
//	//student.m_age = 29;//报错， m_age默认是private
//	cout << "Student type size:" << sizeof(Student) << endl;//存在内存对齐占用填充空间的问题
//	cout << *((int*)(&(student.m_score))-2) << endl;//绕过内存的访问
//	//student.setAge(29);
//	student.m_score = 99.9;
//	student.printMe();//30,99.9
	
	
	//Doctor d;
	//d.printMe();
	cout << sizeof(Student) << endl;
	
	//Doctor* d = new Doctor();
	Student* d = new Doctor();//使用具体（派生），声明泛化（基类）
	d->printMe();
	
	return 0;
}

#include <iostream>
using namespace std;

/*

//auto关键字
int TestAuto()
{
	return 10;
}
int main()
{
	int a = 10;
	auto b = a; // 通过a的类型自动推导出c的类型是int
	auto c = 'a';
	auto d = TestAuto();

	cout << typeid(b).name() << endl;
	cout << typeid(c).name() << endl;
	cout << typeid(d).name() << endl;

	//auto e; //使用auto定义变量时必须对其进行初始化
	return 0;
}

void TestAuto()
{
	auto a = 1, b = 2;
	//auto c = 3, d = 4.0; // 该行代码会编译失败，因为c和d的初始化表达式类型不同
}
int main()
{
	int x = 10;
	auto a = &x;
	auto* b = &x;
	auto& c = x;

	cout << typeid(a).name() << endl;
	cout << typeid(b).name() << endl;
	cout << typeid(c).name() << endl;
	*a = 20;
	*b = 30;
	c = 40;
	return 0;
}
//在同一行定义多个变量时，这些变量必须是相同的类型。否则编译器将会报错
//因为编译器实际只对第一个类型进行推导，然后用推导出来的类型定义其它变量

//auto不能作为函数的参试
//void TestAuto(auto a)
{}
//auto不能直接用来声明数组
void TestAuto()
{
	int a[] = { 1, 2, 3 };
	//auto b[] = { 4，5，6 };
}

//基于范围的for循环
void TestFor1()
{
	int array[] = { 1, 2, 3, 4, 5 };
	for (int i = 0; i < sizeof(array) / sizeof(array[0]); ++i)
		array[i] *= 2;
	for (int* p = array; p < array + sizeof(array) / sizeof(array[0]); ++p)
		cout << *p << endl;
}
void TestFor()
{
	int array[] = { 1, 2, 3, 4, 5 };
	for (auto& e : array)
		e *= 2;
	for (auto e : array)
		cout << e << " ";
	return ;
}
int main()
{
	TestFor();

	return 0;
}

//nullptr指针空值
void f(int)
{
	cout << "f(int)" << endl;
}
void f(int*)
{
	cout << "f(int*)" << endl;
}
int main()
{
	f(0);
	f(NULL); // 预处理以后变成f(0)
	f((int*)NULL);

	int* p1 = NULL; // C
	int* p2 = nullptr; // C++11推荐用

	// 结论：C++11的环境中，统一使用nullptr代表空指针
	return 0;
}

struct Student
{
	void SetStudentInfo(const char* name, const char* gender, int age)
	{
		strcpy(_name, name);
		strcpy(_gender, gender);
		_age = age;
	}
	void PrintStudentInfo()
	{
		cout << _name << " " << _gender << " " << _age << endl;
	}
	char _name[20];
	char _gender[3];
	int _age;
};
int main()
{
	Student s;
	s.SetStudentInfo("Vitobo", "男", 20);
	s.PrintStudentInfo();
	return 0;
}
/
//1.类的定义
class className
{
	// 类体：由成员函数和成员变量组成
};
//1.声明和定义全部放在类体中
class Person
{
public:
	//显示基本信息
	void ShowInfo()
	{
		cout << _name << "-" << _sex << "-" << _age << endl;
	}
public:
	char* _name;
	char* _sex;
	int _age;
};
//2.声明放在.h文件中，类的定义放在.cpp中

class Person
{
public:
	void PrintPersonInfo();
private:
	char _name[20];
	char _gender[3];
	int _age;
};
// 这里需要指定PrintPersonInfo是属于Person这个类域
void Person::PrintPersonInfo()
{
	cout << _name << " "<<_gender << " " << _age << endl;
}

class A
{
public:   //共有
	int a = 10;
	int b = 20;
protected: //保护
	char i = 'm';
private:  //私有
	int c = 3;
};
int main()
{
	A aa;
	aa.a;
	return 0;
}

class A
{
public:
	void PrintA()
	{
		  cout << _a << endl;
	}
private:
	char _a;
};
// 类中既有成员变量，又有成员函数
class A1 {
public:
	void f1(){}
private:
	int _a;
};
// 类中仅有成员函数
class A2 {
public:
	void f2() {}
};
// 类中什么都没有---空类
class A3
{};
int main()
{
	A aa;
	cout << sizeof(aa) << endl;
	cout << sizeof(A) << endl;
	cout << sizeof(A1) << endl;
	cout << sizeof(A2) << endl;
	cout << sizeof(A3) << endl;

	return 0;
}

class Date
{
public:
	void Display()
	{
		cout << _year << "-" << _month<<"-"<<_day<<endl;
	}
	void setDate(int year, int month, int day)
	{
		_year = year;
		_month = month;
		_day = day;
	}
private:
	int _year;
	int _month;
	int _day;
};
int main()
{
	Date d1, d2;
	d1.setDate(2008, 8, 8);
	d2.setDate(2020, 8, 8);
	d1.Display();
	d2.Display();
	return 0;
}

class Date
{
public:
	void PrintA()
	{
		cout << this-> _a << endl;
	}
	void Show()
	{
		cout << "Show()" << endl;
	}
private:
	int _a;
};
int main()
{
	Date* p = NULL;
	p->PrintA();
	p->Show();
}
*/
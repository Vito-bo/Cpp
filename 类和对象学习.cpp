
#include <iostream>
using namespace std;

// 类和对象
// 类：是对对象来进行描述的
// 对象：是现实世界中的实体
#if 0
// 在C++中，struct定义出来的类型就可以看成是一个类了
struct Student
{
	// 结构体中的变量
	char _name[20];
	char _gender[3];
	int _age;

	// 结构体中的函数
	void InitStudent(char name[], char gender[], int age)
	{
		strcpy(_name, name);
		strcpy(_gender, gender);
		_age = age;
	}

	void PrintStudent()
	{
		cout << _name << "-" << _gender << "-" << _age << endl;
	}

	void SetAge(int age)
	{
		_age = age;
	}
};

int main()
{
	// 在C语言中的方式
	struct Student s1;
	s1._age = 18;

	// 在C++中
	Student s2;
	s2.InitStudent("BOBO", "MAN", 22);
	s2.SetAge(20);
	s2.PrintStudent();
	return 0;
}


// 在C++中，定义一个类使用class关键字
// 方式1：将成员函数在类内来进行定义
class Student
{
private:
	char _name[20];
	char _gender[3];
protected:
	int _age;

public:
	// 成员函数
	void InitStudent(char name[], char gender[], int age)
	{
		strcpy(_name, name);
		strcpy(_gender, gender);
		_age = age;
	}

	// 注意：成员函数如果在类内进行定义，成员函数可能会被编译器当成内联函数来对待
	void PrintStudent()
	{
		cout << _name << "-" << _gender << "-" << _age << endl;
	}

	void SetAge(int age)
	{
		_age = age;
	}
};
int main()
{
	// Student是类名，可以将其看成是学生的一个群体
	// s是Student定义出来的对象
	Student s;

	s.InitStudent("bobo", "nan", 20);
	s.PrintStudent();

	return 0;
}


// 方式2：成员函数如果放在类外来进行定义
// 成员函数名之前必须加上::，表明该函数是这个类的成员函数
// 如果没有加，就相当于在全局作用域中定义了一个函数

class Person
{
public:
	void Eat();
	void Sleep();
private:
	char _name[20];
	char _gender[3];
	int _age;
};

void Person::Eat()
{
	cout << "开饭了" << endl;
}
void Person::Sleep()
{
	cout << "晚安" << endl;
}


// 如何计算一个类/对象的大小？
class  Student
{
public:
	// 成员变量
	char _name[20];
	char _gender[3];
	int _age;

public:
	// 成员函数
	void InitStudent(char name[], char gender[], int age)
	{
		strcpy(_name, name);
		strcpy(_gender, gender);
		_age = age;
	}

	// 注意：成员函数如果在类内部类进行定义，成员函数可能会被编译器当成内联函数来对待
	void PrintStudent()
	{
		cout << _name << "-" << _gender << "-" << _age << endl;
	}

	void SetAge(int age)
	{
		_age = age;
	}
};


int main()
{
	Student s1, s2, s3;
	s1.InitStudent("Peter", "男", 18);
	cout << sizeof(s1) << endl;
	return 0;
}


class A
{
public:
	void SetA(int a)
	{
		_a = a;
	}

private:
	int _a;
};


class B
{
public:
	void TestB()
	{}
};


class C
{};

// 空的结构体是多少呢？
// 分析：在C++中，用struct定义出来的结构体就是类
// 空类:实现每个实例在内存中都有一个独一无二的地址，编译器往往会给一个空类隐含的加一个字节，
//这样空类在实例化后在内存得到了独一无二的地址，所以空类所占的内存大小是1个字节。
struct D
{};

struct AA
{
	int a;
	char b;
	double c;
	char d;
};


int main()
{
	// 结论：求一个类的大小--->只需将类中"成员变量"加起来，注意内存对齐
	cout << sizeof(A) << endl;   // 4
	cout << sizeof(B) << endl;   // 1
	cout << sizeof(C) << endl;   // 1

	cout << sizeof(D) << endl;

	cout << sizeof(AA) << endl;
	return 0;
}
#endif

class Student
{
public:
	char _name[20];
	char _gender[20];
	int _age;

public:
	// 成员函数
	// 看起来该函数有三个参数，实际上有4个
	// 另外一个参数是：隐含的this指针
	void InitStudent(char name[], char gender[], int age)
	{
		// 不能给this指针来进行赋值。类类型* const
		//this = nullptr;

		cout << this << endl;

		// 有了this指针，成员函数就知道现在是在操作那个对象
		// 注意：对成员变量的操作都是通过this指针来进行的。
		strcpy(this->_name, name);
		strcpy(this->_gender, gender);
		this->_age = age;
	}

	//
};
int main()
{

	Student s1, s2, s3;
	s1.InitStudent("Peter", "男", 18);
	s2.InitStudent("David", "男", 19);
	s3.InitStudent("Lily", "女", 18);

	cout << sizeof(s1) << endl;

	return 0;
}


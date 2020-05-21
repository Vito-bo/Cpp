
#include <iostream>
#include <string>
using namespace std;

//class Person
//{
//public:
//	void Print()
//	{
//		cout << "name:" << _name << endl;
//		cout << "age:" << _age << endl;
//	}
//protected:
//	string _name = "peter"; // 姓名
//	int	   _age = 18;		// 年龄
//};
//
//// 继承后父类的Person的成员（成员函数+成员变量）都会变成子类的一部分。这里体现出了Student和Teacher复用了Person的成员。下面我们使用监视窗口查看Student和Teacher对象，可以看到变量的复用。调用Print可以看到成员函数的复用。
//class Student : public Person
//{
//protected:
//	int _stuid; // 学号
//};
//
//class Teacher : public Person
//{
//protected:
//	int _jobid; // 工号
//};
//
//int main()
//{
//	Student s;
//	Teacher t;
//	s.Print();
//	t.Print();
//
//	return 0;
//}

//class Person
//{
//public:
//	void Print()
//	{
//		cout << "name:" << _name << endl;
//		cout << "age:" << _age << endl;
//	}
//protected:
//	string _name = "peter"; // 姓名
//
//private:
//	int	   _age = 18;		// 年龄
//};
//
//struct Student : Person
//{
//public:
//	void f()
//	{
//		_name = "xxx";
//		//_age = 10; 父类的私有继承下来以后不可见
//	}
//protected:
//	int _stuid; // 学号
//};
//
//int main()
//{
//	Student s;
//	s.Print();
//	//s._name;
//
//	return 0;
//}


//class Person
//{
//protected:
//	string _name; // 姓名
//	string _sex;  // 性别
//	int	_age;	 // 年龄
//};
//
//class Student : public Person
//{
//public:
//	int _No; // 学号
//};
//
//void main()
//{
//	Student sobj;
//	// 1.子类对象可以赋值给父类对象/指针/引用
//	Person pobj = sobj;
//	Person* pp = &sobj;
//	Person& rp = sobj;
//
//	pp = &sobj;
//	Student* ps1 = (Student*)pp; // 这种情况转换时可以的。
//	ps1->_No = 10;
//
//	pp = &pobj;
//	Student* ps2 = (Student*)pp; // 这种情况转换时虽然可以，但是会存在越界访问的问题
//	ps2->_No = 10;
//}

//class Person
//{
//protected:
//	string _name = "小李子"; // 姓名
//	int _num = 111; 	   // 身份证号
//};
//
//class Student : public Person
//{
//public:
//	void Print()
//	{
//		cout << " 姓名:" << _name << endl;
//		cout << " 身份证号:" << Person::_num << endl;
//		cout << " 学号:" << _num << endl;
//	}
//protected:
//	int _num = 999; // 学号  子类成员隐藏(重定义)父类的成员
//};
//
//int main()
//{
//	Student s;
//	s.Print();
//
//	return 0;
//}

// 函数重载：同一作用
// 
// 父子类中，同名成员变量构成隐藏，同名函数构成隐藏(参数返回值都可以不同)
//class A
//{
//public:
//	void fun()
//	{
//		cout << "func()" << endl;
//	}
//};
//class B : public A
//{
//public:
//	void fun(int i)
//	{
//		cout << "func(int i)->" << i << endl;
//	}
//};
//
//void main()
//{
//	B b;
//	b.fun(10);
//	b.A::fun();
//};

//class Person
//{
//public:
//	//Person(const char* name = "peter")
//	Person(const char* name)
//		: _name(name)
//	{
//		cout << "Person()" << endl;
//	}
//
//	Person(const Person& p)
//		: _name(p._name)
//	{
//		cout << "Person(const Person& p)" << endl;
//	}
//
//	Person& operator=(const Person& p)
//	{
//		cout << "Person operator=(const Person& p)" << endl;
//		if (this != &p)
//			_name = p._name;
//
//		return *this;
//	}
//
//	~Person()
//	{
//		cout << "~Person()" << endl;
//	}
//protected:
//	string _name; // 姓名
//};
//
//// 派生类几个默认成员函数：构造、析构、拷贝构造、赋值
//class Student : public Person
//{
//public:
//	Student()
//		:Person("xxx")
//	{
//		cout << "Student()" << endl;
//	}
//
//	// s2(s1)
//	Student(const Student& s)
//		:Person(s)
//		, _id(s._id)
//	{
//		cout << "Student(const Student& s)" << endl;
//	}
//
//	// s1 = s3
//	Student& operator=(const Student& s) // 跟父类的operator=构成隐藏
//	{
//		if (this != &s)
//		{
//			Person::operator=(s);
//			_id = s._id;
//		}
//
//		cout << "Student& operator=(const Student& s)" << endl;
//
//		return *this;
//	}
//
//
//	~Student()  // 也跟父类的~Person()构成隐藏，编译器会将析构函数的名称处理成destrucator()
//	{
//		//Person::~Person();  不要显示调用，因为不能保证先调子类析构再调父类析构的顺序
//		// 子类析构函数调用完成够，自动调用父类的
//		cout << "~Student()" << endl;
//	}
//
//protected:
//	int _id;
//};

// C++98
//class A
//{
//private:
//	A()
//	{}
//};
//
//class B : public A
//{
//public:
//	
//};

// C++11
//class A final
//{
//};
//
//class B : public A
//{
//public:
//
//};

class Person
{
public:
	Person() { ++_count; }
	int _p; // 姓名
	static int _count; // 统计人的个数。
};

int Person::_count = 0;
class Student : public Person
{
public:
	int _stuNum; // 学号
	static int _count; // 统计人的个数。
};

int Student::_count = 0;


int main()
{
	Person p;
	p._p = 2;
	p._count = 1;


	Student s;
	s._p = 3;
	s._count = 4;

	/*Student s1;
	Student s2(s1);
	Student s3;
	s1 = s3;*/

	//B b;

	return 0;
}


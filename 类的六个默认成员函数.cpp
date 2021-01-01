#include <iostream>
using namespace std;

#if 0
class A
{
public:
	void Test()
	{
		cout << "A::Test()" << endl;
	}
	void TestFunc()
	{
		Test();
		cout << this << endl;
	}
	int _t;
};

int main()
{
	A a1, a2, a3;
	a1.TestFunc();
	a1.TestFunc();
	a1.TestFunc();

	//A::TestFunc();
	// 成员函数必须要通过对象来进行调用，在该成员函数调用之前， 
	//编译器需要将当前对象的地址通过ecx寄存器传递给成员函数

	A* pa = &a1;
	pa->TestFunc();
	// 注意：pa是A*类型的指针，就是说pa将来可以指向A类型的对象
	//       如果pa指针没有合法指向时，一般都是将该指针置为Nullptr
	pa = nullptr;
	pa->TestFunc();

	return 0;
}
#endif

#if 0
class Date
{
public:
	Date()
	{
		_year = 1900;
		_month = 1;
		_day = 1;
	}
	void SetDate(int year, int month, int day)
	{
		_year = year;
		_month = month;
		_day = day;
	}
	void PrintDate()
	{
		cout << _year << "-" << _month << "-" << _day << endl;
	}
private:
	int _year;
	int _month;
	int _day;
};
int main()
{
	Date d;
	d.PrintDate();
	// 创建对象时，编译器自动调用构造函数，给对象中设置一些初识值


	Date d1;
	d1.SetDate(2021, 1, 1);
	d1.PrintDate();

	int a = 5;
	int b(a);
	cout << b << endl;
}
// 如果类中没有显示定义构造函数，则C++编译器会自动生成一个无参的默认构造函数，
// 一旦用户显示定义编译器将不再生成

class Time
{
public:
	Time(int hour = 0, int minute = 0, int second = 0)
	{
		_hour = hour;
		_minute = minute;
		_second = second;
	}

	void PrintTime()
	{
		cout << _hour << ":" << _minute << ":" << _second << endl;
	}
private:
	int _hour;
	int _minute;
	int _second;
};


class Date
{
public:
	// 用户显式定义了带有参数的构造函数
	Date(int year, int month, int day)
	{
		_year = year;
		_month = month;
		_day = day;
	}

	void SetDate(int year, int month, int day)
	{
		_year = year;
		_month = month;
		_day = day;
	}

	void PrintDate()
	{
		cout << _year << "-" << _month << "-" << _day << endl;
	}

private:
	int _year;
	int _month;
	int _day;

	Time _t;
};


int main()
{
	// Date类中已经显式定义了带有三个参数的构造函数
	// 验证：编译器还会不会生成无参的构造函数呢？

	// 如果代码可以通过编译则编译器生成无参构造函数了
	// 如果代码编译失败则编译没有生成


	// 编译报错：error C2512: “Date”: 没有合适的默认构造函数可用
	// 当类中显式定义了构造函数时，编译器不会再生成无参的默认构造函数了

	Date d;  // 创建d对象期间，编译器需要调用无参的构造函数
	return 0;
}


class Date
{
public:
	// 无参构造函数
	Date()
	{
		_year = 1900;
		_month = 1;
		_day = 1;
	}

	// 全缺省构造函数
	Date(int year = 1900, int month = 1, int day = 1)
	{
		_year = year;
		_month = month;
		_day = day;
	}

	void SetDate(int year, int month, int day)
	{
		_year = year;
		_month = month;
		_day = day;
	}

	void PrintDate()
	{
		cout << _year << "-" << _month << "-" << _day << endl;
	}

private:
	int _year;
	int _month;
	int _day;
};
int main()
{
	Date d1(202, 1, 1);

	// 发现：即可以调用无参构造函数来创建d2，
	//     也可以调用全缺省的构造函数来创建d2
	// 产生了二义性，编译器就报错了
	//Date d2;
	return 0;
}
#endif

#if 0
// 析构函数
typedef int DataType;

class SeqList
{
public:
	SeqList(int capacity = 10)
	{
		_arr = (DataType*)malloc(sizeof(DataType)*capacity);
		_capacity = capacity;
		_size = 0;
	}

	//析构函数
	~SeqList()
	{
		if (_arr)
		{
			free(_arr);
			_arr = nullptr;
			_capacity = 0;
			_size = 0;
		}
	}

	void PushBack(DataType x)
	{

	}
private:
	DataType* _arr;
	size_t _capacity;
	size_t _size;
};

class String
{
public:
	String(const char* str = "")
	{
		_str = (char*)malloc(strlen(str) + 1);
		strcpy(_str, str);
	}
	~String()
	{
		if (_str)
		{
			free(_str);
			_str = nullptr;
		}
	}
private:
	char* _str;
};
class Person
{
private:
	String _name;
	int _age;
};
void Test()
{
	Person p;
}
int main()
{
	Test();

	String s("nihao shjie");
}
#endif 

#if 0
// 拷贝构造函数
class Date
{
public:
	// 成员函数在类内实现，编译器有可能会将其当成内联函数来处理
	Date(int year = 1000, int month = 1, int day = 1)
	{
		_year = year;
		_month = month;
		_day = day;
	}
	
	// 拷贝构造函数
	Date(const Date& d)
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;

		cout << "Date(Date&)" << endl;
	}

	void Print()
	{
		cout << _year << "-" << _month << "-" << _day << endl;
	}
private:
	int _year;
	int _month;
	int _day;
};
int main()
{
	Date d1;
	Date d2(2021, 1, 1);
	Date d3(d2);

	return 0;
}



// 注意：如果类中涉及到资源管理时，该类必须要显示提供析构函数
//		在析构函数中将对象的资源释放掉。否则会发送资源泄漏

// 编译器生成的默认拷贝构造函数是按照浅拷贝方式实现的。
// 浅拷贝：将一个对象中的内容原封不动的拷贝到另一个对象中
// 后果：多个对象共享同一份资源，最终在对象销毁时该份资源被释放多次而导致代码崩溃

// 注意：一个类中如果涉及到资源管理时，拷贝构造函数是必须要实现的

class String{
public:
	String(const char* str = "")
	{
		_str = (char*)malloc(strlen(str) + 1);
		strcpy(_str, str);
	}


	// String类没有实现自己的拷贝构造函数，则编译器会生成一份
	~String()
	{
		if (_str)
		{
			free(_str);
			_str = nullptr;
		}
	}
private:
	char* _str;
};


void TestString()
{
	String s1("hello world");
	String s2(s1);
}


int main()
{
	TestString();
	return 0;
}
#endif

#if 0
// 赋值运算符重载
class Date
{
public:
	// 成员函数在类内实现，编译器可能会将其当成内联函数来处理
	Date(int year = 1900, int month = 1, int day = 1)
	{
		_year = year;
		_month = month;
		_day = day;
	}

	// 拷贝构造函数
	Date(const Date& d)
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;

		cout << "Date(Date&):" << this << endl;
	}

	void PrintDate()
	{
		cout << _year << "-" << _month << "-" << _day << endl;
	}

private:
	int _year;
	int _month;
	int _day;
};

int main()
{
	Date d0;
	Date d1(2020, 10, 12);
	Date d2(d1);
	Date d3(2020, 10, 13);

	// 调用赋值运算符重载函数
	// 如果一个类没有显式实现赋值运算符重载函数，则编译器会生成一份默认的
	// 完成对象之间的赋值操作
	d1 = d3;

	int a = 10;
	int b = 20;
	a = b;

	return 0;
}


// 注意：如果类中涉及到资源管理时，赋值运算符函数必须要显式实现出来
//	编译器生成的赋值运算符重载是按照浅拷贝的方式实现的
// 如果类中涉及到资源管理时，会导致以下后果：1.浅拷贝（造成一份资源释放多次引起代码崩溃）2.s1原来的空间丢失了-内存泄漏

class Date
{
public:
	Date(int year = 1900, int month = 1, int day = 1)
	{
		_year = year;
		_month = month;
		_day = day;
	}

	// 拷贝构造函数
	Date(const Date& d)
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;

		cout << "Date(Date&):" << this << endl;
	}
	
	void PrintDate()
	{
		cout << _year << "-" << _month << "-" << _day << endl;
	}

	// 对于自定义类型，编译器不知道如何进行响应运算符的操作
	// 因此需要对该运算符进行重载，相当于告诉编译器针对该种类型的对象如何去进行运算符操作
	bool operator<(const Date& d)
	{
		if ((_year < d._year) ||
			(_year == d._year && _month < d._month) ||
			(_year == d._year && _month == d._month && _day < d._day))
		{
			return true;
		}
	}
	bool operator==(const Date& d)
	{
		return _year == d._year && _month == d._month && _day == d._day;
	}
	bool operator!=(const Date& d)
	{
		return !(*this == d);
	}
	
	Date& operator+=(int days)
	{
		_day += days;
		return *this;
	}

	Date operator+(int days)
	{
		Date tmp(*this);
		tmp._day += days;
		return tmp;
	}

	Date& operator=(const Date& d)
	{
		// this是=运算符的左操作数，d是=运算符的右操作数
		if (this != &d)
		{
			_year = d._year;
			_month = d._month;
			_day = d._day;
		}
		return *this;
	}

	// 前置++
	Date& operator++()
	{
		_day++;
		return *this;
	}

	// 后置++
	Date operator++(int)
	{
		Date tmp(*this);
		_day++;
		return tmp;
	}

	// 前置--
	Date& operator--()
	{
		_day--;
		return *this;
	}

	// 后置--
	// 先使用，后-1
	Date operator--(int)
	{
		Date tmp(*this);
		_day--;
		return tmp;
	}

	Date operator-(int days)
	{
		Date temp(*this);
		temp._day -= days;
		return temp;
	}

	~Date()
	{}

private:
	int _year;
	int _month;
	int _day;

};
int main()
{
	Date d1(2020, 10, 14);
	Date d2(2020, 10, 15);
	Date d3(2020, 10, 16);

	d1 = d2;
	d1.operator=(d2);

	d1 = d2 = d3; //  ===》d1.operator=(d2.operator=(d3));

	d2 = d1++;  // 后置++
	d2 = ++d1;  // 前置++

	//d1--;
	d1 = d1;
	Date& d4 = d1;



	d4 = d1;
	if (d1 == d2)
	{
		;
	}

	d2 = d1 + 10;

	int a = 10;
	int b = 20;
	int c = 0;
	c = a + b;

	d2 = d1 - 1;
	d4--;


	return 0;
}
#endif


class Date
{
public:
	Date(int year = 1900, int month = 1, int day = 1)
	{
		_year = year;
		_month = month;
		_day = day;
	}

	Date(const Date& d)
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}

	// 普通类型的成员函数
	// this指针的类型   Date* const this;
	void TestThis()
	{
		//this = nullptr;
		_day++;
	}

	// const类型的成员函数
	// const修饰的成员函数是不能被修改成员变量的值的
	// this指针的类型：const Date* const this
	//

	// 注意：一般如果成员函数中不需要修改成员变量时，最好将该函数设置成const类型的成员函数
	//	如果在成员函数中需要修改当前对象中的成员函数时，该函数一定不能设置为const类型的成员函数，否则编译失败
	bool operator==(const Date& d)const
	{
		// ++_day;  编译失败
		return _year == d._year &&
			_month == d._month &&
			_day == d._day;
	}

	void PrintDate()const
	{
		// _day++;
		cout << _year << "-" << _month << "-" << _day << endl;
	}

	Date& operator=(const Date& d)
	{
		if (this != &d)
		{
			_year = d._year;
			_month = d._month;
			_day = d._day;
		}

		return *this;
	}

	bool operator<(const Date& d)const
	{
		return true;
	}

	// Date* const
	Date* operator&()
	{
		++_day;
		cout << this << endl;
		return this;
	}

	// const Date* const
	const Date* operator&()const
	{
		//++_day;
		cout << this << endl;
		return this;
	}


	void Test1()
	{}

	void Test2()const
	{}

	void TestFuncWithoutConst()
	{
		// TestFuncWithoutConst：this指向的对象-->是可读可写的
		Test2(); // Test2: this指向的对象是只读的
	}


	void TestFuncWithConst()const
	{
		// const 修饰成员函数，表明该成员函数中的this指针指向的对象是不能修改的
		// 但是普通成员函数中this指向对象中的内容是可以修改的
		// 如果const类型成员函数中可以调用普通类型的成员函数,假设内部调用的普通成员函数中修改了this指向的对象
		// 那么外部const类型成员函数不安全
		//Test1(/*this*/);
	}
private:
	int _year;
	int _month;
	int _day;
};


int main()
{
	int a = 100;
	int b = 200;
	int c = 300;
	int d = 400;
	int* p1 = &a;
	p1 = &b;

	const int* p2 = &b;
	p2 = &a;
	*p2 = 2;

	int const* p3 = &c;
	p3 = &a;
	*p3 = 3;

	const int* const p4 = &d;
	p4 = &a;
	*p4 = 4;

	return 0;
}
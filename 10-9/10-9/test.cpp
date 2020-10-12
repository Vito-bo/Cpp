
#include <iostream>
using namespace std;

//C++复习-构造函数和析构函数

#if 0
class A
{
public:
	/*
	void TestFunc(A* const this)
	{
	this->_t = 10;
	cout << this << endl;
	}

	*/

	void Test()
	{
		cout << "A::Test()" << endl;
	}

	void TestFunc()
	{
		//this->_t = 10;

		Test();
		cout << this << endl;
	}

	int _t;
};

int main()
{
	A a1, a2, a3;

	a1.TestFunc();    // call A::TestFunc(&a1)
	a2.TestFunc();    // call A::TestFunc(&a2)
	a3.TestFunc();    // call A::TestFunc(&a3)

	//A::TestFunc();

	// 成员函数必须要通过对象来进行调用，在该成员函数调用之前，
	// 编译器需要将当前对象的地址通过ecx寄存器传递给成员函数
	// 

	A* pa = &a1;
	pa->TestFunc();   // call A::TestFunc(pa);

	pa = &a2;
	pa->TestFunc();   // call A::TestFunc(pa);


	// 注意：pa是A*类型的指针，也就是说pa将来可以指向A类型的对象
	//       如果pa指针没有合法指向时，一般都是将该指针置为nullptr
	pa = nullptr;
	pa->TestFunc();
	return 0;
}
#endif


#if 0

class Date
{
public:
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
	Date d1;
	//d._year = 2020;

	d1.SetDate(2020, 10, 11);
	d1.PrintDate();

	Date d2;
	d2.SetDate(2020, 10, 12);
	d2.PrintDate();

	Date d3;
	d3.SetDate(2020, 10, 12);
	d3.PrintDate();

	Date d4(2020, 10, 13);
	d4.PrintDate();

	int a;
	a = 10;
	cout << a << endl;

	int b = 10;
	cout << b << endl;

	int c(20);
	cout << c << endl;
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

	Date(int year, int month, int day)
	{
		_year = year;
		_month = month;
		_day = day;

		cout << "Date(int,int,int):" << this << endl;
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


void TestDate()
{
	Date d1(2020, 10, 11);
	d1.PrintDate();


	// 创建对象时，编译器自动调用构造函数，给对象中设置一些初始值
	Date d2;
	d2.PrintDate();

	Date d3();
}

int main()
{
	TestDate();
	return 0;
}
#endif


// 如果类中没有显式定义构造函数，则C++编译器会自动生成一个无参的默认构造函数，
// 一旦用户显式定义编译器将不再生成


#if 0
// 用户没有显式定义任何构造函数---显式：用户有没有自己写
class Date
{
public:
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
	// 从概念：
	// 目前日期类中没有显式定义构造函数，但是该类仍旧可以创建对象，当创建对象时，编译器需要自动调用构造函数
	// 该构造函数哪里来的，就是编译器生成的默认无参构造函数
	Date d;
	return 0;
}
#endif


#if 0
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
#endif


#if 0
// 无参的构造函数和全缺省的构造函数都称为默认构造函数，并且默认构造函数只能有一个
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
	Date d1(2020, 10, 11);

	// 发现：即可以调用无参构造函数来创建d2，
	//       也可以调用全缺省的构造函数来创建d2
	// 产生了二义性，编译器就报错了
	Date d2;
	return 0;
}
#endif


/*
1. 当用户没有显式定义构造函数时，编译器会生成一个无参的默认构造函数
*/

#if 0
class Time
{
public:
	Time(int hour = 0, int minute = 0, int second = 0)
	{
		_hour = hour;
		_minute = minute;
		_second = second;
		cout << "Time(int,int,int)" << endl;
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
	//内置类型
	int _year;
	int _month;
	int _day;
	//自定义类型
	Time _t;
};



int main()
{
	Date d;
	return 0;
}
#endif


#if 0
//析构函数分析
//析构函数不能重载
//无参数无返回值
//一个类有且只有一个析构函数。
//对象声明周期结束时，C++编译系统自动调用析构函数。
typedef int DataType;
class SeqList
{
public:
	SeqList(int capacity = 10)
	{
		_array = (DataType*)malloc(sizeof(DataType)*capacity);

		_capacity = capacity;
		_size = 0;
	}

	// 析构函数
	~SeqList()
	{
		if (_array)
		{
			free(_array);
			_array = nullptr;
			_capacity = 0;
			_size = 0;
		}
	}

	void PushBack(DataType data)
	{
		// ...
	}

	void PopBack()
	{
		if (!Empty())
		{
			_size--;
		}
	}

	size_t Size()
	{
		return _size;
	}

	size_t Capacity()
	{
		return _capacity;
	}

	bool Empty()
	{
		return _size == 0;
	}

	// ...
private:
	DataType* _array;
	size_t _capacity;
	size_t _size;
};


void TestSeqList()
{
	SeqList s;
	s.PushBack(10);
	s.PushBack(10);
	s.PushBack(10);

	s.PopBack();
}

int main()
{
	TestSeqList();
	return 0;
}
#endif


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

void TestPerson()
{
	Person p;
}

int main()
{
	TestPerson();

	String s("hello world");
	return 0;
}
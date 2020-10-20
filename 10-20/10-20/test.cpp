
#include <iostream>
using namespace std;

//类和对象6-

//赋值运算符重载和const成员函数

#if 0
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

	bool operator==(const Date& d)
	{
		return _year == d._year &&
			_month == d._month &&
			_day == d._day;
	}

	Date& operator+=(int days)
	{
		_day += days;
		return *this;
	}

	Date operator+(/*Date* const this,*/int days)
	{
		Date temp(*this);
		temp._day += days;
		return temp;
	}

	~Date()
	{}

	// =
	Date& operator=(const Date& d)
	{
		// this是=运算符的左操作数，d是=运算符的右操作数
		//cout << this << "=" << &d << endl;

		if (this != &d)
		{
			_year = d._year;
			_month = d._month;
			_day = d._day;
		}

		return *this;
		//return d;
	}

	// 前置++
	Date& operator++()
	{
		_day++;
		return *this;
	}

	// 后置++
	// 先使用 后加+1
	Date operator++(int)
	{
		Date temp(*this);
		_day++;
		return temp;
	}

	Date& operator--()
	{
		_day--;
		return *this;
	}

	// 后置++
	// 先使用 后加+1
	Date operator--(int)
	{
		Date temp(*this);
		_day--;
		return temp;
	}

	int _year;
	int _month;
	int _day;
};


Date operator-(const Date& d, int days)
{
	Date temp(d);
	temp._day -= days;
	return temp;
}



/*
int operator+(int left, int right)
{
return left + right;
}
*/


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

	a = b;
	a = c;

	a = b = c;

	a++;
	a--;

	return 0;
}
#endif


#if 0
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

	Date* operator&()
	{
		cout << this << endl;
		return this;
	}

private:
	int _year;
	int _month;
	int _day;
};

int main()
{
	Date d1(2020, 10, 14);
	//cout << &d1 << endl;
	&d1;

	const Date d2(2020, 10, 15);
	&d2;
	return 0;
}
#endif

#if 0
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
	// const修饰的成员函数中是不能修改成员变量的值
	// this指针的类型：const Date* const this

	// 注意：一般如果在成员函数中不需要修改成员变量时，最好将该函数设置成const类型的成员函数
	//      如果在成员函数中需要修改当前对象中的成员变量时，该函数一定不能设置为const类型的成员函数
	//      否则代码编译失败
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
	Date d1(2020, 10, 14);  // 可读可写
	Date d2(2020, 10, 14);
	Date d3(2020, 10, 15);
	const Date d4(2020, 10, 14); // 只读

	&d1;
	&d4;

	// 普通类型的对象可以调用const类型的成员函数
	d1.PrintDate();

	if (d1 == d2)
	{
		cout << "相同" << endl;
	}
	else
	{
		cout << "不相等" << endl;
	}

	if (d1 == d3)
	{
		cout << "相同" << endl;
	}
	else
	{
		cout << "不相等" << endl;
	}
	return 0;
}
#endif


// 构造函数作用：初始化对象--初始化对象空间中包含的成员变量的

// 初始化和赋值的区别？

#if 0
class Date
{
public:
	Date(int year = 1900, int month = 1, int day = 1)
	{
		// 对当前对象中的成员变量在进行赋值
		_year = year;
		_month = month;
		_day = day;
		_day = day;
		// a = 10;
	}

private:
	int _year;
	int _month;
	int _day;

	const int a;
};

int main()
{
	const int a = 10;
	Date d1(2020, 10, 14);

	return 0;
}
#endif

#if 0
class Date
{
public:
	Date(int year = 1900, int month = 1, int day = 1)
		: _year(year)
		, _month(month)
		, _day(day)
		, _day(day)
	{
		// 对当前对象中的成员变量在进行赋值
		//_year = year;
		//_month = month;
		//_day = day;
		//_day = day;
	}

private:
	int _year;
	int _month;
	int _day;
};


int main()
{
	Date d1(2020, 10, 14);

	return 0;
}
#endif


class Date
{
public:
	//全缺省的构造函数
	Date(int year = 1900, int month = 1, int day = 1)
		: _year(year)
		, _month(month)
		, _day(day)
	{
		cout << "Date(int,int,int):" << this << endl;
	}
	//拷贝构造函数
	Date(const Date& d)
		: _year(d._year)
		, _month(d._month)
		, _day(d._day)
	{
		cout << "Date(const Date&):" << this << endl;
	}
	//赋值运算符重载
	Date& operator=(const Date& d)
	{
		cout << this << "=" << &d << endl;
		if (this != &d)
		{
			_year = d._year;
			_month = d._month;
			_day = d._day;
		}

		return *this;
	}
	//析构
	~Date()
	{
		cout << "~Date():" << this << endl;
	}

private:
	int _year;
	int _month;
	int _day;
};


Date TestDate1(Date d)
{
	Date temp(d);
	temp = d;
	return temp;
}

//引用传递，引用返回
Date& TestDate2(Date& d)
{
	Date temp(d);
	temp = d;
	return d;
}

//值传递，值返回
Date TestDate3(Date d)
{
	return d;
}

void TestDate()
{
	Date d1(2020, 10, 14);
	//Date d2(d1);

	//d2 = TestDate1(d1); // 值传递
	//d2 = TestDate2(d1); // 引用传递

	TestDate3(TestDate3(d1));
}

int main()
{
	TestDate();
	return 0;
}

#endif
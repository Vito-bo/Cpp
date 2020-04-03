#include <iostream>
using namespace std;

//class Date
//{
//public:
//	Date(int year = 0, int month = 1, int day = 1)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//
//	// 可以不写析构函数的，因为编译器自动生成的就可以用
//	// 可以不写拷贝构造，因为编译器自动生成的就可以用
//
//	Date(const Date& d)
//	{
//		_year = d._year;
//		_month = d._month;
//		_day = d._day;
//
//		cout << "Date(const Date& d)" << endl;
//	}
//
//	// d1 = d3;
//	// d1 = d1;
//	// d1.operator=(&d1, d3)
//	// 参数是自定义类型：都建议传引用，提高小效率
//	// 参数加了引用：建议加const进行保护(除非本来就要传引用改变这个参数，如swap)
//	Date& operator=(const Date& d)
//	{
//		if (this != &d)
//		{
//			_year = d._year;
//			_month = d._month;
//			// d._day = _day;
//			_day = d._day;
//		}
//
//		return *this;
//	}
//
//	void Print()
//	{
//		cout << _year << "-" << _month << "-" << _day << endl;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
////int main()
////{
////	Date d1(2020, 3, 19);
////	Date d2(d1);
////	d1.Print();
////	d2.Print();
////	Date d3(2020, 3, 20);
////	d2 = d1 = d3;
////	d1.Print();
////	d3.Print();
////
////	d1 = d1;
////
////	int i = 0;
////	int j = 1;
////	i = j;
////	int k = 2;
////	i = j = k; // 连续赋值
////
////	return 0;
////}
//
//int main()
//{
//	Date d1(2020, 3, 19);
//	Date d2(2020,3,20);
//	d1 = d2;
//	Date d3 = d2; // 等价于Date d3(d2) 记住：这里调用的不是operator=，调用的是拷贝构造
//
//	d1.Print();
//	d3.Print();
//	
//
//	return 0;
//}


class Date
{
public:
	int GetMonthDay(int year, int month)
	{
		int monthDays[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
		if (month == 2 &&
			((year % 4 == 0 && year % 100 != 0) || year % 400 == 0))
		{
			return 29;
		}
		else
		{
			return monthDays[month];
		}
	}

	Date(int year = 0, int month = 1, int day = 1)
	{
		if (year >= 0
			&& month > 0 && month < 13
			&& day > 0 && day <= GetMonthDay(year, month))
		{
			_year = year;
			_month = month;
			_day = day;
		}
		else
		{
			cout << "非法日期" << endl;
		}
	}

	// d1 < d2
	// 实际中这里不加inline也可以，因为直接在类中实现的函数，默认就是inline
	inline bool operator<(const Date& d)
	{
		if ((_year < d._year)
			|| (_year == d._year && _month < d._month)
			|| (_year == d._year && _month == d._month && _day < d._day))
		{
			return true;
		}

		return false;
	}

	inline bool operator==(const Date& d)
	{
		return _year == d._year && _month == d._month && _day == d._day;
	}

	// 如果Date加了时分秒成员，如果增强程序的复用性，代码的改动最小。
	// 请往下看
	// d1 <= d2
	inline bool operator<=(const Date& d)
	{
		return *this < d || *this == d;
	}

	// d1 > d2
	inline bool operator>(const Date& d)
	{
		return !(*this <= d);
	}

	inline bool operator>=(const Date& d)
	{
		return !(*this < d);
	}

	inline bool operator!=(const Date& d)
	{
		return !(*this == d);
	}

	// ++d1;
	// d1.operator++(&d1)
	Date& operator++()
	{
		*this += 1;
		return *this;
	}

	// d1++  // 后置++多调用两次拷贝构造，建议使用前置++
	// d1.operator++(&d1, 0)
	Date operator++(int) // 为了区分于前置++，这里加一个参数
	{
		// 返回++之前的值
		Date tmp(*this);
		*this += 1;

		return tmp;
	}

	// d1 + 100
	// d1.operator+(&d1, 100);
	/*Date operator+(int day)
	{
	Date tmp(*this);
	tmp._day += day;
	while (tmp._day > GetMonthDay(tmp._year, tmp._month))
	{
	tmp._day -= GetMonthDay(tmp._year, tmp._month);
	++tmp._month;
	if (tmp._month == 13)
	{
	tmp._year++;
	tmp._month = 1;
	}
	}

	return tmp;
	}*/
	// 使用+=复用去实现+
	// d1 + 100
	Date operator+(int day)
	{
		Date ret(*this);
		ret += day;
		//ret.operator+=(day);
		return ret;
	}

	// d1 += 100
	// d1.operator+=(&d1, 100);
	Date& operator+=(int day)
	{
		if (day < 0)
		{
			*this -= -day;
			return *this;
		}

		_day += day;
		while (_day > GetMonthDay(_year, _month))
		{
			// 减到当前月的天数
			_day -= GetMonthDay(_year, _month);
			// 月进1
			++_month;
			// 月满年进1，月置1
			if (_month == 13)
			{
				_year++;
				_month = 1;
			}
		}

		return *this;
	}

	Date operator-(int day)
	{
		Date ret(*this);
		ret -= day;
		return ret;
	}

	Date& operator-=(int day)
	{
		if (day < 0)
		{
			*this += -day;
			return *this;
		}

		_day -= day;
		while (_day <= 0) // 注意不是<
		{
			--_month;
			if (_month == 0)
			{
				--_year;
				_month = 12;
			}

			_day += GetMonthDay(_year, _month);
		}

		return *this;
	}

	// d1 - 100
	// Date operator-(int day);
	// d1 - d2
	int operator-(const Date& d)
	{

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

void test1()
{
	Date d1(2020, 3, 19);
	d1.Print();

	//Date d2(2021, 2, 29);
	//d2.Print();

	Date d3 = d1 + 100;
	d3.Print();
	d1.Print();

	Date d4 = d1 += 100;
	d4.Print();
	d1.Print();
	//d1 - 50;
	//d1 += 100;
	//d1 -= 50;
	//d1 - d2;

	d1 -= 100;
	d1.Print();
}

void test2()
{
	Date d1(2020, 3, 19);
	//d1 -= -50;
	Date d2(d1);
	//d1.Print();

	Date ret1 = d1++;
	Date ret2 = ++d2;
	d1.Print();
	ret1.Print();

	d2.Print();
	ret2.Print();
}

int main()
{
	test2();

	return 0;
}
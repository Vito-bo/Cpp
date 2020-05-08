
#include <iostream>
using namespace std;

class Date
{
public:
	// 获取某年某月的天数
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
	Date(int year = 0, int month = 0, int day = 0)
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


	// 日期+=天数(d1+=100)
	// d1.operator+=(&d1,100);
	Date& operator+=(int day)
	{
		if (day<0)
		{
			*this -= -day;
			return *this;
		}
		_day += day;
		while (_day > GetMonthDay(_year, _month))
		{
			// 减掉当前月的天数
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
	/*
	// d1+=100 
	// 用+复用去实现+=
	Date& operator+=(int day)
	{
		*this = *this + day;
		return *this;
	}

	// 日期+天数(d1+100)
	// d1.operator+(&d1,100);
	Date operator+(int day)
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
	}
	*/
	// 使用+=复用去实现+
	Date operator+(int day)
	{
		Date tmp(*this);
		tmp += day;
		return tmp;
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
	
	// ++d1;
	Date& operator++()
	{
		*this += 1;
		return *this;
	}

	// d1++
	// 后置++多调用两次拷贝构造，建议使用前置++
	Date operator++(int)  //为了区分与前置++，加一个参数
	{
		// 返回++之前的值
		Date tmp(*this);
		*this += 1;
		return tmp;
	}

	// d1<d2
	// 实际中这里不加inline也可以，因为直接在类中实现的函数，默认就是inline
	inline bool operator<(const Date& d)
	{
		if ((_year < d._year)
			|| (_year == d._year && _month < d._month)
			|| (_year = d._year&& _month == d._month&& _day < d._day))
		{
			return true;
		}
		return false;
	}

	// d1==d2
	inline bool operator==(const Date& d)
	{
		return _year == d._year &&_month == d._month&& _day == d._day;
	}
	
	// 如果日期类加了时分秒成员，如何增强代码的复用性，代码的改动最小
	// d1<=d2
	inline bool operator<=(const Date& d)
	{
		return *this < d || *this == d;
	}

	// d1 > d2
	inline bool operator>(const Date& d)
	{
		return !(*this <= d);
	}

	// d1>=d2
	inline bool operator>=(const Date& d)
	{
		return !(*this < 0);
	}
	
	// d1 != d2
	inline bool operator!=(const Date& d)
	{
		return !(*this == d);
	}

	// d1-天数
	//Date operator-(int day);
	// 日期-日期
	int operator-(const Date& d)
	{
		int flag = -1;
		Date min = *this;
		Date max = d;
		if (*this > d)
		{
			flag = 1;
			min = d;
			max = *this;
		}
		int n = 0;
		while (min != max)
		{
			++n;
			++min;
		}
		return n*flag;
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

	Date d3 = d1 + 100;
	d3.Print();
	d1.Print();


	Date d4 = d1 += 100;
	d4.Print();
	d1.Print();

	d3 -= 100;
	d3.Print();

	//d1 - 50;
	//d1 += 100;
	//d1 -= 50;
	//d1 - d2;

}

void test2()
{
	Date d1(2020, 3, 19);
	//d1 -= -50;
	Date d2(d1);
   // d1.Print();


	Date ret1 = d1++;
	Date ret2 = ++d2;
	d1.Print();
	ret1.Print();
	
	d2.Print();
	ret2.Print();

}

void test3()
{
	Date d1(2020, 3, 21);
	Date d2(2020, 9, 1);
	//cout << d1 - d2 << endl;
	cout << d2-d1<< endl;
}
int main()
{
	test3();
	return 0;
}
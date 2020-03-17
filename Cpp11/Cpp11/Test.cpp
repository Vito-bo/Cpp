

#include <iostream>
using namespace std;
//定义出来，就初始化了->构造函数
//	Date d1(2020, 3, 12);
//	d1.Print();
//
//	Date d2(2020, 3, 13);
//	d2.Print();
//
//	//Date d3();  // 导致d3没有被定义出来
//	Date d3; 
//	d3.Print();
//
//	// 构造函数只能在对象构造的时候自动调用一次,后面想要修改Init
//	d3.Init(2020, 3, 14);
//	d3.Print();
//
//	Date d4(2020);
//	d4.Print();
//
//	return 0;
//}


//class Date
//{
//public:
//	// 无参和3个参数无法和全缺省的3个参数构造函数并存
//	/*Date(int year, int month, int day)
//	{
//	_year = year;
//	_month = month;
//	_day = day;
//	}
//
//	Date()
//	{
//	_year = 0;
//	_month = 1;
//	_day = 1;
//	}*/
//
//	// 全缺省的构造函数 推荐的写法
//	Date(int year = 0, int month = 1, int day = 1)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//
//	// 没有写构造函数，编译器会生成一个默认构造函数
//
//	void Print()
//	{
//		cout << _year << "-" << _month << "-" << _day << endl;
//	}
//
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//int main()
//{
//	// 分别调用4个重载的构造函数 ， 推荐写全缺省的构造函数
//	Date d1;
//	Date d2(2020);
//	Date d3(2020, 1);
//	Date d4(2020, 2, 2);
//	d1.Print();
//	d2.Print();
//	d3.Print();
//	d4.Print();
//
//	Date d1;  // 调用默认的构造函数 ->C++中不用传参去调用构造函数就是默认构造函数
//	d1.Print();
//
//	return 0;
//}

//class Time
//{
//public:
//	Time()
//	{
//		cout << "Time()默认构造函数" << endl;
//		_hour = 0;
//		_minute = 0;
//		_second = 0;
//	}
//
//	/*Time(int hour)
//	{
//	_hour = hour;
//	_minute = 0;
//	_second = 0;
//	}*/
//
//	void Print()
//	{
//		cout << _hour << ":" << _minute << ":" << _second << endl;
//	}
//private:
//	int _hour;
//	int _minute;
//	int _second;
//};
//
//class Date
//{
//public:
//	void Print()
//	{
//		cout << _year << "-" << _month << "-" << _day << endl;
//		_t.Print();
//	}
//
//	// 我们不实现构造函数的时候，编译器会生成一个默认构造函数，
//	// 基本类型不初始化
//	// 自定义类型，会调用它(Time)的默认构造函数进行初始化
//private:
//	// 基本类型/内置类型
//	int _year;
//	int _month;
//	int _day;
//
//	// class或struct定义叫做自定义类型
//	Time _t;
//};
//
//int main()
//{
//	Date d1;
//	d1.Print();
//
//	return 0;
//}



//class Date
//{
//public:
//	// 全缺省的构造函数 推荐的写法
//	Date(int year = 0, int month = 1, int day = 1)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//
//	//~Date()
//	//{
//	//	// Date类没有资源需要清理，所以析构函数类什么都不用写
//	//}
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
//class Stack
//{
//public:
//	Stack(int n = 10)
//	{
//		_a = (int*)malloc(sizeof(int)*n);
//		_size = 0;
//		_capacity = n;
//	}
//
//	// Date不写析构，没问题，编译生成就可以
//	// Stack不写析构，有问题，有内存泄漏
//	//~Stack()
//	//{
//	//	// Stack的析构函数，有资源需要清理
//	//	free(_a);
//	//	_size = _capacity = 0;
//	//	_a = nullptr;
//	//}
//private:
//	int* _a;
//	int _size;
//	int _capacity;
//};
//
//int main()
//{
//	Date d1; // 析构函数并不是完成d1对象销毁，d1对象销毁时系统完成。析构函数完成的是清理工作？
//	d1.Print();
//
//	Stack st; //Stack st(100);
//	// Push/Pop
//
//	// struct Stack st
//	// Init     对比  构造函数
//	// Destory  对比  析构函数
//	// 经常忘了Init和Destory   对比 自动调用，不存在忘了的问题
//	// C++类使用构造函数和析构函数来解决这些问题
//
//	return 0;
//}

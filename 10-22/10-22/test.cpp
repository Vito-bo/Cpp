
#include<iostream>
using namespace std;

bool IsLeapYear(int year)
{
	if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
		return true;
	else
		return false;
}

int days[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

int GetMonthDays(int year, int month)
{
	if (month == 2 && IsLeapYear(year))
		return 29;
	return days[month];
}

bool IsValidDate(int year, int month, int day)
{
	if (year>0
		&& month >= 1 && month <= 12
		&& day >= 1 && day <= GetMonthDays(year, month))
		return true;
	else
		return false;
}

int main()
{
	int year, month, day;
	int ret = 0;
	cin >> year >> month >> day;
	//检测输入日期是否合法
	if (!IsValidDate(year, month, day))
	{
		cout << -1;
	}

	for (int i = 1; i < month; i++)
	{
		ret += days[i];
	}
	ret += day;
	if (IsLeapYear(year) && month>2)
	{
		ret += 1;
	}
	cout << ret <<endl;
	return 0;
}


/*
类和对象涉及到的知识点：
1.面向对象和面向过程的概念以及区别
2.类的定义
3.访问权限--private/protected/public
4.封装：
5.在C++中class和struct的区别？C语言中的struct和C++中的class区别？
6.一个类就是一个作用域
7.如何求一个类的大小？结论：注意：空类的大小是多少？为什么？
8.如何求一个结构体的大小？/什么是内存对齐？结构体为什么要进行内存对齐？
9.对齐参数如何设置？可以设置为任意值吗？
10.如何知道结构体中某个成员相对于结构体起始位置的偏移量？offsetof?模拟实现
11.什么是大小端？如何测试一个机器是大端还是小端？举一个使用大小端的场景？
12.大小端和操作系统有关系吗？

13.类的实例化--什么是类？什么是对象？类和对象的区别？
14.this指针
15.构造函数/拷贝构造函数/赋值运算符重载/析构函数
	概念，特性，调用场景，关于编译器默认生成的默认成员函数
16.运算符重载
17.const成员函数--const修饰成员函数的本质：修饰该成员函数的this指针
18.&操作符的重载

19.初始化列表， 
20.explicit关键字--》禁止单参类型构造函数类型转化的作用
21.static修饰类成员--静态成员变量 和 静态成员函数
22.友元---》友元函数 和 友元类
23.了解内部类
24.

*/




/*
动态内存管理
1.每个区域存储什么数据？
内核空间：（放的是与操作系统相关的代码，用户没有权限直接去操作，如果要操作只能通过指定的api函数进行）
栈：（存放于函数调用相关的一些数据：栈帧，函数的参数，函数体中的局部变量，一些寄存器信息）
	特性：函数调用完成之后，对应的栈帧就被回收了
内存映射段：放置（文件映射，动态库，匿名映射）
堆（C语言：malloc/calloc/realloc，这些空间用完之后，必须要用free来进行释放）
数据段：全局数据（变量和对象）被static修饰的静态数据（当程序启动时，该部分数据的空间就被开辟好了，当程序消亡时被撤销--即该位置存储的数据声明周期伴随程序）
代码段：放置用户的代码，以及只读的一些常量（该位置的数据是不能修改的）

2.为什么要进行分区？
	方便查找，便于管理
*/


/*
重点：总结sizeof和strlen的区别？？
C语言；malloc/calloc/realloc这三个方法之间的区别？
	相同点:
		都是C语言中用来进行动态内存申请的库函数
		申请的空间都在堆上，用完之后必须要使用free来进行释放
		如果空间申请成功，返回空间的首地址，如果申请失败返回的是NULL，因此在使用之前必须要进行判空
		返回值类型都是void* 在接收返回值时必须要进行强制类型转换
	不同点：
	参数个数不同
	功能上唯一不同点：calloc会将其申请的内容空间初始化为0
		void* malloc(size_t size)
			malloc的参数是用户所申请空间的字节数，申请成功返回空间的首地址，
			如果申请空间失败，返回的是NULL,用户在进行接受的时候必须要强转，在使用时必须要进行判空，
			使用完之后必须要借助free来进行释放
		void* calloc(size_t num, size_t size);
			num表示元素的个数，size表示单个元素所占的字节数
		void* realloc(void* p, size_t size);
			将p指向堆空间大小调整到size字节
			p==NULL-->该函数的功能与malloc类似--直接申请size个字节返回即可
			p!=NULL-->将p指向的空间大小调整到size字节
				假设：p指向空间的大小为oldsize
					size<=oldsize 将p指向的空间缩小，然后返回原空间的首地址即可
					size>oldsize: 将p指向的空间扩大


#include<iostream>
using namespace std;

int main()
{
	int* p = (int*)malloc(10 * sizeof(int));
	if (p == NULL)
	{

	}
	//在空间中存储数据
	free(p);
	return 0;
}
*/

/*
为什么C++需要重新设计一套自己的动态内存管理方式？


*/

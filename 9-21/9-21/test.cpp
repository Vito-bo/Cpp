
//引用详细解析

#include <iostream>
using namespace std;


#if 0
int main()
{
	int a = 10;
	const int& ra = a;

	// ra = 100;
	a = 200;

	double d = 12.34;

	const int& rd = d;

	d = 56.78;
	cout << rd << endl;
	return 0;
}
#endif



#if 0
// 引用作用一：可以使代码书写更加的简化
struct A
{
	int a;
	int b;

	struct B
	{
		int c;
		int d;
	};

	B sutB;
};


// typedef是给类型取别名的
typedef A::B STUB;

int main()
{
	A stuA;
	stuA.sutB.c = 10;

	// 后序代码对于stuA结构体中sutB成员中的c访问的特别多

	stuA.sutB.c = 20;
	stuA.sutB.c = 30;


	// 引用是给一个变量取别名的
	int& rc = stuA.sutB.c;
	rc = 40;


	// 定义一个B结构题的变量
	A::B b1;
	A::B b2;
	A::B b3;

	STUB b4;
	return 0;
}
#endif



#if 0
void Swap(int* pa, int* pb)
{
	int temp = *pa;
	*pa = *pb;
	*pb = temp;
}


// 引用类型作为函数的形参----基本上可以取到C语言中的一级指针
void Swap(int& left, int& right)
{
	int temp = left;
	left = right;
	right = temp;
}


// 对于该打印函数---不期望通过形参外边外部实参的
// 建议：如果不想通过形参来改变外部实参的情况下，可以以const类型引用作为形参
void Print(const int& r)
{
	// 但是：假设写代码的时候  手一滑
	//r = 100;
	cout << r << endl;
}


// 在C语言中，写一个函数，专门用来交换int*类型的指针，Swap函数该如何实现？
// 在C++语言中，写一个函数，专门用来交换int*类型的指针，Swap函数该如何实现？

int main()
{
	int a = 10;
	int b = 20;
	Swap(&a, &b);

	Print(a);
	Print(b);

	Swap(a, b);

	Print(a);
	Print(b);
	return 0;
}
#endif

#if 0
// 以引用的方式作为函数返回值时：
// 一定不能返回函数栈上空间----典型：局部变量
// 因为：函数结束后，函数体内部的局部变量就被销毁了
// 如果在外部以引用的方式来接收函数的返回值，外部的引用实际引用的就是一块非法的内存空间

// 返回：只要返回的实体/变量不受函数结束而销毁
// 比如：全局变量、局部静态变量、引用类型的参数
int& Add(int left, int right)
{
	int ret = left + right;
	cout << "&ret = " << &ret << endl;
	return ret;
}


int& TestRetRef(int& ra)
{
	ra = 10;
	return ra;
}


int main()
{
	// result就是Add函数中ret局部变量的别名
	int& result = Add(1, 2);
	//cout << "&result = " << &result << endl;
	//Add(3, 4);
	//Add(5, 6);

	int a = 0;
	int& r = TestRetRef(a);
	return 0;
}
#endif


// 在C++中，函数传参有三种方式：
// 传值、传地址、传引用
// 传值：形参是实参的一份拷贝，传参的效率低，不能通过形参改变外部的实参
// 传地址：形参保存的是实参的地址，传参效率高，可以通过形参改变外部的实参
// 传引用：形参实际是实参的别名，理论传参效率也比较高，可以通过形参改变外部的实参---可以达到与指针类似的效果，而且比指针可能性更高更安全


#if 0
// 传引用比传值的效率高
#include <time.h>
struct A{ int a[10000]; };

void TestFunc1(A a){}

void TestFunc2(A& a){}

void TestRefAndValue()
{
	A a;
	// 以值作为函数参数
	size_t begin1 = clock();
	for (size_t i = 0; i < 100000; ++i)
		TestFunc1(a);
	size_t end1 = clock();


	// 以引用作为函数参数
	size_t begin2 = clock();
	for (size_t i = 0; i < 100000; ++i)
		TestFunc2(a);
	size_t end2 = clock();


	// 分别计算两个函数运行结束后的时间
	cout << "TestFunc1(A)-time:" << end1 - begin1 << endl;
	cout << "TestFunc2(A&)-time:" << end2 - begin2 << endl;
}

int main()
{
	TestRefAndValue();
	return 0;
}
#endif


#if 0
// 传地址和传递效率的区别
// 传值和传引用在效率上几乎一样
#include <time.h>
struct A{ int a[10000]; };

void TestFunc1(A* a){}

void TestFunc2(A& a){}

void TestRefAndValue()
{
	A a;
	// 以值作为函数参数
	size_t begin1 = clock();
	for (size_t i = 0; i < 100000; ++i)
		TestFunc1(&a);
	size_t end1 = clock();


	// 以引用作为函数参数
	size_t begin2 = clock();
	for (size_t i = 0; i < 100000; ++i)
		TestFunc2(a);
	size_t end2 = clock();


	// 分别计算两个函数运行结束后的时间
	cout << "TestFunc1(A*)-time:" << end1 - begin1 << endl;
	cout << "TestFunc2(A&)-time:" << end2 - begin2 << endl;
}

int main()
{
	for (int i = 0; i < 10; ++i)
	{
		TestRefAndValue();
		cout << endl;
	}

	return 0;
}
#endif


#if 0
// C++中面试中高频题目：引用和指针有什么区别？

void Swap(int* left, int* right)
{
	int temp = *left;
	*left = *right;
	*right = temp;
}


// 引用类型作为函数的形参----基本上可以取到C语言中的一级指针
void Swap(int& left, int& right)
{
	int temp = left;
	left = right;
	right = temp;
}

int main()
{
	int a = 10;
	int b = 20;

	Swap(&a, &b);   // 调用int*
	Swap(a, b);     // 调用int&

	int* pa = &a;
	*pa = 100;

	int& ra = a;
	ra = 100;

	return 0;
}
#endif


#if 0
int main()
{
	int a = 10;
	int& ra = a;

	int* p = &a;

	int b = 20;
	p = &b;

	char c = 'a';
	char& rc = c;
	char* pc = &c;

	rc++;
	pc++;
	cout << sizeof(rc) << endl;
	cout << sizeof(pc) << endl;

	int*p1;
	int** p2;
	int*** p3;

	int d = 10;
	int& rd = d;
	//int&& rrd = d;
	//int&&& rrrd = d;

	// C++11中提出的右值引用
	const int&& rrd = 10;
	return 0;
}
#endif


int main()
{
	const int a = 10;
	int* pa = (int*)&a;

	*pa = 100;

	cout << a << endl;
	cout << *pa << endl;
	return 0;
}
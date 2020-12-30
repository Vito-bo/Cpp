
#include <iostream>
using namespace std;


// 引用学习
int& Count()
{
	static int n = 0;
	n++;
	return n;
}

int main()
{
	Count();
	return 0;
}


#if 0
#include <time.h>
struct A{
	int a[100000];
};

void TestFunc1(A a){}
void TestFunc2(A* a){}
void TestFunc3(A& a){}
void TestRefAndValue()
{
	A a;
	// 以值作为函数参数
	size_t begin1 = clock();
	for (size_t i = 0; i < 100000; ++i)
	{
		TestFunc1(a);
	}
	size_t end1 = clock();

	size_t begin2 = clock();
	for (size_t i = 0; i < 100000; ++i)
		TestFunc2(&a);
	size_t end2 = clock();

	// 以引用作为函数参数
	size_t begin3 = clock();
	for (size_t i = 0; i < 100000; ++i)
		TestFunc3(a);
	size_t end3 = clock();


	// 分别计算两个函数运行结束后的时间
	cout << "TestFunc1(A)-time:" << end1 - begin1 << endl;
	cout << "TestFunc1(A*)-time:" << end1 - begin1 << endl;
	cout << "TestFunc2(A&)-time:" << end2 - begin2 << endl;
}

int main()
{
	int a = 10;        //ra就是a的别名
	const int& ra = a; //ra和a在底层使用的是同一块内存空间

	// ra = 100; 不能直接通过ra修=修改a空间中存储的内容，因为：ra被const限制
	a = 200;           //修改a,ra也被修改了
	return 0;
}


int main()
{
	double d = 12.34;
	const int& rd = d;

	d = 56.78;
	cout << rd << endl; //12
	//d和rd的地址不一样，rd并不是d的别名，即rd引用的不是d
	return 0;
}


int& Add(int left, int right)
{
	int ret = left + right;
	return ret;
}
int main()
{
	int& result = Add(1, 2);

	Add(3, 4);//result=7
	Add(5, 6);//result=11
	//Add函数运行结束后，它并没有清理栈帧中所留下的垃圾数据，
	//因此：result是ret的别名，result可以看到空间中的垃圾数据。
	return 0;
}

int main()
{
	int a = 10;
	int* pa = &a;
	int& ra = a;
	int b = 20;
	ra = b;

	return 0;
}

void Swap(int* pa, int* pb)
{
	int tmp = *pa;
	*pa = *pb;
	*pb = tmp;
}
// 引用类型作为函数的形参
void Swap(int& left, int& right)
{
	int tmp = left;
	left = right;
	right = tmp;
}

/// 建议：如果不想通过形参来改变外部实体的情况下，可以以const类型引用作为形参
void Print(const int& r)
{
	cout << r << endl;
}
int main()
{
	int a = 10;
	int b = 20;
	Swap(&a, &b); // 调用int*
	
	Print(a);
	Print(b);

	Swap(a, b);  // 调用int&
	Print(a);
	Print(b);

	return 0;
}



// 在C++中，函数传参有三种方式：传值，传地址，传引用
// 传值：形参是实参的一份拷贝，传参的效率低，不会通过改变形参而改变外部的实参。
// 传地址：形参保存的是实参的地址，传参效率高，可以通过形参改变外部的实参。
// 传引用：形参实际是实参的别名，传递效率高，可以通过形参改变外部的实参--可以达到与指针类似的效果，而且比指针可用性更高更安全


// 传值和传引用
#include <time.h>
struct A{
	int a[100000];
};

void TestFunc1(A a){}
void TestFunc2(A* a){}
void TestFunc3(A& a){}
void TestRefAndValue()
{
	A a;
	// 以值作为函数参数
	size_t begin1 = clock();
	for (size_t i = 0; i < 100000; ++i)
	{
		TestFunc1(a);
	}
	size_t end1 = clock();

	size_t begin2 = clock();
	for (size_t i = 0; i < 100000; ++i)
		TestFunc2(&a);
	size_t end2 = clock();

	// 以引用作为函数参数
	size_t begin3 = clock();
	for (size_t i = 0; i < 100000; ++i)
		TestFunc3(a);
	size_t end3 = clock();


	// 分别计算两个函数运行结束后的时间
	cout << "TestFunc1(A)-time:" << end1 - begin1 << endl;
	cout << "TestFunc1(A*)-time:" << end1 - begin1 << endl;
	cout << "TestFunc2(A&)-time:" << end2 - begin2 << endl;
}

void Test()
{
	const int a = 10;
	//int& ra = a;     //编译出错，a为常量
	const int& ra = a; 

	//int& b = 10;      //编译出错，b为常量
	const int& b = 10;

	double d = 12.34;
	//int& rd = d;        //编译时出错，类型不同
	const int& rd = d;
}
int main()
{

	int a = 10;
	int& ra = a;
	//int&& rra = ra;

	TestRefAndValue();
	return 0;
}
#endif
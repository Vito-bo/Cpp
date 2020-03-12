
#include <iostream>
using namespace std;
/*
//1.普通的命名空间
namespace N1 //N1为命名空间
{
	//命名空间中的内容既可以定义变量，也可以定义函数
	int a;
	int Add(int left, int right)
	{
		return left + right;
	}
}

//2.命名空间可以嵌套
namespace N2
{
	int a;
	int b;
	int Add(int left, int right)
	{
		return left + right;
	}

	namespace N3
	{
		int c;
		int d;
		int Sub(int left, int right)
		{
			return left - right;
		}
	}
}

//3.同一个工程中允许存在多个相同名称的命名空间，编译器最后会合成同一个命名空间中。
namespace N1
{
	int Mul(int left, int right)
	{
		return left*right;
	}
}
// 一个命名空间就定义了一个新的作用域
// 命名空间中的所有内容都局限于该命名空间中

//2.命名空间的使用
namespace N
{
	int a = 10;
	int b = 20;
	int Add(int left, int right)
	{
		return left + right;
	}
	int Sub(int left, int right)
	{
		return left - right;
	}
}
//命名空间的三种使用方式
//1.加命名空间名称及作用域限定符
//int main()
//{
//	//printf("%d\n", a);  //编译出错，无法识别a
//	printf("%d\n", N::a); 
//	return 0;
//}

//2.使用using将命名空间中成员引入
//using N::b;
//int main()
//{
//	printf("%d\n", N::a);
//	printf("%d\n", b);
//	return 0;
//}

//3.使用using namespace 命名空间名称引入
using namespace N;
int main()
{
	printf("%d\n", a);
	printf("%d\n", b);
	printf("%d\n", Add(10,20));
	return 0;
}

//3.C++输入&输出

//cout标准输出（控制台）cin标准输入（键盘）
//必须包含<iostream>头文件以及std标准命名空间
using namespace std;
int main()
{
	cout << "Hello World!" << endl;
	return 0;
}

//2.使用C++输入输出更方便，不需要增加数据格式控制
using namespace std;
int main()
{
	int a;
	double b;
	char c;
	cin >> a;
	cin >> b >> c;

	cout << a << endl;
	cout << b << " " << c << endl;
	return 0;
}

//4.缺省参数
//缺省参数是声明或定义函数时为函数的参数指定一个默认值
//在掉用该函数时，如果没有指定实参则采用该默认值，否则使用指定的实参

using namespace std;
void Test(int a = 0)
{
	cout << a << endl;
}
int main()
{
	Test();  //没有传参时，使用参数的默认值
	Test(10);//传参时，使用指定的实参
	return 0;
}

//4.1缺省参数分类
//全缺省参数
using namespace std;
void TestFunc(int a = 10, int b = 20, int c = 30)
{
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;
	cout << "c = " << c << endl;
}
//半缺省参数
void TestFunc1(int a, int b = 20, int c = 30)
{
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;
	cout << "c = " << c << endl;
}
int main()
{
	TestFunc();
	TestFunc(1);
	TestFunc(1,2);
	TestFunc(1, 2, 3);
	TestFunc1(1, 2);
	return 0;
}
//全缺省就是参数全部给缺省值，半缺省是缺省部分的值
//1.半缺省参数必须从右向左依次来给出，不能间隔着给
//2.缺省参数不能在函数声明和定义中同时出现
//3.缺省值必须是常量或者全局变量
//C语言不支持（编译器不支持）

//5.函数重载
//C++允许在同一作用域中声明几个功能类似的同名函数。
//这些同名函数的形参列表（参数个数/类型/顺序）必须不同

using namespace std;
int Add(int left, int right)
{
	return left + right;
}
double Add(double left, double right)
{
	return left + right;
}
long Add(long left, long right)
{
	return left + right;
}
int main()
{
	int a = Add(10, 20);
	double b = Add(10.0, 20.0);
	long c =  Add(10L, 20L);
	cout << a << " " << b << " " << c << endl;
	return 0;
}

extern "C" int Add(int left, int right);
int main()
{
	Add(10, 20);
	return 0;
}

//6.引用
//引用不是新定义一个变量，而是给已存在变量取一个别名
//编译器不会为引用变量开辟内存空间，它和它引用的变量共用同一块内存
//引用类型必须和引用实体是同种类型
//一个变量可以有多个引用
int main()
{
	int a = 10;
	//int& ra; //编译出错，引用在定义时必须初始化
	int& ra = a; 
	int& rra = a;
	printf("%p\n", &a);
	printf("%p\n", &ra);
	printf("%p\n", &rra);
	return 0;
}

//6.1常引用
int main()
{
	const int a = 10;
	// 权限放大，只读—>可读可写
	//int& ra = a;//a为常量，其值不能改变，b是a的别名也不可以改变
	const int& ra = a;
	//int& b = 10;
	//权限缩小，可读可写-》只读
	const int& c = 10;//c只能读，不能改变
	double d = 12.34;
	int& rd = d;
	const int& rd = d;

}


//6.2 引用做参数
void Swap(int& left, int& right)
{
	int temp = left;
	left = right;
	right = temp;
}
int main()
{
	int a = 2, b = 3;
	Swap(a, b);
	return 0;
}

int& Add(int a, int b)
{
	int c = a + b;
	return c;
}

int main()
{
	int& ret = Add(1, 2);
	cout << "Add(1, 2) is :" << ret << endl;
	Add(3, 4);
	cout << "Add(1, 2) is :" << ret << endl;
	return 0;
}


#include <time.h>
//struct A{ int a[10000]; };

A a;
// 值返回
A TestFunc1() { return a; }
// 引用返回
A& TestFunc2(){ return a; }

void TestReturnByRefOrValue()
{
	// 以值作为函数的返回值类型
	size_t begin1 = clock();
	for (size_t i = 0; i < 100000; ++i)
		TestFunc1();
	size_t end1 = clock();

	// 以引用作为函数的返回值类型
	size_t begin2 = clock();
	for (size_t i = 0; i < 100000; ++i)
		TestFunc2();
	size_t end2 = clock();

	// 计算两个函数运算完成之后的时间
	cout << "TestFunc1 time:" << end1 - begin1 << endl;
	cout << "TestFunc2 time:" << end2 - begin2 << endl;
}
int main()
{
	TestReturnByRefOrValue();

	return 0;
}

int main()
{
	int a = 10;

	int& ra = a;
	int* pa = &a;

	return 0;
}


inline int Add(int a, int b)
{
	int c = a + b;
	return c;
}

// C语言如何解决小函数频繁调用开销？-》宏函数
// C++如何解决小函数频繁调用开销? -》inline函数

int main()
{
	Add(1, 2);

	return 0;
}

#include <unordered_map>

int main()
{
	int a = 10;
	int b = a;
	
	auto c = a; // 通过a的类型自动推导出c的类型是int
	cout << typeid(c).name() << endl;

	std::unordered_map<std::string, std::string> m;
	// auto真正作用的体现，以后会有比较复杂的类型定义，使用auto会方便些
	//std::unordered_map<std::string, std::string>::iterator it = m.begin();
	auto it = m.begin();

	return 0;
}


int main()
{
	int x = 10;
	auto a = &x;
	auto* b = &x;
	auto& c = x;

	cout << typeid(a).name() << endl;
	cout << typeid(b).name() << endl;
	cout << typeid(c).name() << endl;

	int array[] = { 1, 2, 3, 4, 5 };
	for (int i = 0; i < sizeof(array) / sizeof(array[0]); ++i)
	{
		array[i] *= 2;
	}

	// 新写法上更便捷  ->语言更新的趋势，简化用法
	for (auto& e : array)
	{
		e *= 2;
	}

	// 范围for
	for (auto e : array)
	{
		cout << e << " ";
	}
	cout << endl;
}
void f(int)
{
	cout << "f(int)" << endl;
}

void f(int*)
{
	cout << "f(int*)" << endl;
}

#ifdef __cplusplus
#define NULL    0
#else

int main()
{
	f(0);
	f(NULL); // 预处理以后变成f(0)
	f(nullptr);

	int* p1 = NULL; // C
	int* p2 = nullptr; // C++11推荐用

	// 结论：C++11的环境中，统一使用nullptr代表空指针

	return 0;
}
*/





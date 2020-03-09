
#include <iostream>
using namespace std;

//int& Add(int a, int b)
//{
//	int c = a + b;
//	return c;
//}
//
//int main()
//{
//	int& ret = Add(1, 2);
//	cout << "Add(1, 2) is :" << ret << endl;
//	Add(3, 4);
//	cout << "Add(1, 2) is :" << ret << endl;
//	return 0;
//}

//#include <time.h>
////struct A{ int a[10000]; };
//
//A a;
//// 值返回
//A TestFunc1() { return a; }
//// 引用返回
//A& TestFunc2(){ return a; }
//
//void TestReturnByRefOrValue()
//{
//	// 以值作为函数的返回值类型
//	size_t begin1 = clock();
//	for (size_t i = 0; i < 100000; ++i)
//		TestFunc1();
//	size_t end1 = clock();
//
//	// 以引用作为函数的返回值类型
//	size_t begin2 = clock();
//	for (size_t i = 0; i < 100000; ++i)
//		TestFunc2();
//	size_t end2 = clock();
//
//	// 计算两个函数运算完成之后的时间
//	cout << "TestFunc1 time:" << end1 - begin1 << endl;
//	cout << "TestFunc2 time:" << end2 - begin2 << endl;
//}
//int main()
//{
//	TestReturnByRefOrValue();
//
//	return 0;
//}

//int main()
//{
//	int a = 10;
//
//	int& ra = a;
//	int* pa = &a;
//
//	return 0;
//}


//inline int Add(int a, int b)
//{
//	int c = a + b;
//	return c;
//}
//
//// C语言如何解决小函数频繁调用开销？-》宏函数
//// C++如何解决小函数频繁调用开销? -》inline函数
//
//int main()
//{
//	Add(1, 2);
//
//	return 0;
//}

#include <unordered_map>

//int main()
//{
//	int a = 10;
//	int b = a;
//	
//	auto c = a; // 通过a的类型自动推导出c的类型是int
//	cout << typeid(c).name() << endl;
//
//	std::unordered_map<std::string, std::string> m;
//	// auto真正作用的体现，以后会有比较复杂的类型定义，使用auto会方便些
//	//std::unordered_map<std::string, std::string>::iterator it = m.begin();
//	auto it = m.begin();
//
//	return 0;
//}


//int main()
//{
//	int x = 10;
//	auto a = &x;
//	auto* b = &x;
//	auto& c = x;
//
//	cout << typeid(a).name() << endl;
//	cout << typeid(b).name() << endl;
//	cout << typeid(c).name() << endl;
//
//	int array[] = { 1, 2, 3, 4, 5 };
//	for (int i = 0; i < sizeof(array) / sizeof(array[0]); ++i)
//	{
//		array[i] *= 2;
//	}
//
//	// 新写法上更便捷  ->语言更新的趋势，简化用法
//	for (auto& e : array)
//	{
//		e *= 2;
//	}
//
//	// 范围for
//	for (auto e : array)
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//}
void f(int)
{
	cout << "f(int)" << endl;
}

void f(int*)
{
	cout << "f(int*)" << endl;
}

//#ifdef __cplusplus
//#define NULL    0
//#else

//int main()
//{
//	f(0);
//	f(NULL); // 预处理以后变成f(0)
//	f(nullptr);
//
//	int* p1 = NULL; // C
//	int* p2 = nullptr; // C++11推荐用
//
//	// 结论：C++11的环境中，统一使用nullptr代表空指针
//
//	return 0;
//}

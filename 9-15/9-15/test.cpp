
#include <iostream>
using namespace std;
#include <time.h>

////传值，传引用效率比较
//struct A{ int a[10000]; };
//void TestFunc1(A a){}
//
//void TestFunc2(A& a){}
//
//void TestRefAndValue()
//{
//	A a;
//	//以值作为函数参数
//	size_t begin1 = clock();
//	for (size_t i = 0; i < 10000; i++){
//		TestFunc1(a);
//	}
//	size_t end1 = clock();
//
//	//以引用作为函数参数
//	size_t begin2 = clock();
//	for (size_t i = 0; i < 10000; i++){
//		TestFunc2(a);
//	}
//	size_t end2 = clock();
//
//	//分别计算两个函数运行结束后的时间
//	cout << "TestFunc1(A)-time:" << end1 - begin1 << endl; //9
//	cout << "TestFunc2(A&)-time:" << end2 - begin2 << endl;//0 
//}
//以值作为参数或者返回值类型，在传值和返回值期间，函数不会直接传递实参或者将变量本身直接返回
//而是传递实参或者返回变量的一份临时的拷贝，因此用值作为参数或者返回值类型，效率是非常低下的

////值和引用的作为返回值类型的性能比较
//struct A{ int a[10000]; };
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
//	// 以引用作为函数的返回值类型
//	size_t begin2 = clock();
//	for (size_t i = 0; i < 100000; ++i)
//		TestFunc2();
//	size_t end2 = clock();
//	// 计算两个函数运算完成之后的时间
//	cout << "TestFunc1 time:" << end1 - begin1 << endl;//191
//	cout << "TestFunc2 time:" << end2 - begin2 << endl;//1
//}
////传值和引用在作为传参以及返回值类型上效率相差很大
////传值引用一般就是生成一个临时对象，而引用调用是调用参数本身
//int main()
//{
//	//TestRefAndValue();
//	TestReturnByRefOrValue();
//	return 0;
//}

////引用和指针的区别
////引用在语法概念上就是一个别名，和其引用实体共用同一块空间
////在底层实现上实际是有空间的，因为引用是按照指针方式来实现的
//int main()
//{
//	int a = 10;
//	int& ra = a;
//	ra = 20;
//	int* pa = &a;
//	*pa = 20;
//	return 0;
//}

////内联函数-inline修饰的函数
////C++编译器在函数待用内联函数的地方展开
//inline int Add(int left, int right)
//{
//	return left + right;
//}
//int main()
//{
//	int ret = 0;
//	ret = Add(2, 3);
//	return 0;
//}

////auto关键字:auto声明的变量必须由编译器在编译器在编译时推导而得
//int TestAuto()
//{
//	return 10;
//}
//int main()
//{
//	int a = 10;
//	auto b = a;
//	auto c = 'a';
//	auto d = TestAuto();
//	cout << typeid(b).name() << endl;
//	cout << typeid(c).name() << endl;
//	cout << typeid(d).name() << endl;
//	//auto e; 无法通过编译，使用auto定义变量时必须对其进行初始化
//	return 0;
//}

////auto的使用细则
//int main()
//{
//	int x = 10;
//	auto a = &x;
//	auto* b = &x;
//	auto& c = x;
//	cout << typeid(a).name() << endl;
//	cout << typeid(b).name() << endl;
//	cout << typeid(c).name() << endl;
//	*a = 20;
//	*b = 30;
//	c = 40;
//	return 0;
//}

//基于范围for循环
int main()
{
	int array[] = { 1, 2, 3, 4, 5 };
	for (auto& e : array)
		e *= 2;
	for (auto e : array)
		cout << e << " ";
	return 0;
}



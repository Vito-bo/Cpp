
#include <iostream>
using namespace std;

//
//class Sum
//{
//public:
//	Sum()
//	{
//		_sum += _i;
//		++_i;
//	}
//	//静态成员变量初始化
//	static void Init()
//	{
//		_i = 1;
//		_sum = 0;
//	}
//	static int GetSum()
//	{
//		return _sum;
//	}
//private:
//	static int _i;
//	static int _sum;
//};
//
//int Sum::_i = 1;
//int Sum::_sum = 0;
//
//class Solution {
//public:
//	int Sum_Solution(int n) {
//		//Sum a[n]; //c99 变长数组
//		Sum::Init();
//		Sum* p = new Sum[n];
//		return Sum::GetSum();
//	}
//};

//int main()
//{
//	// 一个int
//	int* p1 = (int*)malloc(sizeof(int)); //C
//	int* p2 = new int; //C++
//
//	free(p1);
//	p1 = nullptr;
//	delete p2;
//	p2 = nullptr;
//
//	//10个int型的数组
//	int* p3 = (int*)malloc(sizeof(int)* 10);
//	int* p4 = new int[10];
//
//	free(p3);
//	delete[] p4;
//
//	//申请一个int对象，并且初始化成10
//	int* p5 = new int(10);
//	delete p5;
//
//
//
//	return 0;
//}

//void Test()
//{
//	//动态申请一个int类型的空间
//	int* p1 = new int;
//	//动态申请一个int类型的空间并初始化为10
//	int* p2 = new int(10);
//	//动态申请10个int类型的空间
//	int* p3 = new int[10];
//
//	//new delete操作符
//	delete p1;
//	delete p2;
//	delete[] p3;
//}

//new和delete操作自定义类型
//class Test
//{
//public:
//	Test()
//		: _data(0)
//	{
//		cout << "Test():" << this << endl;
//	}
//	~Test()
//	{
//		cout << "~Test():" << this << endl;
//	}
//private:
//	int _data;
//};
//
//void Test1()
//{
//	// 申请单个Test类型的空间
//	Test* p1 = (Test*)malloc(sizeof(Test));
//	free(p1);
//
//	// 申请10个Test类型的空间
//	Test* p2 = (Test*)malloc(sizeof(Test)*10);
//	free(p2);
//
//}
//
//void Test2()
//{
//	// 申请单个Test类型的空间
//	Test* p1 = new Test;
//	delete p1;
//
//	// 申请10个Test类型的空间
//	Test* p2 = new Test[10];
//	delete[] p2;
//}
//
//int main()
//{
////	Test1();
//	Test2();
//	
//	return 0;
//}

/*
operator new：该函数实际通过malloc来申请空间，当malloc申请空间成功时直接返回；申请空间失败，
尝试执行空 间不足应对措施，如果改应对措施用户设置了，则继续申请，否则抛异常。
*/

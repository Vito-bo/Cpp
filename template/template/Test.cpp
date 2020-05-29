#include <iostream>
#include <assert.h>
using namespace std;

////通用的交换函数
//void Swap(int& left, int& right)
//{
//	int temp = left;
//	left = right;
//	right = temp;
//}
//void Swap(double& left, double& right)
//{
//	double temp = left;
//	left = right;
//	right = temp;
//}
//void Swap(char& left, char& right)
//{
//	char temp = left;
//	left = right;
//	right = temp;
//}

//泛型编程：编写与类型无关的通用代码，是代码复用的一种手段。
//模板泛型编程的基础

////函数模板
////template<typename T>
//template<class T>
//void Swap(T& left, T& right)
//{
//	T temp = left;
//	left = right;
//	right = temp;
//}
//
//int main()
//{
//	double d1 = 2.0;
//	double d2 = 5.0;
//	Swap(d1, d2);
//	return 0;
//}

////隐式实例化：让编译器根据实参推演模板参数的实际类型
//template<class T>
//T Add(const T& left, const T& right)
//{
//	return left + right;
//}
//int main()
//{
//	int a1 = 10, a2 = 10;
//	double d1 = 10.0, d2 = 20.0;
//	cout<<Add(a1, a2)<<endl;
//	cout<<Add(d1, d2)<<endl;
//	
//	//cout << Add(a1, d1) << endl;
//	//用户强制转化
//	cout << Add(a1, (int)d1) << endl;
//
//	return 0;
//}

////显式实例化：在函数名后的<>中指定参数的实际类型
//template<class T>
//T Add(const T& left, const T& right)
//{
//	return left + right;
//}
//int main()
//{
//	int a = 10;
//	double d = 20.0;
//	cout << Add<int>(a, d) << endl;
//
//
//	return 0;
//}

////专门处理int的加法函数
//int Add(int left, int right)
//{
//	return left + right;
//}
//
////通用加法函数
//template<class T>
//T Add(T left, T right)
//{
//	return left + right;
//}
//int main()
//{
//	Add(1, 2); //与非模板函数匹配，编译器不需要特化
//	Add<int>(1, 2); //调用编译器特化的Add函数
//
//	return 0;
//}

//// 专门处理int的加法函数
//int Add(int left, int right)
//{
//	return left + right;
//}
//// 通用加法函数
//template<class T1, class T2>
//T1 Add(T1 left, T2 right)
//{
//	return left + right;
//}
//void Test()
//{
//	Add(1, 2); // 与非函数模板类型完全匹配，不需要函数模板实例化
//	Add(1, 2.0); // 模板函数可以生成更加匹配的版本，编译器根据实参生成更加匹配的Add函
//
//}

namespace bit_c
{
	// 顺序表 -- 可以动态增长的数组
	// C语言定义的顺序表
	// 数据和方法是分开定义
	// 问题1：数据是可以被随便改的  CPP如何解决->类的封装 先把数据和方法放到一起，通过访问限定符保护一起
	// 问题2：代码冗余，要同时满足SeqList seq1,要存int; SeqList seq2,存double.
	//        面对问题2，C就能去定义出两份实现，代码逻辑一样，类型不一样  CPP如何解决-》类模板
	typedef int SLDataType;
	typedef struct SeqList
	{
		SLDataType*   _a;
		size_t _size;
		size_t _capacity;
	}SeqList;

	void SeqListInit(SeqList* ps, size_t n) // cpp->构造函数解决
	{}
	void SeqListDestory(SeqList* ps)        // cpp->析构函数解决
	{}
	void SeqListPrint(SeqList* ps);
	void SeqListCheckCapacity(SeqList* ps);
	void SeqListPushBack(SeqList* ps, SLDataType x)  // c两个参数，cpp->看起来只有一个参数，实际也是两个，有一个是隐含的this
	{}
	void SeqListPopBack(SeqList* ps);
}

namespace bit_cpp
{
	// typedef int SLDataType;
	template<class T>
	class SeqList
	{
	public:
		SeqList(size_t n = 10)
			:_a(new T[n])
			, _size(0)
			, _capcity(n)
		{}

		~SeqList()
		{
			if (_a != nullptr)
			{
				delete[] _a;
				_size = _capcity = 0;
			}

		}

		void PushBack(T x)
		{
			// ...
		}

		// a[i]
		// a[i] = 0;
		T& operator[](size_t i)
		{
			// 断言i访问的位置是否合法
			assert(i < _size);

			return _a[i];
		}

		// ...

	private:
		T*           _a;
		size_t      _size;
		size_t      _capcity;
	};
	
}

int main()
{
	//// C中使用顺序表
	//bit_c::SeqList seqc;
	//bit_c::SeqListInit(&seqc, 10);
	//// ...
	//bit_c::SeqListPushBack(&seqc, 1);
	//bit_c::SeqListPushBack(&seqc, 2);
	//bit_c::SeqListPushBack(&seqc, 3);
	//bit_c::SeqListDestory(&seqc);


	// CPP中使用顺序表
	bit_cpp::SeqList<int> seqcpp1;
	seqcpp1.PushBack(1);
	seqcpp1.PushBack(2);
	seqcpp1.PushBack(3);

	// 读第i个位置的数据
	cout << seqcpp1[0] << endl;
	// 写第i个位置数据
	// seqcpp1.operator[](0) = 0;
	seqcpp1[0] = 0;
	seqcpp1[1] = 0;

	bit_cpp::SeqList<double> seqcpp2;
	seqcpp2.PushBack(1.1);
	seqcpp2.PushBack(2.2);
	seqcpp2.PushBack(3.3);


	return 0;
}


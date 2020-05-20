
#include <iostream>
#include <assert.h>
using namespace std;


////1.泛型编程
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
//...
//泛型编程：编写与类型无关的通用代码，是代码复用的一种手段。
//模板是泛型编程的基础

//1.函数模板

//template<class T>
//void Swap(T& left, T& right)
//{
//	T temp = left;
//	left = right;
//	right = temp;
//}
////注意：typename是用来定义模板参数关键字，也可以使用class(切记：不能使用struct代替class)
//

//int main()
//{
//	//int i1 = 10;
//	//int i2 = 20;
//
//	//char a = '0';
//	//char b = '9';
//
//	double d1 = 2.0;
//	double d2 = 5.0;
//
//	//Swap(i1, i2);
//	//Swap(a, b);
//	Swap(d1, d2);
//
//
//	return 0;
//}

//隐式实例化

//template<class T>
//T Add(const T& left, const T& right)
//{
//	return left + right;
//}
////int main()
////{
////	int a1 = 10, a2 = 20;
////	double d1 = 10.0, d2 = 20.0;
////	Add(a1, a2);
////	Add(d1, d2);
////	/*
////	该语句不能通过编译，因为在编译期间，当编译器看到该实例化时，需要推演其实参类型
////	通过实参a1将T推演为int，通过实参d1将T推演为double类型，但模板参数列表中只有一个T，
////	编译器无法确定此处到底该将T确定为int 或者 double类型而报错
////	注意：在模板中，编译器一般不会进行类型转换操作，因为一旦转化出问题，编译器就需要背黑锅
////	Add(a1, d1);
////	*/
////	// 此时有两种处理方式：1. 用户自己来强制转化 2. 使用显式实例化
////	Add(a1, (int)d1);
////	return 0;
////}
//
////显式实例化：在函数名后的<>中指定模板参数的实际类型
//
//int main()
//{
//	int a = 10;
//	double d = 20.0;
//	//显式实例化
//	Add<int>(a, d);
//	return 0;
//}

//模板参数的匹配原则
// 专门处理int的加法函数
//int Add(int left, int right)
//{
//	return left + right;
//}
//// 通用加法函数
//template<class T>
//T Add(T left, T right)
//{
//	return left + right;
//}
//void Test()
//{
//	Add(1, 2); // 与非模板函数匹配，编译器不需要特化
//	Add<int>(1, 2); // 调用编译器特化的Add版本
//
//	Add(1, 2.0);
//}
//模板函数不允许自动类型转换，但普通函数可以进行自动类型转换

//类模板
//动态顺序表
template<class T>
class Vector
{
	Vector(size_t capacity = 10)
	: _pData(new T[capacity])
	, _size(0)
	, _capacity(capacity)
	{}

	//使用析构函数演示：在类中声明，在类外定义
	~Vector();

	void PushBack(const T& data);
	void PopBack();
	//...
	T& operator[](size_t pos)
	{
		assert(pos < _size);
		return _pData[pos];
	}
private:
	T* _pData;
	size_t _size;
	size_t _capacity;
};
//注意：类模板中函数放在类外进行定义时，需要加模板参数列表
template <class T>
Vector<T>::Vector()
{
	if (_pData)
		delete[] _pData;
	_size = _capacity = 0;
}

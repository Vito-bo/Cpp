#include <iostream>
using namespace std;

////1.非类型模板参数
//namespace bo
//{
//	//定义一个模板类型的静态数组
//	template<class T, size_t N=10>
//	class array
//	{
//	public:
//		T& operator[](size_t index){
//			return _array[index];
//		}
//		const T& operator[](size_t index)const{
//			return _array[index];
//		}
//		size_t size()const{
//			return _size;
//		}
//		bool empty()const{
//			return 0 == _size;
//		}
//	private:
//		T _array[N];
//		size_t _size;
//	};
//}
//
////模板的特化
//template<class T>
//bool IsEqual(T& left, T& right)
//{
//	return left == right;
//}
//void Test()
//{
//	char* p1 = "hello";
//	char* p2 = "world";
//	if (IsEqual(p1, p2))
//		cout << p1 << endl;
//	else
//		cout << p2 << endl;
//}
//
////函数模板特化
//template<>
//bool IsEqual<char*>(char*& left, char*& right)
//{
//	if (strcmp(left, right) > 0)
//		return true;
//	return false;
//}
////一般情况下如果函数模板遇到不能处理或者处理有误的类型，为了实现简单通常都是将该函数直接给出
//bool IsEqual(char* left, char* right)
//{
//	if (strcmp(left, right) > 0)
//		return true;
//	return false;
//}

////2.类模板的特化-全特化
////全特化是将模板参数列表中所有的参数都确定化
//template<class T1, class T2>
//class Data
//{
//public:
//	Data(){
//		cout << "Data<T1,T2>" << endl;
//	}
//private:
//	T1 _d1;
//	T2 _d2;
//};
//
////template<>
//class Data<int, char>
//{
//public:
//	Data() { cout << "Data<int, char>" << endl; }
//private:
//	T1 _d1;
//	T2 _d2;
//};
//
//void TestVector()
//{
//	Data<int, int> d1;
//	Data<int, char> d2;
//}

//2.2偏特化
//任何对模板参数进一步进行条件限制的特化版本。
// 将第二个参数特化为int
template<class T1, class T2>
class Data
{
public:
	Data() { cout << "Data<T1, T2>" << endl; }
private:
	T1 _d1;
	T2 _d2;
};
template <class T1>
class Data<T1, int>
{
public:
	Data() { cout << "Data<T1, int>" << endl; }
private:
	T1 _d1;
	int _d2;
};
//两个参数偏特化为指针类型
template <typename T1, typename T2>
class Data <T1*, T2*>
{
public:
	Data() { cout << "Data<T1*, T2*>" << endl; }
private:
	T1 _d1;
	T2 _d2;
};
//两个参数偏特化为引用类型
template <typename T1, typename T2>
class Data <T1&, T2&>
{
public:
	Data(const T1& d1, const T2& d2)
		: _d1(d1)
		, _d2(d2)
	{
		cout << "Data<T1&, T2&>" << endl;
	}
private:
	const T1 & _d1;
	const T2 & _d2;
};
void test2()
{
	Data<double, int> d1; // 调用特化的int版本
	Data<int, double> d2; // 调用基础的模板
	Data<int *, int*> d3; // 调用特化的指针版本
	Data<int&, int&> d4(1, 2); // 调用特化的指针版本
}





int main()
{
	//Test1();
	return 0;
}
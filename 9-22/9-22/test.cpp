
#include <iostream>
using namespace std;

#if 0
#define  MAX 10

int main()
{
	const int a = 10;
	int b = 20;

	int* pa = (int*)&a;   // &a结果的类型 const int*--->表明该地址指向的空间中内容不允许被修改
	*pa = 100;

	printf("%d\n", MAX);  // *&a<==>a 
	printf("%d\n", a);
	printf("%d\n", b);
	printf("%d\n", *&a);  //*&a结果就是a本身--->既然是a本身--->替换为10

	cout << 10 << endl;
	cout << *pa << endl;
	return 0;
}
#endif



#if 0
#define  MAX 10

int main()
{
	// 宏在预处理阶段会被宏体来进行替换

	int a = 100;
	a = MAX;  // 该条语句在预处理阶段已经被修改为：a = 10;
	return 0;
}
#endif

#if 0
int main()
{
	const int a = 10;
	int* pa = (int*)&a;

	printf("%d\n", a);
	printf("%d\n", *pa);
	return 0;
}
#endif


#if 0
int main()
{
	const int a = 10;

	int array[a];
	//a = 10;

	return 0;
}
#endif


#if 0
// 宏的替换发生在预处理阶段----但是宏不会
// const修饰的常量替换发生在编译阶段---->而const修饰的常量是有类型的，因此会参与类型检测


// 宏不会进行类型检测，因为其在预处理阶段已经被替换
#define PI  "3.14"


// pi的类型是double类型的   "3.14"是字符串类型   编译阶段知道类型不匹配而报错
const double pi = "3.14";

// 一般情况下：在C++中 更建议使用const修饰的常量来取代C语言中的宏
// 因为：const修饰的内容已经是常量了，而且会参与类型检测，比宏常量使用起来更安全

int main()
{
	int r = 2;

	double s = PI * r * r;   // 宏替换：s = "3.14" * r * r;

	double s = pi * r * r;
	return 0;
}
#endif


#if 0
#define MAX(a, b) (a > b ? a : b)


int main()
{
	int a = 10;
	int b = 20;

	cout << MAX(++b, a) << endl;  //该条语句在预处理阶段被替换为： cout <<(a > b ? a : b)<< endl;
	cout << MAX("hello", 100) << endl;

	return 0;
}
#endif


#if 0
// 注意：在C++中，一般对于比较短小的函数，建议写成内联函数

inline int Add(int left, int right)
{
	return left + right;
}


inline void TestInline()
{
	for (int i = 0; i < 10; ++i)
	{
		printf("%d\n");
	}

	for (int i = 0; i < 10; ++i)
	{
		printf("%d\n");
	}

	for (int i = 0; i < 10; ++i)
	{
		printf("%d\n");
	}

	for (int i = 0; i < 10; ++i)
	{
		printf("%d\n");
	}

	for (int i = 0; i < 10; ++i)
	{
		printf("%d\n");
	}
}

inline int Fac(int N)
{
	if (N == 0)
		return 1;

	return Fac(N - 1)*N;
}

int main()
{
	int a = 10;
	int b = 20;

	int c = 0;
	c = Add(a, b);  // 在Release模式下，编译器对代码的优化是非常高的，Add的函数调用已经没有了，直接给了30

	// 假设：Add函数中5行代码
	Add(a, b);
	Add(a, b);
	Add(a, b);
	Add(a, b);
	Add(a, b);
	printf("%d\n", c);
	//cout << c << endl;

	// 在Release版本下，main函数中的5行代码直接被优化成：printf("%d\n", 30);

	TestInline();

	Fac(5);
	return 0;
}
#endif


#if 0
#include "Add.h"


int main()
{
	Add(10, 20);
	return 0;
}
#endif


#if 0
inline int Max(int left, int right)
{
	return left > right ? left : right;
}

int main()
{
	int a = 10;
	int b = 20;

	int c = 0;

	c = Max(++b, a);
	cout << c << endl;
	return 0;
}
#endif


// C++11中的语法糖

// auto


#if 0
int Add(int left, int right)
{
	return left + right;
}


int main()
{
	int a = 10;

	auto b = a;
	auto c = 'c';
	auto d = 12.34;
	auto r = Add(10, 20);

	cout << typeid(a).name() << endl;
	cout << typeid(b).name() << endl;
	cout << typeid(c).name() << endl;
	cout << typeid(d).name() << endl;
	cout << typeid(r).name() << endl;

	auto aa;
	return 0;
}
#endif


#if 0
int main()
{
	int a = 10;

	auto* pa1 = &a;
	auto  pa2 = &a;

	// pa1和pa2最终打印的都是int*
	// auto定义指针类型变量时，加*和不加* 没有区别
	cout << typeid(pa1).name() << endl;
	cout << typeid(pa2).name() << endl;


	int b = 10;
	// rb1是新定义了一个整形的变量
	auto rb1 = b;

	// rb2是b的别名
	auto& rb2 = b;

	// 使用auto来定义引用类型变量时，必须要分&的标记
	cout << typeid(rb1).name() << endl;
	cout << typeid(rb2).name() << endl;

	auto  a1 = 10, a2 = 20;

	//auto b1 = 10, b2 = 12.34;
	return 0;
}
#endif


// auto不能作为函数的参数
// 并不是所有的参数都有初始化表达式，因此编译器无法推演a的实际类型
//void TestAuto(auto a)
//{
//	printf("%d", a);
//}

#if 0
int main()
{
	int array1[] = { 1, 2, 3 };


	auto array2[] = { 3, 4, 5 };

	return 0;
}
#endif

#if 0
#include <map>
#include <string>

int main()
{
	std::map<std::string, std::string> m{ { "apple", "苹果" }, { "orange", "橙子" } };

	std::map<std::string, std::string>::iterator it1 = m.begin();
	auto it2 = m.begin();
	return 0;
}
#endif

int main()
{
	int a1[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };

	// 给数组中的每个元素乘2
	for (int i = 0; i < sizeof(a1) / sizeof(a1[0]); ++i)
		a1[i] *= 2;

	for (int i = 0; i < sizeof(a1) / sizeof(a1[0]); ++i)
		cout << a1[i] << " ";
	cout << endl;


	// 在C++11中
	// for循环还可以这么写
	int array[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };

	// 范围for循环
	for (auto& e : array)
		e *= 2;

	for (auto e : array)
		cout << e << " ";
	cout << endl;
	return 0;
}              
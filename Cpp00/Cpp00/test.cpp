
#if 0
#include <stdio.h>

//1.命名空间的定义

//命名空间可以定义变量，可以定义函数，也可以嵌套
//命名空间避免命名冲突或名字污染

//1.普通的命名空间
//namespace关键字 定义命名空间
namespace N1 //N1为命名空间的名称
{
	//命名空间中的内容,可以定义变量或函数
	int a;
	int Add(int left, int right)
	{
		return left + right;
	}
}

//2.命名空间的嵌套定义
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
		int Sub(int x, int y)
		{
			return x + y;
		}
	}
}

//3.同一个工程中允许存在多个相同名称的命名空间
//编译器最后会合成同一个命名空间中
namespace N1
{
	int Mul(int left, int right)
	{
		return left* right;
	}
}
//一个命名空间就定义了一个新的作用域，
//命名空间中的所有内容都局限于该命名空间中


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


//命名空间的三种使用方法
//1.加命名空间名称及作用域限定符
//int main()
//{
//	printf("%d\n", n::a);
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
//3.使用using namespace命名空间名称引入
using namespace N;
int main()
{
	printf("%d\n", N::a);
	printf("%d\n", b);
	printf("%d\n",Add(10, 20));
	return 0;
}

//3.C++的输入&输出
#include <iostream>
using namespace std;// std C++标准库的命名空间
int main()
{
	cout << "Hello World" << endl;
	//cout标准输出（控制台）
	//cin 标准输入（键盘）
	
	int a = 1;
	double d = 1.1;
	//指定格式类型输出
	//printf("%d，%.lf\n", a,d);
	// 自动识别类型
	cout << a << "," << d << endl;
	return 0;
}

//3.1 C++输入
#include <iostream>
using namespace std;

int main()
{
	int a = 0;
	//C语言输入
	//scanf("%d", &a);
	//printf("%d\n");

	double b;
	char c;
	cin >> b >> c;
	cout << b << " " << c << endl;
	return 0;
}

//4.缺省参数
//缺省参数是声明或定义函数时为函数的参数指定一个默认值
//在调用的时候，如果没有指定实参则采用该默认值，否则使用指定的实参
#include <iostream>
using namespace std;

void Test(int a = 0)
{
	cout << a << endl;
}
int main()
{
	Test();  //没有传参时，使用参数的默认值
	Test(2); //传参时，使用指定的实参
	return 0;
}
#endif


#include <iostream>
using namespace std; 
// 全缺省参数
void Test(int a=10, int b = 20, int c=30)
{
	cout << "a= " << a << endl;
	cout << "b= " << b << endl;
	cout << "c= " << c << endl;
}
// 半缺省参数
void Test1(int a, int b = 10, int c = 30)
{
	cout << "a= " << a << endl;
	cout << "b= " << b << endl;
	cout << "c= " << c << endl;
}
int main()
{
	Test1(1);
	Test1(1, 2);
	Test1(1, 2, 3);

	return 0;
}
//1.半缺省参数必须从右往左依次来给出，不能间隔着给
//2.缺省参数不能在函数声明和定义中同时出现
//3.缺省值必须是常量或者全局变量
//4.C语言不支持缺省参数（编译器不支持）


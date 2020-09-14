
#include <iostream>
using namespace std;

//C++复习-入门

//1.命名空间
//使用命名空间的目的是对标识符的名称进行本地化，以避免命名冲突或名字污染
//命名空间定义了一个新的作用域，命名空间中的所有内容都局限于该命名空间中

//namespace N
//{
//	int a = 10;
//	int b = 20;
//	int Add(int left, int right)
//	{
//		return left + right;
//	}
//	int Sub(int left, int right)
//	{
//		return left - right;
//	}
//	namespace M
//	{
//		int c = 30;
//		int d = 40;
//		int Mul(int left, int right)
//		{
//			return left * right;
//		}
//	}
//}
//命名空间使用的三种方式
////1.加命名空间名称及作用域限定符
//int main()
//{
//	printf("%d\n",N:: a);
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
////3.使用using namespace 命名空间名称引入
//using namespace N;
//int main()
//{	
//	printf("%d\n", N::a);
//	printf("%d\n", b);
//	printf("%d\n", Add(10, 20));
//	return 0;
//}

//3.C++输入&输出
//int main()
//{
//	cout << "welcome to shanxi" << endl;
//	return 0;
//}
//int main()
//{
//	int a;
//	char c;
//	double d;
//	cin >> a;
//	cin >> c >> d;
//	cout << a << endl;
//	cout << c << " " << d << endl;
//	return 0;
//}

//4.缺省参数
//缺省参数是声明或定义函数时为函数的参数指定一个默认值。
//如果没有指定实参则采用该默认值，否则使用指定的实参
//void Test1(int a = 0)
//{
//	cout << a << endl;
//}
//int main()
//{
//	Test1(); //没有传参时，使用参数的默认值
//	return 0;
//}
////全缺省参数
//void Test2(int a = 10, int b = 20, int c = 30)
//{
//	cout << "a=" << a << endl;
//	cout << "b=" << b << endl;
//	cout << "c=" << c << endl;
//}
////半缺省参数
//void Test3(int a, int b = 20, int c = 30)
//{
//	cout << "a=" << a << endl;
//	cout << "b=" << b << endl;
//	cout << "c=" << c << endl;
//}
//int main()
//{
//	Test2();
//	Test3(1);
//	return 0;
//}
////半缺省参数必须从右向左依次给出，不能间隔着给
//缺省参数不能在函数声明和定义中同时出现
//如果声明与定义位置同时出现，恰巧两个位置提供的值不同，编译器就无法确定到底该用哪个缺省值
//缺省值必须是常量或者全局变量

//5.函数重载
//C++允许在同一作用域中声明几个功能类似的同名函数，
//这些同名函数的形参列表(参数个数，或类型 或顺序)必须不同
//函数的返回类型可以相同也可以不相同，仅仅返回类型不同不足以成为函数的重载
//int Add(int left, int right)
//{
//	return left + right;
//}
//double Add(double left, double right)
//{
//	return left + right;
//}
//long Add(long left, long right)
//{
//	return left + right;
//}
//int main()
//{
//	cout << Add(10, 20) << endl;
//	cout << Add(2.3, 5.5) << endl;
//	cout << Add(10l, 20l) << endl;
//	return 0;
//}
//C语言没办法支持函数重载，因为同名函数没办法区分。
//而C++是通过函数修饰规则来区分，只要参数不同，修饰出来的名字就不一样，就支持了重载
//函数重载要求参数不同，而跟返回值没有关系

////C++工程中可能需要将某些函数按照C风格来编译，在函数前加extern "C",意思是告诉编译器将该函数按照C语言规则来编译
//extern "C" int Add(int left, int right)
//{
//	return left + right;
//}
//int main()
//{
//	cout << Add(1, 2) << endl;
//	return 0;
//}

//6.引用
//引用不是定义一个新的变量，而是给已存在的变量取一个别名
//编译器不会给引用变量开辟内存空间，它和它引用的变量共同使用同一块内存空间
//int main()
//{
//	int a = 10;
//	char& ra = a;
//	printf("%p\n", &a);
//	printf("%p\n", &ra);
//	return 0;
//}
////引用类型必须和引用实体是同种类型

////引用的特征
//int main()
//{
//	int a = 10;
//	int b = 20;
//	//int& ra; //引用在定义时必须初始化
//	int& ra = a;
//	int& rra = a;//一个变量可以有多个引用
//	//int& rra = b;//引用一旦引用一个实体，再不能引用其它实体
//	printf("%p %p %p\n", &a, &ra, &rra);
//	return 0;
//}

////常引用
//int main()
//{
//	const int a = 10;
//	//int& ra = a;  //编译出错，a为常量
//	const int& ra = a;
//	//int& b = 10;//编译出错，b为常量
//	const int& b = 10;
//	double d = 12.34;
//	//int& rd = d;//编译出错，类型不同
//	const int& ra = d;
//	return 0;
//}

//引用的使用场景
////1.做参数
//void Swap(int& left, int& right)
//{
//	int tmp = left;
//	left = right;
//	right = tmp;
//}
////2.做返回值
//int& Count()
//{
//	static int n = 0;
//	n++;
//	return n;
//}

int& add(int a, int b)
{
	int c = a + b;
	return c;
	//return a + b// 编译报错  a+b不是左值 （表达式 常量 没有左值）
}
int& Count()
{
	static int n = 0;
	n++;

	return n;
}
int main()
{
	int& ret = add(1, 2);//不能返回局部变量的引用。主要原因是局部变量会在函数返回后被销毁，
	//因此被返回的引用就成为了"无所指"的引用，程序会进入未知状态。
	int& r = Count();
	cout << r << endl;
	cout << r << endl;
	cout << r << endl;
	return 0;
	//如果函数返回时，出了函数作用域，如果返回对象还未还给系统，则可以使用引用返回，
	//如果已 经还给系统了，则必须使用传值返回。
}


#include <iostream>
using namespace std;
//函数重载喝引用

#if 0
// 《程序员自我修养》
// vs是一个集成开发环境，当点击生成或者重新生成时：预处理--->编译-->汇编--->链接--->生成可执行程序
// C/C++编译器对这些源文件是单独进行编译器的
int Add(int left, int right);    //_Add
//{
//	return left + right;
//}


double Add(double left, double right);  // _Add
//{
//	return left + right;
//}


int main()
{
	Add(10, 30);
	Add(1.2, 3.4);
	return 0;
}
#endif


#if 0
//int Add(int left, int right);    //C++编译器将int Add(int left, int right)修改为：?Add@@YAHHH@Z
//{
//	return left + right;
//}


//double Add(double left, double right);  //C++编译器double Add(double left, double right)修饰为：?Add@@YANNN@Z
//{
//	return left + right;
//}


double Add(int left, double right);

int main()
{
	//Add(10, 30);
	Add(1, 3.4);
	return 0;
}
#endif


#if 0
//
int Add(int left, int right)    //C++编译器将int Add(int left, int right)修改为：?Add@@YAHHH@Z
{
	return left + right;
}


double Add(double left, double right)  //C++编译器double Add(double left, double right)修饰为：?Add@@YANNN@Z
{
	return left + right;
}



int main()
{
	Add(10, 30);
	Add(1.2, 3.4);
	return 0;
}

#endif


#if 0
extern "C" int Add(int left, int right);    //C++编译器将int Add(int left, int right)修改为：?Add@@YAHHH@Z
//{
//	return left + right;
//}
#endif

#if 0
// 如果C++和C语言混合起来编程，如何搞？--- 采用条件编译可以处理

extern "C"{
	int Add1(int left, int right);  // _Add1
	int Add2(int left, int right);  // _Add2
	int Add3(int left, int right);  // _Add3
	int Add4(int left, int right);  // _Add4
}


void TestFunc(int a = 10)
{
	cout << "void TestFunc(int)" << endl;
}
void TestFunc()
{
	cout << "void TestFunc()" << endl;
}

int main()
{
	TestFunc(10);
	TestFunc();
	//Add(10, 30);
	return 0;
}

int _Add(int left, int right);

int main()
{
	_Add(1, 2);  // __Add
	return 0;
}
#endif

#if 0
// 传值：不能通过形参改变外部的实参，因为形参是实参的一份拷贝
void Swap(int left, int right)
{
	int temp = left;
	left = right;
	right = temp;
}

// 传地址：如果想要通过形参改变外部的实参
// 问题：指针可能不安全---每次使用时必须要对指针判空
//      代码的可读性比较差
void Swap(int* left, int* right)
{
	int temp = *left;
	*left = *right;
	*right = temp;
}


// 大佬想：能不能够继续按照值的方式来传参，在函数实现中也按照值的方式来操作，但是也想到达到指针类似的效果
/*
void Swap(int left, int right)
{
int temp = left;
left = right;
right = temp;
}

如果left和right能够是实参的别名就好了

别名：另外一个名字
*/
int main()
{
	int a = 10;
	int b = 20;

	Swap(a, b);

	Swap(&a, &b);
	return 0;
}
#endif

#if 0
int main()
{
	int a = 10;

	// 要给a区别名，称为ra
	// &出现在类型之后，表示引用的标记
	int &ra = a;

	ra = 100;
	return 0;
}
#endif


//int main()
//{
//	int a = 10;
//	int& ra = a;
//
//	// ra就是a的别名
//	ra = 100;
//
//	// 引用类型必须与其实体是同种类型的
//	// 实体是int类型的，别名也必须是int类型的
//	//double& rra = a;
//	return 0;
//}


#if 0
int main()
{
	int a = 10;
	// int& ra;  编译失败：引用类型变量在定义时必须要初始化---否则编译器就不知道ra到底是谁的别名
	int& ra = a;


	// 一个变量可以有多个引用---->一个实体可以有多个别名
	int& ra1 = a;
	int& ra2 = a;
	int& ra3 = a;
	int& ra4 = ra;  // ra就是a

	ra = 100;
	ra1 = 200;
	ra2 = 300;
	ra3 = 400;

	// 引用一旦引用一个实体后，再不能引用其他的实体了
	int b = 10;

	int& rb = b;

	// rb已经是b的别名了，让rb变成a的别名，能不能做到？
	rb = a;   // 并不是让rb成为a的别名，而是用a给rb赋值

	// &rb = a;  编译报错，&rb--->对rb取地址int* = int
	return 0;
}
#endif


#if 0
int main()
{
	// 引用一旦引用一个实体，再不能引用其他的实体
	// 该引用在其生命周期内，只能和一个实体结合

	// 问题：引用和其引用的实体的生命周期是一样的?

	int a = 10;
	int& ra = a;

	if (true)
	{
		int& rra = a;
		rra = 100;
	}

	// rra = 1000;
	return 0;
}
#endif

#if 0
// 常引用
int main()
{
	// a是一个常量，a不能够被修改的
	const int a = 10;
	//a = 100;

	// 如果ra可以引用a，那么我们就可以通过ra来修改a
	//int& ra = a;  // 编译失败
	const int& ra = a;

	//ra = 200;

	///////////////////////////////////////
	const int& b = 10;



	return 0;
}
#endif


#if 0
int main()
{
	int a = 10;
	const int& ra = a;

	a = 100;


	// 思考下？
	double d = 12.34;
	const int& rd = d;  // rd已经是d的别名了--rd是int类型的，应该rd将d中整形部分拿到了

	d = 34.56;

	cout << rd << endl;

	return 0;
}
#endif


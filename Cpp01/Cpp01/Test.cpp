

#include <iostream>
using namespace std;
#if 0

// 函数重载
int Add(int left, int right)
{
	return left + right;
}

double Add(double left, double right)
{
	return left + right;
}

long Add(long left, long right)
{
	return left + right;
}

short Add(short left, int right)
{
	return left + right;
}

short Add(int left, short right)
{
	return left + right;
}

void TestFunc(int a = 10)
{
	//cout << "void TestFunc(int)" << endl;
}

void TestFunc(int a)
{
	//cout << "void TestFunc(int)" << endl;
}

int main()
{
	Add(10, 20);
	Add(10.0, 20.0);
	Add(10L, 20L);

	return 0;
}


int main()
{
	int a = 0;
	int& ra = a;
	cout << &a << endl;
	cout << &ra << endl;

	int& b = a;
	cout << &b << endl;
	int& c = b;
	cout << &c << endl;

	//int& d;

	int x = 1;
	c = x; // 把x的值赋值给c，并不是c变成x的别名
	cout << &c << endl;
	cout << &x << endl;

	return 0;
}

int main()
{
	const int a = 10;
	// 权限放大 只读->可读可写
	//int& b = a; // 不行 a自己都不能改变，b是我别名还可以改变？->不行
	const int& b = a;

	int c = 20;
	int& d = c;
	// 权限缩小 可读可写->只读
	const int& e = c; // 可以 c自己可以读可以改变，e只能读，不能改变  ->行
		 
	return 0;
}

int main()
{
	int i = 0;
	double d = i; // 隐式类型的转换
	const double& rd = i;

	return 0;
}
#endif

//void SwapC(int* pa, int* pb);
void Swap(int& ra, int& rb)
{
	int c = ra;
	ra = rb;
	rb = c;
}

int main()
{
	int a = 0, b = 2;
	Swap(a, b);

	return 0;
}
//C++的类型转换

#include <iostream>
using namespace std;

class A
{
public:
	virtual void f()
	{}

	int _a;
};

class B : public A
{
public:
	int _b;
};


//A* pa = &a;
//f_cast(pa);
//
//pa = &b;
//f_cast(pa);

void f_cast(A* pa)
{
	// 如果想区分pa是指向父类，还是子类对象？
	// 如果pa是指向子类对象，则转换成功，
	// 如果pa指向父类对象则转换失败返回nullptr 
	B* pb = dynamic_cast<B*>(pa);
	//B* pb = (B*)pa;
	if (pb != nullptr)
	{
		cout << "转换成功：pa指向子类对象" << endl;
		pb->_a = 1;
		pb->_b = 2;
	}
	else
	{
		cout << "转换失败：pa指向父类对象" << endl;
	}
}

int x10()
{
	int i = 1;
	double d = 8.88;
	i = d; // c语言支持相近类型的隐式类型转换 (相近类型，也就是意义相似的类型)
	cout << i << endl;

	int* p = nullptr;
	p = (int*)i; // c语言支持相近类型的强制类型转换 (不相近类型，也就是意义差别很大的类型)
	cout << p << endl;

	// C++ 兼容C语言留下来的隐式转换和显示转换，但是C++觉得C语言做得不规范，C++想规范一下
	// 标准C++为了加强类型转换的可视性，引入了四种命名的强制类型转换操作符
	// static_cast、reinterpret_cast、const_cast、dynamic_cast
	d = static_cast<double>(i);     // 对应c语言隐式类型转换 （相近类型）
	p = reinterpret_cast<int*>(i);  // 对应c语言大部分强制类型转换（不相近类型）

	volatile const int ci = 10;
	//const int ci = 10;
	int* pi = const_cast<int*>(&ci); // 对应c语言强制类型转换中去掉const属性的（不相近类型）
	//int* pi = (int*)&ci;
	*pi = 20;
	cout << *pi << endl;
	cout << ci << endl; // 这里打印是10是因为ci存储的内存被改了，但是ci被放进了寄存器，这里去寄存器中取，还是10.本质这是由于编译器对const对象存取优化机制导致。
	// 想要禁止编译器做这个优化，每次都到内存中去取值，就把volatile加上

	A a;
	B b;

	// C++中子类对象可以赋值给父类的对象、指针、引用，这个过程中会发生切片，这个过程是
	// 语法天然支持的，这个叫向上转换，都可以成功。

	// 如果是父类的指针或者引用，传给子类的指针，这个过程叫向下转换，这个过程有可能能成功
	// 要看具体情况。
	// 最后需要注意的是：dynamic_cast向下转换只能针对继承中的多态类型(父类必须包含虚函数)

	// 因为dynamic_cast如何识别父类的指针是指向父类对象还是子类对象的呢？dynamic_cast的原理
	// dynamic_cast通过去虚表的上方存储的标识信息，来判断指向父类对象还是子类对象。
	A* pa = &a;
	f_cast(pa);

	pa = &b;
	f_cast(pa);

	return 0;
}

// 总结一下：尽量少用类型转换，如果要用尽量规范一点，且知道转换后会有什么影响

class AA
{
public:
	//AA(int a)
	explicit AA(int a)
	{
		cout << "AA(int a)" << endl;
	}

	//AA(int a1, int a2)
	explicit AA(int a1, int a2)
	{
		cout << "AA(int a1, int a2)" << endl;
	}

	AA(const AA& a)
	{
		cout << "AA(const AA& a)" << endl;
	}
private:
	int _a1;
	int _a2;
};

int main()
{
	AA aa1(1);

	// 隐式转换-> A tmp(1); A a2(tmp)，再优化成直接构造
	AA aa2 = 1;
	AA aa3 = { 1, 2 }; // C++11
}
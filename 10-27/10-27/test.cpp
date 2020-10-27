
#include<iostream>
using namespace std;

#if 0
//C++为什么要重新设计一套动态内存管理的方式
class Test
{
public:
	Test(int t = 0)
		:_t(t)
	{
		cout << "Test(int):" << this << endl;
	}
	~Test()
	{
		cout << "~Test():" << this << endl;
	}
private:
	int _t;
};
int main()
{
	Test t1(100);//会调用构造函数
	//malloc不会主动调用构造函数
	Test* pt = (Test*)malloc(sizeof(Test));

	free(pt);
	return 0;
}
#endif

#if 0
class Test
{
public:
	Test(int t = 0)
		: _t(t)
	{
		cout << "Test(int):" << this << endl;
	}

	~Test()
	{
		cout << "~Test():" << this << endl;
	}

private:
	int _t;
};

int main()
{
	Test* pt1 = new Test(100);//会调用构造函数
	Test* pt2 = (Test*)malloc(sizeof(Test));

	delete pt1;//会调用析构函数
	free(pt2);
	return 0;
}


int main()
{
	//申请单个类型的空间
	int* p1 = new int;
	int* p2 = new int(10); //对申请的空间进行初始化

	int arr[10];

	//申请一段连续的空间
	int* p3 = new int[10];
	int* p4 = new int[10]{1, 2, 3, 4, 5, 6, 7, 8, 9, 0};//对申请的连续空间进行初始化

	delete p1;
	delete p2;
	delete[] p3;
	delete[] p4;
	return 0;
}
#endif

#if 0
//对于内置类型空间的申请和释放
int main()
{
	int* p1 = (int*)malloc(sizeof(int)* 10);
	int* p2 = (int*)malloc(sizeof(int)* 10);

	int* p3 = new int;
	int* p4 = new int;

	int* p5 = new int[10];
	int* p6 = new int[10];

	delete p1;
	delete[] p2;

	free(p3);
	delete[] p4;

	free(p5);
	delete p6;

	// windows提供的一个api函数，用来进行简单的内存泄漏检测
	//_CrtDumpMemoryLeaks();
	return 0;
}

class Test
{
public:
	Test(int t = 0)
		:_t(t)
		, _p(new int)
	{
		cout << "Test(int):" << this << endl;
	}
	~Test()
	{
		cout << "~Test()" << this << endl;
	}
private:
	int _t;
	int* _p;
};

int main()
{
	Test* p1 = (Test*)malloc(sizeof(Test)* 10);
	Test* p2 = (Test*)malloc(sizeof(Test)* 10);
	Test* p3 = new Test;
	Test* p4 = new Test;
	Test* p5 = new Test[10];
	Test* p6 = new Test[10];

	delete p1;
	delete[] p2;

	free(p3);
	delete[] p4;

	free(p5);
	delete p6;

	// windows提供的一个api函数，用来进行简单的内存泄漏检测
	//_CrtDumpMemoryLeaks();
	return 0;
}
#endif

#if 0
void* operator new(size_t size, char* filename, char* funcname, size_t lineNo)
{
	cout << filename << "-" << funcname << "-" << lineNo << ":" << size << endl;
	return malloc(size);
}


#define new new(__FILE__, __FUNCDNAME__,__LINE__)
int main()
{
	int* p = new int;

	delete p;
	return 0;
}
#endif

class Test
{
public:
	Test(int t = 0)
		: _t(t)
		, _p(new int)
	{
		cout << "Test(int):" << this << endl;
	}

	~Test()
	{
		delete _p;
		cout << "~Test():" << this << endl;
	}

private:
	int _t;
	int* _p;
};


int main()
{
	// 注意：malloc申请出来的空间不能将其称作为对象
	// 因为：malloc在申请空间期间不会调用构造函数
	
	Test* pt = (Test*)malloc(sizeof(Test));
	// 现在需要将pt指向的堆空间变成一个对象
	// 如果能够在pt指向的空间上执行构造函数即可

	// placement-new 定位new表达式
	// 在已经开辟好的空间上执行构造函数

	new(pt)Test(100);


	pt->~Test();
	free(pt);
	return 0;
}










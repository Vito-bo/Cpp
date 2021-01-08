
#include <iostream>
using namespace std;


#if 0
// C++为什么不能使用C语言中的动态内存管理方式
class Test
{
public:
	Test(int t = 0)
		:_t(t)
	{
		cout << "Test():" << this << endl;
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
	//Test t1(10);

	// malloc没有调用构造函数
	Test* pt = (Test*)malloc(sizeof(Test));
	
	// free没有调用析构函数清理资源
	free(pt);
	return 0;
}
#endif



// new  和  malloc 是C++中的关键字，也可以称为 操作符
int main()
{
	// 申请单个类型
	int* p1 = new int;
	int* p2 = new int(10); //对申请的空间进行初始化

	int array[10];  // new 之后直接跟的就是对象的类型
	// 申请一段连续的空间
	int* p3 = new int[10];
	int* p4 = new int[10]{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 0};

	delete p1;
	delete p2;

	delete[] p3;
	delete[] p4;

	return 0;
}

#if 0
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
	// new 会调用构造函数
	Test* pt1 = new Test(10);
	Test* pt2 = (Test*)malloc(sizeof(Test));

	// delete会调用析构函数
	delete pt1;
	free(pt2);
	return 0;
}
#endif

#if 0
// 对于内置类型空间的申请和释放：new/delete  new[]/delete[] malloc/free
// 匹配起来使用，也不会有任何的问题---既不会崩溃也不会发生内存泄漏
// 但是：注意一定要不按照该种方式使用
int main()
{
	int* p1 = (int*)malloc(sizeof(int)* 10);
	int* p2 = (int*)malloc(sizeof(int)* 10);

	delete p1;
	delete[] p2;

	int* p3 = new int;
	int* p4 = new int;

	free(p3);
	delete[] p4;

	// windows提供的一个api函数，用来进行简单的内存泄漏检测
	_CrtDumpMemoryLeaks();

	return 0;
}
#endif
#if 0
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
		delete _p;
		cout << "~Test():" << this << endl;
	}
private:
	int _t;
	int* _p;
};

int main()
{
	//Test* p1 = (Test*)malloc(sizeof(Test)* 10);
	//Test* p2 = (Test*)malloc(sizeof(int)* 10);
	Test* p3 = new Test;
	//Test* p4 = new Test[];

	//delete p1;
	//delete[] p2;
	//free(p3);
	//delete[] p4;

	// windows提供的一个api函数，用来进行简单的内存泄漏检测
	_CrtDumpMemoryLeaks();

	return 0;
}
#endif

#if 0
class Test
{
public:
	Test(int t = 0)
		:_t(t)
		, _p(new int)
	{
		cout << "Test(int):" << this << endl;
	}

	/*~Test()
	{
		delete _p;
		cout << "~Test()" << this << endl;
	}*/
private:
	int _t;
	int* _p;
};
int main()
{
	Test* pt = new Test[10];
	// 对于自定义类型会调用自己的构造函数进行初始化，调用析构函数进行销毁
	delete[] pt;

	return 0;
}
#endif

#if 0
// 重载 new
void* operator new(size_t size, char* filename, char* funcname, size_t lineNo)
{
	cout << filename << "-" << funcname << "-" << lineNo << ":" << size << endl;
	return malloc(size);
}

#define new new(__FILE__, __FUNCDNAME__, __LINE__)

int main()
{
	int* p = new int;
	delete p;
	return 0;
}
#endif


#if 0
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
#endif

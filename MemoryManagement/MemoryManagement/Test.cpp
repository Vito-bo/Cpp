#include <iostream>
using namespace std;

//void Test()
//{
//	int* p1 = (int*)malloc(sizeof(int));
//	free(p1);
//	// 1.malloc/calloc/realloc的区别是什么？
//	int* p2 = (int*)calloc(4, sizeof (int));
//	int* p3 = (int*)realloc(p2, sizeof(int)* 10);
//	// 这里需要free(p2)吗？
//	free(p3);
//}

//void Test()
//{
//	//动态申请一个int类型的空间
//	int* ptr1 = new int;
//	//动态申请一个int类型的空间并初始化为10
//	int* ptr2 = new int(10);
//	//动态申请10个int类型的空间
//	int* ptr3 = new int[10];
//
//	delete ptr1;
//	delete ptr2;
//	delete[] ptr3;
//}
//new和delete操作自定i类型
class Test
{
public:
	Test()
		: _data(0)
	{
		cout << "Test():" << this << endl;
	}
	~Test()
	{
		cout << "~Test():" << this << endl;
	}
private:
	int _data;
};
void Test2()
{
	//申请单个Test类型的空间
	Test* p1 = (Test*)malloc(sizeof(Test));
	free(p1);

	//申请10个Test类型的空间
	Test* p2 = (Test*)malloc(sizeof(Test)* 4);
	free(p2);
}

void Test3()
{
	//申请单个Test类型的对象
	Test* p1 = new Test;

	//申请10个Test类型的对象
	Test* p2 = new Test[10];
	delete[] p2;
}
//在申请自定义类型的空间时，new会调用构造函数，delete会调用析构函数，而malloc和free不会。

struct ListNode
{
	ListNode* _next;
	ListNode* _prev;
	int _data;
	void* operator new(size_t n)
	{ 
		void* p = nullptr;
		p = allocator<ListNode>().allocate(1);
		cout << "memory pool allocate" << endl;
		return p;
	}
	void operator delete(void* p)
	{
		allocator<ListNode>().deallocate((ListNode*)p, 1);
		cout << "memory pool deallocate" << endl;
	}
};
class List
{
public:
	List()
	{
		_head = new ListNode;
		_head->_next = _head;
		_head->_prev = _head;
	}
	~List()
	{
		ListNode* cur = _head->_next;
		while (cur != _head)
		{
			ListNode* next = cur->_next;
			delete cur;
			cur = next;
		}
		delete _head;
		_head = nullptr;
	}
private:
	ListNode* _head;
};
int main()
{
	List l;
	return 0;
}
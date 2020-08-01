//list的介绍及使用
//list底层是双向链表结构
//forward_list是单链表，只能超前迭代

#include <iostream>
#include <list>
#include <vector>
using namespace std;
//
////1.list的构造
//int main()
//{
//	list<int> l1;        //构造空的l1
//	list<int> l2(4, 100);//l2中放4个值为100的元素
//	list<int> l3(l2.begin(), l2.end());//用l2的[begin(),l2.end()]左闭右开区间构造l3
//	list<int> l4(l3);    //用l3拷贝构造l4
//
//	//以数组为迭代器构造l5
//	int arr[] = { 16, 17, 5, 19 };
//	list<int> l5(arr, arr + sizeof(arr) / sizeof(arr[0]));
//
//	//用迭代器方式打印l5中的元素
//	list<int>::iterator it = l5.begin();
//	while (it != l5.end()){
//		cout << *it << " ";
//		it++;
//	}
//	cout << endl;
//
//	//C++11范围for的方式遍历
//	for (auto& e : l5){
//		e *= 2;
//		cout << e << " ";
//	}
//	cout << endl;
//	return 0;
//}

////list iterator的使用
////begin与end为正向迭代器，对迭代器执行++操作，迭代器向后移动
////rbegin与rend为反向迭代器，对迭代器进行++操作，迭代器向前移动
//void print_list(const list<int>& l)
//{
//	// 注意这里调用的是list的 begin() const，返回list的const_iterator对象
//	for (list<int>::const_iterator it = l.begin(); it != l.end(); ++it)
//	{
//		cout << *it << " ";
//		 //*it = 10; //编译不通过
//	}
//	cout << endl;
//}
//int main()
//{
//	int array[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
//	list<int> l(array, array + sizeof(array) / sizeof(array[0]));
//	//使用正向迭代器正向打印list中的元素
//	list<int>::iterator it = l.begin();
//	while (it != l.end()){
//		cout << *it << " ";
//		it++;
//	}
//	cout << endl;
//	//使用反向迭代器打印List中的元素
//	list<int>::reverse_iterator rit = l.rbegin();
//	while (rit != l.rend()){
//		cout << *rit << " ";
//		rit++;
//	}
//	cout << endl;
//
//	print_list(l);
//	cout << l.front() << endl;
//	cout << l.back() << endl;
//	
//	l.push_front(3);
//	for (auto& e : l){
//		cout << e << " ";
//	}
//	cout << endl;
//	l.pop_front();
//	for (auto& e : l){
//		cout << e << " ";
//	}
//	cout << endl;
//
//	l.push_back(7);
//	for (auto& e : l){
//		cout << e << " ";
//	}
//	cout << endl;
//	l.pop_back();
//	for (auto& e : l){
//		cout << e << " ";
//	}
//	cout << endl;
//	return 0;
//}

////list modifiers
//void PrintList(list<int>& l)
//{
//	for (auto& e : l){
//		cout << e << " ";
//	}
//	cout << endl;
//}
//int  main()
//{
//	//int arr1[] = { 1, 2, 3 };
//	//list<int> L(arr1, arr1 + sizeof(arr1) / sizeof(arr1[0]));
//
//	////获取链表中的第二个节点
//	//auto pos = ++L.begin();
//	//cout << *pos << endl;
//	////在pos位置前插入值为4的元素
//	//L.insert(pos, 4);
//	//PrintList(L);
//
//	////在pos前插入5个值为5的元素
//	//L.insert(pos, 5, 5);
//	//PrintList(L);
//
//	////在pos前插入[v.begin(),v.end()]区间中的元素
//	//vector<int> v{ 7, 8, 9 };
//	//L.insert(pos, v.begin(), v.end());
//	//PrintList(L);
//
//	////删除pos位置上的元素
//	//L.erase(pos);
//	//PrintList(L);
//
//	////删除list中的[begin,end)区间中的元素，即删除list中的所有元素
//	//L.erase(L.begin(), L.end());
//	//PrintList(L);
//
//	//用数组来构造list
//	int arr[] = { 1, 2, 3 };
//	list<int> l1(arr, arr + sizeof(arr) / sizeof(arr[0]));
//	PrintList(l1);
//	
//	//交换l1和l2中的元素
//	list<int> l2;
//	l1.swap(l2);
//	PrintList(l1);
//	PrintList(l2);
//
//	//将l2中的元素清空
//	l2.clear();
//	cout << l2.size() << endl;
//
//	return 0;
//}

//list的迭代器失效
void TestListIterator1()
{
	int array[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
	list<int> l(array, array + sizeof(array) / sizeof(array[0]));
	auto it = l.begin();
	while (it != l.end())
	{
		// erase()函数执行后，it所指向的节点已被删除，因此it无效，在下一次使用it时，必须先给其赋值
		l.erase(it);
		++it;
	}
}
// 改正
void TestListIterator()
{
	int array[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
	list<int> l(array, array + sizeof(array) / sizeof(array[0]));
	auto it = l.begin();
	while (it != l.end())
	{
		l.erase(it++); // it = l.erase(it);
	}
}

int main()
{
	//TestListIterator1();
	TestListIterator();
	return 0;
}

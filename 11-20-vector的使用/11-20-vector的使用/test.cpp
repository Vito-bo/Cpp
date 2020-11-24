
#include <iostream>
#include <vector>
using namespace std;

#if 0
class Date
{
public:
	Date(int year = 2000, int month = 1, int day = 1)
		:_year(year)
		, _month(month)
		, _day(day)
	{
		cout << "Date(int, int, int):" << this << endl;
	}

private:
	int _year;
	int _month;
	int _day;
};
// 构造和遍历
void Test1()
{
	vector<int> v1;
	vector<int> v2(10, 5);
	vector<int> v3(10);
	vector<Date> v4(10);

	// 区间类型的构造
	int arr[] = { 1, 2, 3, 4, 5 };
	vector<int> v5(arr, arr + sizeof(arr) / sizeof(arr[0]));
	// 拷贝构造
	vector<int> v6(v5);

	// C++11新增加
	vector<int> v7{ 1, 2, 3, 4, 5 };

	// 遍历方式
	for (size_t i = 0; i < v2.size(); i++)
		cout << v2[i] << " ";
	cout << endl;

	// C++11 范围for遍历
	for (auto e : v3)
		cout << e << " ";
	cout << endl;

	// 迭代器方式遍历
	vector<int>::iterator it = v7.begin();
	while (it != v7.end())
	{
		cout << *it << " ";
		it++;
	}
	cout << endl;

}

// 容量操作
void Test2()
{
	vector<int> v{ 1, 2, 3, 4, 5, 6, 7, 8};
	cout << v.size() << endl;  
	cout << v.capacity() << endl;
	

	v.resize(3);
	cout << v.size() << endl;
	cout << v.capacity() << endl;

	v.resize(11);
	cout << v.size() << endl;
	cout << v.capacity() << endl;

	v.resize(20, 6);
	cout << v.size() << endl;
	cout << v.capacity() << endl;

	v.resize(10);
	cout << v.size() << endl;
	cout << v.capacity() << endl;

	v.reserve(5);
	cout << v.size() << endl;
	cout << v.capacity() << endl;

	v.reserve(17);
	cout << v.size() << endl;
	cout << v.capacity() << endl;

	v.reserve(30);
	cout << v.size() << endl;
	cout << v.capacity() << endl;

}

// 元素访问
void Test3()
{
	vector<int> v{ 1, 2, 3, 4, 5 };
	cout << v[0] << endl;
	cout << v.front() << endl;
	cout << v.back() << endl;

	v[0] = 100;
	v.back() = 10;
	v.front() = 20;
	v.at(3) = 200;
	cout << v[0] << endl;
	cout << v.front() << endl;
	cout << v.back() << endl;
	cout << v.at(3) << endl;

	// 不能越界
	//v[5] = 90;
	//v.at(5) = 99;
}

// push_back
// vecotr的扩容机制
// 1.vector的扩容机制 vs:1.5倍 linux;2倍
// 2.尽量避免一遍插入一遍扩容
//	注意：一般大概知道存储多少个元素，提前将空间预留好
void Test4()
{
	vector<int> v;
	v.reserve(100);
	size_t capacity = v.capacity();
	for (size_t i = 0; i < 100; i++)
	{
		v.push_back(i);
		if (capacity != v.capacity())
		{
			cout << capacity << endl;
			capacity = v.capacity();
		}
	}
}

void TestPushBack()
{
	Date d(2020, 11, 20);
	vector<Date> v;

	// 注意：push_back()不是直接将d尾插到vector中
	// 实际上插入的是d的一份拷贝
	v.push_back(d);
	cout << &v << endl;
}
#endif 


// 插入和删除
void Test5()
{
	vector<int> v{ 1, 2, 3, 4, 5 };
	v.insert(v.begin(), 0);

	auto pos = find(v.begin(), v.end(), 3);
	if (pos != v.end())
		v.insert(pos, 4, 6);

	//v.insert(v.begin() + 1, v.begin(), v.end());

	v.erase(v.begin());
	v.erase(v.begin(), v.begin() + 5);
	v.erase(v.begin(), v.end()); // clear()

}

// 迭代器失效：扩容导致
void Test6()
{
	vector<int> v{ 1, 2, 3 };
	cout << v.size() << endl;
	cout << v.capacity() << endl;

	auto it = v.begin();
	v.assign(10, 5);
	//assign() 函数要么将区间[start, end)的元素赋到当前vector,
	//或者赋num个值为val的元素到vector中.这个函数将会清除掉为vector赋值以前的内容.

	it = v.begin();
	while (it != v.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;

}

// 迭代器失效；删除导致
void Test7()
{
	vector<int> v{ 1, 2, 3, 4, 5 };
	auto it = v.begin();
	v.erase(it);
	
	// it = v.begin();
	cout << *it << endl;
}
//迭代器失效：交换导致
void Test8()
{
	vector<int> v1{ 1, 2, 3 };
	vector<int> v2{ 1, 2, 3, 4, 5 };

	auto it1 = v1.begin();
	auto it2 = v2.begin();

	v1.swap(v2);
	// it1 = v1.begin();
	while (it1 != v1.end())
	{
		cout << *it1 << " ";
		++it1;
	}
	cout << endl;
}
// 总结：迭代器失效：对于序列式容器，删除当前的iterator会使后面所有元素的iterator都失效，
// 因为顺序容器内存是连续分配的删除一个元素导致后面所有元素会向前移动一个位置（删除了一个元素，该元素后面的所有元素都要移动位置，所以it++，指向的是未知内存）
// 解决方法：在有可能引起迭代器失效的位置之后，在使用迭代器时重新给该迭代器赋值

// 需求：使用迭代器将vector中的所有元素删除掉
void Test9()
{
	vector<int> v{ 1, 2, 3, 4, 5 };
	auto it = v.begin();
	while (it != v.end())
	{
		it = v.erase(it); //erase()：返回被删除元素的下一个位置
		// ++it;
	}
}


// vector常见使用场景：构造矩阵
void Test10()
{
	// 5*6
	vector<vector<int>> vv;
	vv.resize(5);
	for (int i = 0; i < vv.size(); ++i)
		vv.resize(6);
	for (int i = 0; i < vv.size(); ++i)
	{
		for (int j = 0; j < vv[i].size(); ++j)
			vv[i][j] = j + 1;
	}
	
	// 5*6
	vector<vector<int>> vv(5, vector<int>(6));

	for (size_t i = 0; i < vv.size(); ++i)
	{
		for (size_t j = 0; j < vv[i].size(); ++j)
		{
			vv[i][j] = j + 1;
		}
	}

	// 5*6
	vector<vector<int>> vv(5, vector<int>{1, 2, 3, 4, 5, 6});
}

int main()
{
	Test10();
	return 0;
}
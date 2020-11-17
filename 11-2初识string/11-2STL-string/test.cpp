#include<iostream>
#include<assert.h>
#include <string>
using namespace std;

// string初识

#if 0
// 字符串：就是以'\0'作为结尾的特殊字符数组
// C语言中没有字符串类型
// 定义字符串时，必须保证字符串最后一个元素为'\0'
// C语言中表示字符串的方法：是将字符串作为字符数组来处理的，字符串是逐个放到数组元素中的。

int main()
{
	//1.如果字符串所含元素中没有'\0',则字符串长度为字符串实际长度+1
	char ch1[6] = { 'h', 'e', 'l', 'l', 'o' };
	char ch2[] = { 'h', 'e', 'l', 'l', 'o', '\0' };
	char ch3[] = "hello";
	return 0;
}
C++中专门提供了一些用来进行字符串操作的库函数--<string.h>
strcpy / strlen / strcmp / strcat / strchr..一定要会模拟实现
用户在进行字符串操作时，需要自己管理空间
C++中字符串类型--string类
string类中的接口分为以下几个模块：
构造与析构/迭代器/容量相关/元素访问的/修改/

#endif



void Test1()
{
	string s("welcome to xian lintong");
	
	//size和length都是求字符串的有效长度
	cout << s.size() << endl;
	cout << s.length() << endl;

	//capacity求底层空间总的大小
	cout << s.capacity() << endl;

	//检测该字符串是否为空（的字符串）
	if (!s.empty())
		cout << "not empty" << endl;
	else
		cout << "empty" << endl;

	// 将s中有效字符清空
	s.clear();
	cout << s.size() << endl;
	cout << s.capacity() << endl; //空间容量不变

	if (!s.empty())
		cout << "not empty" << endl;
	else
		cout << "empty" << endl;
}
void Test2()
{
	string s("hello");
	cout << s << endl;
	cout << s.size() << endl;
	cout << s.capacity() << endl;

	// resize调整字符串大小
	// 如果n小于当前字符串长度，则将当前值缩短到n个字符，并删除第n个字符之外的字符。
	// 如果n大于当前字符串，则通过在尾部插入任意数量的字符来扩充当前字符串到达n的大小
	s.resize(10, '!');
	cout << s << endl;
	cout << s.size() << endl;
	cout << s.capacity() << endl;

	s.resize(20, '*');
	cout << s << endl;
	cout << s.size() << endl;
	cout << s.capacity() << endl;

	s.resize(34);
	cout << s << endl;
	cout << s.size() << endl;
	cout << s.capacity() << endl;

	// resize只是将有效元素个数缩减到n个
	// 底层容量没有发生变化
	s.resize(29);
	cout << s << endl;
	cout << s.size() << endl;
	cout << s.capacity() << endl;

	s.resize(10);
	cout << s.size() << endl;
	cout << s.capacity() << endl;
}

void Test3()
{
	//sizeof(string)和字符串的长度是无关的，在一个系统中所有的sizeof(string)是一个固定值，这个和编译器相关
	//cout << sizeof(string) << endl;//28

	string s("hello");
	cout << s.size() << endl;
	cout << s.capacity() << endl;

	// reserve调整字符串容量以适应变化的大小，使其长度最多为n个字符
	// 如果n大于当前字符串容量，该函数将使容器容量增加到n个字符(或更多)
	// 不影响字符串长度，也不能更改其内容。
	s.reserve(10);
	cout << s.size() << endl;
	cout << s.capacity() << endl;

	s.reserve(18);
	cout << s.size() << endl;
	cout << s.capacity() << endl;

	s.reserve(30);
	cout << s.size() << endl;
	cout << s.capacity() << endl;

	s.reserve(50);
	cout << s.size() << endl;
	cout << s.capacity() << endl;

	s.reserve(28);
	cout << s.size() << endl;
	cout << s.capacity() << endl;

	s.reserve(10);
	cout << s.size() << endl;
	cout << s.capacity() << endl;

	string s1("hello world!!!!"); //strtok
	char* p = (char*)s1.c_str();
}

// 字符串追加
void Test4()
{
	string s1;
	string s2("hello");
	s1 += s2;
	s1 += ' ';
	s1 += "world";
	s1.push_back('!');
	cout << s1 << endl;
	
	s1.append("nihao xian");
	cout << s1 << endl;
}

void Test5()
{
	string s("hello");

	size_t pos = s.find('o');
	if (pos != string::npos)// npos字符串结尾
	{
		s.insert(pos, "world");
	}
	cout << s << endl;

	// insert在指定位置插入字符
	s.insert(s.begin(), 3, '*');
	cout << s << endl;

	// erase删除从字符位置pos开始的len个字符（如果内容太短或者len=npos,删除元素直到字符串结束）
	// 默认参数会删除字符串中的所有字符（和clear()相同）
	s.erase(s.begin());
	cout << s << endl;
	s.erase(s.begin(), s.begin() + 3);
	cout << s << endl;
	s.erase();
}

void Test6()
{
	string s1("hello");
	string s2("world");
	swap(s1, s2);
	cout << s1 << " " << s2 << endl;

	s1.swap(s2);
	cout << s1 << " " << s2 << endl;
}

// atoi(表示 ascii to integer)是把字符串转换成整型数
void Test7()
{
	string s("12345");
	int value = atoi(s.c_str());
	cout << value << endl;
}

// find()
void Test8()
{
	string s("http://www.baidu.com");
	size_t pos = s.find("www");
	if (pos != string::npos)
	{
		string ret = s.substr(pos);
		cout << ret << endl;
	}
}

// 有多行单词
// 单词和单词之间使用空格隔开，需求：知道最后一个单词的长度
void Test9()
{
	string s;
	// 循环接收一行字符串
	while (getline(cin, s))
	{
		// rfind()反向查找，返回位置
		cout << s.substr(s.rfind(' ') + 1).size() << endl;
	}
}

void Test10()
{
	string s;
	// 一次接收一个
	while (cin >> s)
	{
		cout << s << endl;
	}
}

// 字符串比较，按照ASCII码进行逐个字符比较
void Test11()
{
	string s1("ningbo");
	string s2("mengmeng");
	if (s1 > s2)
		cout << s1 << endl;
	else
		cout << s2 << endl;
}

//字符串的三种遍历
void Test12()
{
	string s("welcome to xian");
	for (int i = 0; i < s.length(); i++)
	{
		cout << s[i];
	}
	cout << endl;

	for (auto e : s)
		cout << e;
	cout << endl;

	auto it = s.begin();
	while (it != s.end())
	{
		cout << *it;
		++it;
	}
	cout << endl;
}

// vs下string类的扩容规律：1.5倍增长
void Test13()
{
	string s;
	size_t sz = s.capacity();
	cout << "make s gorw:\n";
	for (int i = 0; i < 100; i++)
	{
		s.push_back('c');
		if (sz != s.capacity())
		{
			sz = s.capacity();
			cout << "capacity changed:" << sz << endl;
		}
	}
}

int main()
{
	//Test1();
	//Test2();
	//Test3();
	//Test4();
	//Test5();
	//Test6();
	//Test7();
	//Test8();
	//Test9();
	//Test10();
	//Test11();
	//Test12();
	Test13();

	return 0;
}


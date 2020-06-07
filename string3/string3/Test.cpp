#include <iostream>
//#include <string>
#include <assert.h>
#include <stdlib.h>
using namespace std;

class string
{
public:
	string(const char* str = "")
	{
		// 构造string类对象时，如果传递nullptr指针，认为程序非法，此处断言下
		if (nullptr == str)
		{
			assert(false);
			return;
		}
		_str = new char[strlen(str) + 1];
		strcpy(_str, str);
	}
	string(const string& s)
		: _str(new char[strlen(s._str) + 1])
	{
		strcpy(_str, s._str);
	}
	string& operator=(const string& s)
	{
		if (this != &s)
		{
			char* pStr = new char[strlen(s._str) + 1];
			strcpy(pStr, s._str);
			delete[] _str;
			_str = pStr;
		}
		return *this;
	}
	~string()
	{
		if (_str)
		{
			delete[] _str;
			_str = nullptr;
		}
	}
private:
	char* _str;
};
int main()
{
	string s1("hello");
	s1.push_back(' ');
	s1.push_back('b');
	s1.append(1, 'i');
	s1 += 't';
	cout << s1 << end
	return 0;
}



////string类对象的访问方式及遍历操作
//void Teststring1()
//{
//	string s1("hello world");
//	//const类型对象不能修改
//	const string s2("hello girl");
//	cout << s1 << " " << s2 << endl;
//	cout << s1[0] << " " << s2[0] << endl;
//
//	s1[0] = 'H';
//	cout << s1 << endl; 
//}
//void Teststring2()
//{
//	string s("hello world");
//	//三种遍历方式
//	//1.for+operator[]使用最多
//	for (size_t i = 0; i < s.size(); ++i)
//	{
//		cout << s[i];
//	}
//	cout << endl;
//
//	//迭代器
//	string::iterator it = s.begin();
//	while (it != s.end())
//	{
//		cout << *it;
//		++it;
//	}
//	cout << endl;
//
//	//3.范围for
//	for (auto ch : s)
//	{
//		cout << ch;
//	}
//	cout << endl;
//}
//void Teststring3()
//{
//	string str;
//	str.push_back(' ');  //在str后插入空格
//	str.append("hello"); //在str后追加一个字符串"hello"
//	str += 'b';          //在str后追加一个字符'b'
//	str += "it";         //在str后追加一个字符串"it"
//	cout << str << endl;
//	cout << str.c_str() << endl;//以C语言的方式打印字符串
//
//	//获取file的后缀
//	string file("string.cpp");
//	size_t pos = file.rfind('.');
//	string suffix(file.substr(pos, file.size() - pos));
//	cout << suffix << endl;
//
//	//npos是string里面的一个静态成员变量
//	//static const size_t npos=-1;
//
//	//取出url中的域名
//	string url("http://www.cplusplus.com/reference/string/string/find/");
//	cout << url << endl;
//	size_t start = url.find("://");
//	if (start == string::npos)
//	{
//		cout << "invalid url" << endl;
//		return;
//	}
//	start += 3;
//	size_t finish = url.find('/', start);
//	string adderss = url.substr(start,finish - start);
//	cout << adderss << endl;
//
//	//删除url的协议前缀
//	pos = url.find("://");
//	url.erase(0,pos + 3);
//	cout << url <<endl;
//}
//
//int main()
//{
//	//Teststring1();
//	//Teststring2();
//	//Teststring3();
//
//	return 0;
//
//}



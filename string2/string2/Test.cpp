#include <iostream>
#include <string>
#include <vector>
#include <list>
using namespace std;


// 4个默认成员函数
void Test_string()
{
	string s1;  //ok
	string s2("hello");//ok
	string s3("hello", 2);
	string s4(s2);//ok
	string s5(s2, 1, 2);
	string s6(s2, 1, 8);
	string s7(10, 'a');

	cout << s1 << endl;
	cout << s2 << endl;
	cout << s3 << endl;
	cout << s4 << endl;
	cout << s5 << endl;
	cout << s6 << endl;
	cout << s7 << endl;

	s1 = s7;
	cout << s1 << endl;
}
//1.遍历
void Test_string2()
{
	string s1("hello");
	s1 += ' ';
	s1 += "world";
	cout << s1 << endl;

	//[]+下标  推荐使用这个
	//写
	for (size_t i = 0; i < s1.size(); ++i)
	{
		s1[i] += 1;
	}
	//读
	for (size_t i = 0; i < s1.size(); ++i)
	{
		cout << s1[i] << " ";
	}
	cout << endl;
	
	//迭代器
	//写
	//string::iterator it = s1.begin();
	auto it = s1.begin();
	while (it != s1.end())
	{
		*it -= 1;
		++it;
	}
	//读
	it = s1.begin();
	while (it != s1.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;
	//1.迭代器不一定是指针，像指针一样的东西
	//范围for
	//原理其实是迭代器
	for (auto ch : s1)
	{
		cout << ch << " ";
	}
	cout << endl;
	/*vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	vector<int>::iterator vit = v.begin();
	while (vit != v.end())
	{
		cout << *vit << " ";
		++vit;
	}
	cout << endl;*/

}

int string2int(const string& str)
{
	//int val = 0;
	////只能读，不能写
	//string::const_iterator it = str.begin();
	//while (it != str.end())
	//{
	//	val *= 10;
	//	val += (*it-'0');
	//	++it;
	//}
	//return val;
	int val = 0;
	string::const_reverse_iterator rit = str.rbegin();
	while (rit != str.rend())
	{
		val *= 10;
		val += (*rit - '0');
		++rit;
	}
	return val;
}
//反向迭代器
void Test_string3()
{
	string s1("hello world");
	//倒着遍历
	//string::reverse_iterator rit = s1.rbegin();
	auto rit = s1.rbegin();
	while (rit != s1.rend())
	while (rit != s1.rend())
	{
		cout << *rit << " ";
		++rit;
	}
	cout << endl;
	string nums("12345");
	cout << string2int(nums) << endl;

	//方向：正向迭代器，反向迭代器
	//属性：普通和const

}

int main()
{
	//Test_string();
	//Test_string2();
	Test_string3();
	return 0;
}
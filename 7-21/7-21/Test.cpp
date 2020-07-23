//每日一题7-21
//1.骆驼命名法
#include <iostream>
#include <string>
using namespace std;

int main()
{
	string s;
	while (cin >> s)
	{
		for (int i = 0; i<s.size(); i++)
		{
			//1.遇到_就直接跳过
			if (s[i] == '_')
				continue;
			//2.如果上一个字符是_ 则下一个字符转换为大写字母
			if (i>0 && s[i - 1] == '_')
				cout << (char)toupper(s[i]);
			else
				cout << s[i];
		}
		cout << endl;
	}
	return 0;
}
//2.单词倒排
#include<iostream>
#include<sstream>
#include<string>
#include<vector>
using namespace std;
void deal(vector<string>&res, string& str, char delim = ' ')
{
	// 对字符串进行切分, 借助 stringstream 完成. 默认分割符是空格.
	// stringstream 不光能完成切分, 还能完成字符串和数字之间的转换.
	stringstream ss;
	ss << str;
	string tmp;
	while (ss >> tmp) {
		res.push_back(tmp);
	}
}
int main()
{
	string str;
	while (getline(cin, str)) {
		vector<string> res;
		for (int i = 0; i < str.size(); i++)
			// 先对分割符进行处理. 如果发现分割符, 就统一处理成空格.
		if (!isalnum(str[i]))
			str[i] = ' ';
		// 对字符串进行切分
		deal(res, str);
		cout << res[res.size() - 1];
		for (int i = res.size() - 2; i >= 0; i--)
			cout << " " << res[i];
		cout << endl;
	}
	return 0;
}
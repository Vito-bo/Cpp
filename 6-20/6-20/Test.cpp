////每日一题6-20
////1.统计每个月的兔子数
//
//#include <iostream>
//using namespace std;
//
//int main()
//{
//	int month;
//	while (cin >> month)
//	{
//		int first = 1;
//		int second = 1;
//		int result;
//		for (int i = 3; i <= month; i++)
//		{
//			result = first + second;
//			first = second;
//			second = result;
//		}
//		cout << result << endl;
//	}
//	return 0;
//}

//2.字符串通配符

#include <iostream>
#include <string>
using namespace std;
bool match(const char* pattern, const char *str)
{
	//当前字符结束，返回true
	if (*pattern == '\0' && *str == '\0')
		return true;
	//两个字符串有一个先结束，则返回false
	if (*pattern == '\0' || *str == '\0')
		return false;
	if (*pattern == '?')
	{
		//遇到?号，匹配一个字符，跳过一个位置
		return match(pattern + 1, str + 1);
	}
	else if (*pattern == '*')
	{
		// 遇到*号，匹配0个(str不挪动)，1个（两者都向前挪动一个字符）或多个(str向前挪动一个
		return match(pattern + 1, str) || match(pattern + 1, str + 1) ||
			match(pattern, str + 1);
	}
	else if (*pattern == *str)
	{
		//如果当前字符相等，匹配下一个字符
		return match(pattern + 1, str + 1);
	}
	return false;
}
int main()
{
	string pattern, str;
	while (cin >> pattern >> str)
	{
		bool ret = match(pattern.c_str(), str.c_str());
		if (ret)
			cout << "true" << endl;
		else
			cout << "false" << endl;
	}
	return 0;
}


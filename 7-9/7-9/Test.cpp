//每日一题7-9
//1.收件人列表
#include <iostream>
#include <string>
#include <cstdio>
using namespace std;

int main()
{
	int n;
	while (cin >> n)
	{
		cin.get(); //处理回车
		string name;
		for (int i = 0; i<n; i++) //名字分别处理
		{
			bool quote = false;
			getline(cin, name);
			if (name.find(',') != string::npos ||
				name.find(' ') != string::npos) //找到逗号或者空格，就要加双引号
			{
				quote = true;
			}
			if (quote)
			{
				putchar('\"');
			}
			cout << name;
			if (quote)
			{
				putchar('\"');
			}
			if (i == n - 1) //如果已经是最后一个字符串，那就补回车，否则加逗号和空格
			{
				putchar('\n');
			}
			else
			{
				putchar(',');
				putchar(' ');
			}
		}
	}
	return 0;
}

//2.养兔子
#include <iostream>
#include <cstdio>
int main()
{
	long long n[91] = { 1, 2 };
	for (int i = 2; i <= 90; i++)
	{
		n[i] = n[i - 1] + n[i - 2];
	}
	int d;
	while (std::cin >> d)
	{
		printf("%lld\n", n[d - 1]);
	}
}
//每日一题7-8
//1.剪花布条
#include <iostream>
using namespace std;

int main()
{
	string s, t;
	while (cin >> s >> t)
	{
		int res = 0;
		size_t pos = 0;
		//依次在s中查找t即可，直到再也找不到t
		while ((pos = s.find(t, pos)) != string::npos)
		{
			pos += t.size();//逃过t串整体的长度
			++res; //计数
		}
		cout << res << endl;
	}
	return 0;
}

//2.客似云来
#include <iostream>
#define MAX 83 //如果用公式计算，需要接下来两项的值
using namespace std;

void solve(long long num[])
{
	for (int i = 2; i<MAX; i++)
	{
		num[i] = num[i - 1] + num[i - 2];
	}
}
//1.用遍历求和求解
long long sum_traversal(long long num[], int from, int to)
{
	long long ans = 0;
	for (int i = from - 1; i<to; i++)//让数组下标从from-1遍历到to-1
	{
		ans += num[i];
	}
	return ans;
}
int main()
{
	int from, to;
	long long num[MAX] = { 1, 1 };
	//提前计算Fibonacci数列
	solve(num);
	while (cin >> from >> to)
	{
		cout << sum_traversal(num, from, to) << endl;
	}
	return 0;
}

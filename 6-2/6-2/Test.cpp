
////6-2-1
//#include<iostream>
//#include<vector>
//using namespace std;
//// 本题牛客测试用例不全，至少应该增加以下两组测试用例
//// 输入：
//// 4
//// 1 3 2 3
//// 输出：2
//// 输入：
//// 6
//// 3 2 1 1 2 3
//// 输出：2
//int main()
//{
//	int n;
//	cin >> n;
//	// 注意这里多给了一个值，是处理越界的情况的比较，具体参考上面的解题思路
//	vector<int> a;
//	a.resize(n + 1);
//	a[n] = 0;
//	//读入数组
//	int i = 0;
//	for (i = 0; i < n; ++i)
//		cin >> a[i];
//	i = 0;
//	int count = 0;
//	while (i < n)
//	{
//		// 非递减子序列
//		if (a[i] < a[i + 1])
//		{
//			while (i < n && a[i] <= a[i + 1])
//				i++;
//			count++;
//			i++;
//		} 
//		else if (a[i] == a[i + 1])
//			i++;
//		else // 非递增子序列
//		{
//			while (i < n && a[i] >= a[i + 1])
//			i++;
//			count++;
//			i++;
//		}
//	} 
//	cout << count << endl;
//	return 0;
//}

////6-2-2
////解法一
//#include <iostream>
//#include <string>
//#include <algorithm>
//using namespace std;
//int main()
//{
//	string s;
//	// 注意这里要使用getline，cin>>s遇到空格就接收结束了
//	getline(cin, s);
//	// 翻转整个句子
//	reverse(s.begin(), s.end());
//	// 翻转单词
//	auto start = s.begin();
//	while (start != s.end())
//	{
//		auto end = start;
//		while (end != s.end() && *end != ' ')
//			end++;
//		reverse(start, end);
//		if (end != s.end())
//			start = end + 1;
//		else
//			start = end;
//	} 
//	cout << s << endl;
//	return 0;
//}
//解法2
#include <iostream>
#include <string>
using namespace std;
// cin读取string时自动会被空格分隔开，用另一个字符串存储进行逆序输出
int main()
{
	string s1, s2;
	cin >> s1;
	while (cin >> s1)
		s2 = s1 + " " + s2;
	cout << s2 << endl;
	return 0;
}

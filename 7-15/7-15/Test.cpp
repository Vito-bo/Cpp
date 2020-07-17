//每日一题7-15
//1.字符串计数
/*
补齐字符串，按照26进制进行计算
*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#define N 1000007
#include<math.h>
using namespace std;
int main()
{
	//根据题中给出的例子，这个字符串只包含小写字母，不然答案就不应该是56了
	string s1, s2;
	int len1, len2;
	while (cin >> s1 >> s2 >> len1 >> len2)
	{
		//只包含小写字母的字符串可以看成26进制的数制
		//将s1和s2补长到len2长度
		s1.append(len2 - s1.size(), 'a');
		s2.append(len2 - s2.size(), (char)('z' + 1));
		// 确认s1和s2的两个字符串每个位置上的差值
		vector<int> array;
		for (int i = 0; i<len2; i++)
		{
			array.push_back(s2[i] - s1[i]);
		} 
		// 确认len1和len2之间可组成的不同字符串的个数
		int result = 0;
		for (int i = len1; i <= len2; i++)
		{
			for (int k = 0; k<i; k++)
			{
				result += array[k] * pow(26, i - 1 - k);
			}
		} 
		// 所有字符串最后都不包含是s2自身，所以最后要减1；
		cout << result - 1 << endl;
	} 
	return 0;
}
//最长公共子串
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
	string A, B;
	while (cin >> A >> B) 
	{
		int aLength = A.length();
		int bLength = B.length();
		// 用来保存状态转移方程中间结果的矩阵
		vector<vector<int> > dp(aLength, vector<int>(bLength, 0));
		// 初始化dp矩阵边界：边界字符要么在，要么不在
		dp[0][0] = (A[0] == B[0]) ? 1 : 0;
		for (int i = 1; i<aLength; i++) 
		{
			dp[i][0] = (A[i] == B[0]) ? 1 : 0;
			dp[i][0] = max(dp[i - 1][0], dp[i][0]);
		} 
		for (int j = 1; j<bLength; j++) 
		{
				dp[0][j] = (A[0] == B[j]) ? 1 : 0;
				dp[0][j] = max(dp[0][j - 1], dp[0][j]);
			} 
		// 根据状态转移方程进行计算
		for (int i = 1; i<aLength; i++) 
		{
			for (int j = 1; j<bLength; j++) 
			{
					dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
					if (A[i] == B[j]) 
					{
						dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + 1);
					}
			}
		} 
		cout << dp[aLength - 1][bLength - 1] << endl;
	} 
	return 0;
}
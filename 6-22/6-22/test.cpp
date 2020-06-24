////每日一题6-22
////1.汽水数
//#include <iostream>
//using namespace std;
//
//int main()
//{
//	int n;
//	while (cin >> n)
//	{
//		//兑换的汽水数
//		int sum = 0;
//		while (n>1)
//		{
//			//每三瓶换取一瓶
//			int result = n / 3;
//			//每次不足三瓶的空瓶数
//			int num = n % 3;
//			sum = sum + result;
//			//下一次可以兑换的空瓶
//			n = result + num;
//			if (n == 2)
//			{
//				++sum;
//				break;
//			}
//		}
//		cout << sum << endl;
//	}
//	//while(cin>>n)
//	//{
//	//    cout<<n/2<<endl;
//	//}
//	return 0;
//}

//2.查找两个字符串中的最长公共子串
#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;
int main()
{
	string str1, str2;
	while (cin >> str1 >> str2)
	{
		//以最短的字符串作为s1
		if (str1.size() > str2.size())
			swap(str1, str2);
		int len1 = str1.size(), len2 = str2.size();
		int i, j, start = 0, max = 0;
		vector<vector<int>> MCS(len1 + 1, vector<int>(len2 + 1, 0));
		for (i = 1; i <= len1; i++)
		for (j = 1; j <= len2; j++)
		{
			if (str1[i - 1] == str2[j - 1])
				MCS[i][j] = MCS[i - 1][j - 1] + 1;
			//如果有更长的公共子串，更新长度
			if (MCS[i][j] > max)
			{
				max = MCS[i][j];
				//以i结尾的最大长度为max, 则子串的起始位置为i - max
				start = i - max;
			}
		}
		cout << str1.substr(start, max) << endl;
	}
	return 0;
}
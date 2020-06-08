//每日一题6-5
////1.统计回文
//#include <iostream>
//#include <string>
//using namespace std;
////判断是否是回文
//bool IsCircleText(const string& s)
//{
//	size_t begin = 0;
//	size_t end = s.size() - 1;
//	while (begin < end)
//	{
//		if (s[begin] != s[end])
//			return false;
//		++begin;
//		--end;
//	}
//	return true;
//}
//int main()
//{
//	string str1, str2;
//	getline(cin, str1);
//	getline(cin, str2);
//	size_t count = 0;
//	for (size_t i = 0; i <= str1.size(); i++)
//	{
//		//将字符串2插入到字符串1的每一个位置，再判断是否是回文
//		string str = str1;
//		str.insert(i, str2);
//		if (IsCircleText(str))
//			++count;
//	}
//	cout << count << endl;
//	return 0;
//}

//2.连续最大和
#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int size;
	cin >> size;
	vector<int> nums(size);
	for (size_t i = 0; i < size; i++)
		cin >> nums[i];
	int result = nums[0];
	int sum1 = 0, sum2 = 0;
	for (int i = 0; i < nums.size(); i++)
	{
		// 计算到num[i]的子数组的最大和
		sum2 = sum1 >= 0 ? sum1 + nums[i] : nums[i];
		if (sum2>result)
			result = sum2;
		if (sum2 < 0)
			sum2 = 0;
		sum1 = sum2;
	}
	cout << result << endl;

	return 0;
}
////6-3-1 求连续最长字符串
#include<iostream>
#include<string>
using namespace std;
//int main()
//{
//	string str, res, cur;
//	cin >> str;
//	for (int i = 0; i <= str.length(); i++)
//	{
//		// 数字+=到cur
//		if (str[i] >= '0' && str[i] <= '9')
//		{
//			cur += str[i];
//		} 
//		else
//		{
//			// 找出更长的字符串，则更新字符串
//			if (res.size() < cur.size())
//			res = cur;
//			else
//				cur.clear();
//		}
//	} 
//	cout << res;
//	return 0;
//}

//6-3-2 数组中出现次数超过一半的数字
//解法一
class Solution {
public:
	int MoreThanHalfNum_Solution(vector<int> numbers)
	{
		// 因为用到了sort，时间复杂度O(NlogN)，并非最优
		if (numbers.empty()) return 0;
		sort(numbers.begin(), numbers.end()); // 排序，取数组中间那个数
		int middle = numbers[numbers.size() / 2];
		int count = 0; // 出现次数
		for (int i = 0; i<numbers.size(); ++i)
		{
			if (numbers[i] == middle) ++count;
		} 
	    return(count>numbers.size() / 2) ? middle : 0;
	}
};

//解法二
class Solution {
public:
	int MoreThanHalfNum_Solution(vector<int> numbers)
	{
		if (numbers.empty()) return 0;
		// 遍历每个元素，并记录次数；若与前一个元素相同，则次数加1，否则次数减1
		int result = numbers[0];
		int times = 1; // 次数
		for (int i = 1; i<numbers.size(); ++i)
		{
			if (times == 0)
			{
				// 更新result的值为当前元素，并置次数为1
				result = numbers[i];
                times = 1;
} 
			else if (numbers[i] == result)
			{
				++times; // 相同则加1
			} 
			else
			{
				--times; // 不同则减1
			}
		} 
		// 判断result是否符合条件，即出现次数大于数组长度的一半
		times = 0;
		for (int i = 0; i<numbers.size(); ++i)
		{
			if (numbers[i] == result) ++times;
		} 
		return(times > numbers.size() / 2) ? result : 0；
};





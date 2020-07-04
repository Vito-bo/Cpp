//每日一题7-2
//1.奇数位上是奇数或者偶数位上是偶数
class Solution {
public:
	/**
	*  奇数位上都是奇数或者偶数位上都是偶数
	*  输入：数组arr，长度大于2
	*  len：arr的长度
	*  将arr调整成奇数位上都是奇数或者偶数位上都是偶数
	*/
	void oddInOddEvenInEven(vector<int>& arr, int len) {
		long i = 0, j = 1;
		while (i<len && j<len)
		{
			if ((arr[i] % 2) == 0)
			{
				//偶数位上寻找非偶数
				i += 2;
				continue;
			}
			if ((arr[j] % 2) != 0)
			{
				//奇数位上寻找非奇数
				j += 2;
				continue;
			}
			swap(arr[i], arr[j]);
		}
	}
};
//2.猴子分类
#include <iostream>
#include <string>
#include <math.h>
int main()
{
	int n;
	while (std::cin >> n) {
		if (n == 0)
			break;
		long total = pow(5, n) - 4;
		long left = pow(4, n) + n - 4;
		std::cout << total << " " << left << std::endl;
	}
	return 0;
}
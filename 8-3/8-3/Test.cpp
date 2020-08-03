//每日一题8-3-贪心算法

//1.选择排序
void swap(int* array, int i, int j)
{
	int tmp = array[i];
	array[i] = array[j];
	array[j] = tmp;
}
void selectSort(int* arr, int n){
	//i: 未排序数据的起始位置
	for (int i = 0; i < n; ++i)
	{
		int minIdx = i;
		//从所有未排序的数据中找最小值的索引
		for (int j = i + 1; j < n; ++j){
			if (arr[j] < arr[minIdx])
				minIdx = j;
		}
		swap(arr, minIdx, i);
	}
}
//2.平衡字符串
class Solution {
public:
	int balancedStringSplit(string s) {
		int cnt = 0;
		int balance = 0;
		for (int i = 0; i < s.size(); i++){
			if (s[i] == 'L')
				balance--;
			if (s[i] == 'R')
				balance++;
			if (balance == 0)
				cnt++;
		}
		return cnt;
	}
};
//3.买股票的最佳时机
class Solution {
public:
	int maxProfit(vector<int>& prices) {
		int ret = 0;
		for (int i = 1; i < prices.size(); ++i)
		{
			int curProfit = prices[i] - prices[i - 1];
			if (curProfit > 0)
				ret += curProfit;
		}
		return ret;
	}
};
//4.跳跃游戏
class Solution {
public:
	bool canJump(vector<int>& nums) {
		int n = nums.size();
		int rightmost = 0;
		for (int i = 0; i < n; ++i) {
			//如果可以到达当前位置，则更新最大
			if (i <= rightmost) {
				//每次更新最大的位置
				rightmost = max(rightmost, i + nums[i]);
				//如果可以到达最后一个位置，则直接返回
				if (rightmost >= n - 1) {
					return true;
				}
			}
		}
		return false;
	}
};
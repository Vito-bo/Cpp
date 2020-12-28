

#include <iostream>
#include <vector>
using namespace std;

//剑指offer29-顺时针打印矩阵
//方法一，
class Solution {
public:
	vector<int> spiralOrder(vector<vector<int>>& matrix) {
		if (matrix.empty())
			return{};

		vector<int> ret;
		int left = 0; //左边界
		int top = 0;  //上边界
		int right = matrix[0].size() - 1;
		int bottom = matrix.size() - 1;

		// 循环打印
		while (left <= right && top <= bottom)
		{
			// 从左向右打印
			for (int i = left; i <= right; i++)
			{
				ret.push_back(matrix[top][i]);
			}
			top++;

			// 从上向下打印
			for (int i = top; i <= bottom; i++)
			{
				ret.push_back(matrix[i][right]);
			}
			right--;

			// 从右向左打印
			for (int i = right; i >= left && top <= bottom; i--)
			{
				ret.push_back(matrix[bottom][i]);
			}
			bottom--;

			// 从下向上打印
			for (int i = bottom; i >= top && left <= right; i--)
			{
				ret.push_back(matrix[i][left]);
			}
			left++;
		}
		return ret;
	}
};

//方法二
class Solution {
public:
	vector<int> spiralOrder(vector<vector<int>>& matrix) {
		if (matrix.empty())
			return{};

		vector<int> ret;
		int left = 0; //左边界
		int top = 0;  //上边界
		int right = matrix[0].size() - 1; //右边界
		int bottom = matrix.size() - 1;   //下边界

		// 循环打印
		while (true)
		{
			// 从左向右打印
			for (int i = left; i <= right; i++)
			{
				ret.push_back(matrix[top][i]);
			}
			if (++top>bottom)
				break;

			// 从上向下打印
			for (int i = top; i <= bottom; i++)
			{
				ret.push_back(matrix[i][right]);
			}
			if (--right<left)
				break;

			// 从右向左打印
			for (int i = right; i >= left && top <= bottom; i--)
			{
				ret.push_back(matrix[bottom][i]);
			}
			if (--bottom<top)
				break;

			// 从下向上打印
			for (int i = bottom; i >= top && left <= right; i--)
			{
				ret.push_back(matrix[i][left]);
			}
			if (++left>right)
				break;
		}
		return ret;
	}
};

//剑指offer17-打印从1到最大的n位数
class Solution {
public:
	vector<int> printNumbers(int n) {
		vector<int> ret;
		int max = pow(10, n);
		for (int i = 1; i <= (max - 1); i++)
			ret.push_back(i);
		return ret;
	}

};

// 剑指offer24-反转链表
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) 
		: val(x)
		, next(NULL) 
	{}
	
};

// 三指针法
class Solution {
public:
	ListNode* reverseList(ListNode* head) {
		ListNode* cur = nullptr;
		ListNode* prev = head;
		while (prev != nullptr)
		{
			ListNode* tmp = prev->next;
			prev->next = cur;
			cur = prev;
			prev = tmp;
		}
		return cur;
	}
};
int main()
{
	return 0;
}
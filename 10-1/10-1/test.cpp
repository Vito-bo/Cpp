#include <iostream>
using namespace std;
#include <vector>
#include <stack>


//剑指offer刷题

#if 0
//13-机器人运动的范围
//深度优先算法+回溯算法解决
class Solution {
public:
	int movingCount(int m, int n, int k) {
		if (k == 0)
			return 1;
		//记录该位置是否被访问过
		vector<vector<bool>> valid(m, vector<bool>(n, true));
		return dfs(valid, m, n, 0, 0, k);
	}

	int dfs(vector<vector<bool>>& valid, int m, int n, int row, int col, int k)
	{
		int sum = GetSum(row) + GetSum(col);
		//如果有越界，或者和大于K,或者已经访问过了，返回0
		if (row >= m || col >= n || sum > k || !valid[row][col])
			return 0;
		valid[row][col] = false;//该位置状态为：以访问过
		return 1 + dfs(valid, m, n, row + 1, col, k) + dfs(valid, m, n, row, col + 1, k);
	}

	//求某个数字所有数位之和
	int GetSum(int num)
	{
		if (num<10)
			return num;
		int sum = 0;
		while (num > 0)
		{
			sum += num % 10;
			num /= 10;
		}
		return sum;
	}
};
#endif

//06-从尾到头打印链表

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

//方法1：数组逆置
class Solution {
public:
	vector<int> reversePrint(ListNode* head) {
		vector<int> res; //定义数组存储链表结点数据域
		while (head)
		{
			res.push_back(head->val);
			head = head->next;
		}
		//逆转数组
		reverse(res.begin(), res.end());
		return res;
	}
};

//方法2：利用栈的后进先出原则
class Solution {
public:
	vector<int> reversePrint(ListNode* head) {
		vector<int> res;
		stack<int> s;
		//入栈
		while (head)
		{
			s.push(head->val);
			head = head->next;
		}
		//出栈
		while (!s.empty())
		{
			res.push_back(s.top());
			s.pop();
		}
		return res;
	}
};
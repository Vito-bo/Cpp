
#include <iostream>
using namespace std;
#include <vector>

#if 0
//07-重建二叉树
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
	
};
class Solution{
public:
	TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder)
	{
		if (preorder.size() == 0)//没有结点，返回空
			return nullptr;
		if (preorder.size() == 1) //仅有一个结点
		{
			TreeNode *root = new TreeNode(preorder[0]);
			return root;
		}

		//前序遍历第一个为根节点
		TreeNode *root = new TreeNode(preorder[0]);
		auto itr = inorder.begin();
		while (*itr != preorder[0])//找到中序遍历根节点，分割左右子树
			++itr;
		//构造左子树前序中序序列
		int left = itr - inorder.begin(); //左子树个数
		vector<int> leftpre(preorder.begin() + 1, preorder.begin() + 1 + left);//左子树前序
		vector<int> leftin(inorder.begin(), itr);//左子树中序

		//构造右子树前序中序序列
		vector<int> rightpre(preorder.begin() + 1 + left, preorder.end());//右子树前序
		vector<int> rightin(++itr, inorder.end());

		//递归调用
		root->left = buildTree(leftpre, leftin);
		root->right = buildTree(rightpre, rightin);

		//返回根节点
		return root;
	}
};
#endif

#if 0
//14-1剪绳子
//动态规划求解
//定义dp(n)代表长度为n的绳子分割后的最大可能乘积
//先从n中剪下一段长度为i,则dp(n)=dp(n-i)*dp(i)求最大值

class Solution {
public:
	int dp(int n, vector<int>& res)
	{
		int ans = n;
		for (int i = 1; i <= n / 2; i++)
		{
			if (res[n - i] == 0)
				res[n - i] = dp[n - i, res];
			if (res[i] == 0)
				res[n - i] == dp(i, res);
			ans = max(ans, res[n - i] * res[i]);
		}
		return ans;
	}

	int cuttingRope(int n) {
		if (n == 2)
			return 1;
		if (n == 3)
			return 2;
		if (n == 4)
			return 4;
		vector<int> res(n, 0);
		return dp(n, res);
	}
};
#endif

//25-合并两个排序的链表

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		ListNode* head = new ListNode(1);
		ListNode* ret = head;
		while (l1 != NULL && l2 != NULL) 
		{
			if (l1->val < l2->val) 
			{
				head->next = l1;
				l1 = l1->next;
			}
			else 
			{
				head->next = l2;
				l2 = l2->next;
			}
			head = head->next;
		}
		head->next = l1 == NULL ? l2 : l1;
		return ret->next;
	}
};

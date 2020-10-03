#include <iostream>
using namespace std;


//剑指offer刷题
#if 0

//27-二叉树的镜像
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
	
};
class Solution {
public:
	//根据二叉树的中序遍历，递归实现二叉树的镜像
	TreeNode* mirrorTree(TreeNode* root)
	{
		if (root == NULL)
			return NULL;
		swap(root->left, root->right);
		mirrorTree(root->left);
		mirrorTree(root->right);
		return root;
	}
};

#endif


#if 0
//28-对称的二叉树

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
	bool check(TreeNode* p, TreeNode* q) 
	{
		if (p == nullptr && q == nullptr) 
			return true;
		if (p == nullptr || q == nullptr || p->val != q->val) 
			return false;
		//里侧相互比较，外侧相互比较
		return check(p->left, q->right) && check(p->right, q->left);
	}

	bool isSymmetric(TreeNode* root) 
	{
		if (root == nullptr) 
			return true;
		return check(root->left, root->right);
	}
};

#endif



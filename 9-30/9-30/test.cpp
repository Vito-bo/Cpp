
//9-30刷题

/*
//1.剑指offer-10-II-青蛙跳台阶问题
//方法1
class Solution {
public:
	int numWays(int n) {
		if (n <= 1)
			return 1;
		if (n == 2)
			return 2;
		int f1 = 1;
		int f2 = 2;
		int res;
		while (n>2)
		{
			res = (f1 + f2) % 1000000007;
			f1 = f2;
			f2 = res;
			n--;
		}
		return res;
	}
};
//方法2
class Solution {
public:
	int numWays(int n) {
		int a[101]={1,1};
		for(int i=2;i<=n;++i)
		{
			a[i] = (a[i-1]+a[i-2])%1000000007;
		}
		return a[n];
	}
};
*/

/*
//2.剑指offer 11.旋转数组的最小数字
//方法1：暴力法
class Solution {
public:
	int minArray(vector<int>& numbers) {
		int min = numbers[0];
		for (int i = 1; i<numbers.size(); ++i)
		{
			if (min >= numbers[i])
				min = numbers[i];
		}
		return min;
	}
};
//方法2：二分法
class Solution {
public:
	int minArray(vector<int>& numbers) 
	{
		int i=0,j=numbers.size()-1;
		while(i<j)
		{
			int m=(i+j)/2;
			if(numbers[m] > numbers[j])
				i=m+1;
			else if(numbers[m] < numbers[j])
				j=m;
			else
				j--;
		}
		return numbers[i];
	}
};

*/

#if 0
//2.剑指offer12-矩阵中的路径
class Solution {
public:
	bool exist(vector<vector<char>>& board, string word) {
		if (board.empty() || word.empty())
			return false;
		for (int i = 0; i<board.size(); ++i)
		{
			//回溯法递归求解
			for (int j = 0; j<board[0].size(); ++j)
			{
				if (dfs(board, word, i, j, 0))
					return true;
			}
		}
		return false;
	}
	//i,j:字符数组位置  w:字符串索引
	bool dfs(vector<vector<char>>& board, string& word, int i, int j, int w)
	{
		//如果索引越界，或者值不匹配，返回false
		if (i<0 || i >= board.size() || j<0 || j >= board[0].size() || board[i][j] != word[w])
			return false;
		//如果遍历完字符串则匹配成功
		if (w == word.length() - 1)
			return true;
		char tmp = board[i][j];
		board[i][j] = '\0'; //将当前元素标记为'\0'，即一个不可能出现在word里面的元素，表明当前元素不可再参与比较
		if (dfs(board, word, i - 1, j, w + 1)
			|| dfs(board, word, i + 1, j, w + 1)
			|| dfs(board, word, i, j - 1, w + 1)
			|| dfs(board, word, i, j + 1, w + 1))
		{
			//当前元素的上下左右，如果有匹配到的，返回true
			return true;
		}
		board[i][j] = tmp; //将当前元素恢复本身值
		return false;
	}
};
#endif
/*

//4.剑指offer05-替换空格
class Solution {
public:
	string replaceSpace(string s)
	{
		int count = 0; // 统计空格的个数
		int sOldSize = s.size();
		for (int i = 0; i < s.size(); i++)
		{
			if (s[i] == ' ')
			{
				count++;
			}
		}
		// 扩充字符串s的大小，空格替换为%20,增加两个位置
		s.resize(s.size() + count * 2);
		int sNewSize = s.size();
		// 从后先前将空格替换为"%20"
		for (int i = sNewSize - 1, j = sOldSize - 1; j < i; i--, j--)
		{
			if (s[j] != ' ')
			{
				s[i] = s[j];
			}
			else
			{
				s[i] = '0';
				s[i - 1] = '2';
				s[i - 2] = '%';
				i -= 2;
			}
		}
		return s;
	}
};

*/
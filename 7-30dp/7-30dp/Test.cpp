//动态规划算法专题
//三特点：
//1.把原来的问题的分解成几个相似的子问题
//2.所有的子问题都只需要解决一次
//3.存储子问题的解
//四要素：
//1.状态定义
//2.状态间的转移方程定义
//3.状态的初始出
//4.返回结果
//二本质：
//状态的定义，状态转移方程的定义

//1.Fibonacci
//思路1，递归
class Solution{
public:
	int Fibonacci(int n){
		// 初始值
		if (n <= 0){
			return 0;
		}
		if (n == 1 || n == 2) {
			return 1;
		}
		// F(n)=F(n-1)+F(n-2)
		return Fibonacci(n - 2) + Fibonacci(n - 1);
	}
};
//思路2
//动态规划
class Solution2{
public:
	int Fibonacci(int n){
		// 初始值
		if (n <= 0){
			return 0;
		}
		if (n == 1 || n == 2) {
			return 1;
		}
		// 申请一个数组，保存子问题的解，题目要求从第0项开始
		int* record = new int[n + 1];
		record[0] = 0;
		record[1] = 1;
		for (int i = 2; i <= n; i++){
			// F(n)=F(n-1)+F(n-2)
			record[i] = record[i - 1] + record[i - 2];
		}
		return record[n];
		delete[] record;
	}
};
class Solution3{
public:
	int Fibonacci(int n){
		// 初始值
		if (n <= 0){
			return 0;
		}
		if (n == 1 || n == 2) {
			return 1;
		}
		int fn1 = 1;
		int fn2 = 1;
		int result = 0;
		for (int i = 3; i <= n; i++){
			// F(n)=F(n-1)+F(n-2)
			result = fn2 + fn1;
			// 更新值
			fn1 = fn2;
			fn2 = result;
		}
		return result;
	}
};

//2.字符串分割
class Solution {
public:
	bool wordBreak(string s, unordered_set<string> &dict) {
		if (s.empty())
			return false;
		if (dict.empty())
			return false;
		vector<bool> can_break(s.size() + 1, false);
		//初始化F(0)=true;
		can_break[0] = true;
		for (int i = 1; i <= s.size(); i++){
			for (int j = i - 1; j >= 0; j--){
				//F(i):true{j<i&&F[j]&&substr[j+1,i]能在词典中找到} or false
				//第j+1个字符的索引为j
				if (can_break[j] && dict.find(s.substr(j, i - j)) != dict.end()){
					can_break[i] = true;
					break;
				}
			}
		}
		return can_break[s.size()];
	}
};
//3.三角矩阵
class Solution {
public:
	int minimumTotal(vector<vector<int> > &triangle) {

		if (triangle.empty())
			return 0;
		//F[i][j],F[0][0]初始化
		vector<vector<int>> min_sum(triangle);
		int line = triangle.size();
		for (int i = 1; i<line; i++){
			for (int j = 0; j <= i; j++){
				//处理左边界和右边界
				if (j == 0){
					min_sum[i][j] = min_sum[i - 1][j];
				}
				else if (i == j){
					min_sum[i][j] = min_sum[i - 1][j - 1];
				}
				else{
					min_sum[i][j] = min(min_sum[i - 1][j], min_sum[i - 1][j - 1]);
				}
				//F(i,j)=min(F(i-1,j-1),F(i-1,j))+triangle[i][j]
				min_sum[i][j] = min_sum[i][j] + triangle[i][j];
			}
		}
		int result = min_sum[line - 1][0];
		//min(F(n-1,i))
		for (int i = 1; i<line; i++){
			result = min(min_sum[line - 1][i], result);
		}
		return result;
	}
};

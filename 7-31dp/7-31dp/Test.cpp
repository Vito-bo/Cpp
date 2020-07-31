//每日一题7-31
//1.三角矩阵
class Solution {
public:
	//方法2，动态规划（反向思维）
	int minimumTotal(vector<vector<int> > &triangle) {
		if (triangle.empty())
			return 0;
		int row = triangle.size();
		//从倒数第2行开始
		for (int i = row - 2; i >= 0; --i){
			for (int j = 0; j <= i; j++){
				//F(i,j)=min(F(i+1,j),F(i+1,j+1))+arr[i][j]
				triangle[i][j] = min(triangle[i + 1][j], triangle[i + 1][j + 1]) + triangle[i][j];
			}
		}
		return triangle[0][0];
	}
};
//2.路径总数
class Solution {
public:
	//状态：F(i,j):从(0,0)到达(i,j)的路径总数
	//状态转移方程：F(i,j):F(i-1,j)+F(i,j-1)
	//初始状态:F(0,j)  F(i,0)  路径个数都是1
	//返回结果：F(m-1,n-1)
	int uniquePaths(int m, int n) {
		// write code here
		if (m<1 || n<1)
			return 0;
		//初始化，申请F(I,J)空间
		vector<vector<int>> ret(m, vector<int>(n, 1));

		for (int i = 1; i<m; i++){
			for (int j = 1; j<n; j++){
				ret[i][j] = ret[i - 1][j] + ret[i][j - 1];
			}
		}
		return ret[m - 1][n - 1];
	}
};


//每日一题 回溯算法
//1.3张扑克牌分别放到3个盒子中去，且每个盒子只能放一张牌，一共有多少种不同的放法？
#include <vector>
#include <iostream>
using namespace std;
void Dfs(int index, int n, vector<int>& boxs, vector<int>& book)
{
	if (index == n + 1)
	{
		for (int i = 1; i <= n; i++)
			cout << boxs[i] << " ";
		cout << endl;
		return; //向上回退
	}
	for (int i = 1; i <= n; i++)
	{
		if (book[i] == 0) //第i号牌仍在手上
		{
			boxs[index] = i;
			book[i] = 1; //现在第i号牌已经被用了
			//处理下一个盒子
			Dfs(index + 1, n, boxs, book);
			//从下一个盒子回退到当前盒子，取出当前盒子的牌，
			//尝试放入其它牌。
			book[i] = 0;
		}
	}
}
int main()
{
	int n;
	vector<int> boxs;
	vector<int> books;
	cin >> n;
	boxs.resize(n + 1, 0);
	books.resize(n + 1, 0);
	Dfs(1, n, boxs, books);
	return 0;
}

//2.员工的重要性
class Solution {
public:
	int DFS(unordered_map<int, Employee*>& info, int id)
	{
		int curImpo = info[id]->importance;
		for (const auto& sid : info[id]->subordinates)
		{
			curImpo += DFS(info, sid);
		}
		return curImpo;
	}
	int getImportance(vector<Employee*> employees, int id) {
		if (employees.empty())
			return 0;
		unordered_map<int, Employee*> info;
		for (const auto& e : employees)
		{
			info[e->id] = e;
		}
		return DFS(info, id);
	}
};

//3.图像渲染
#include <vector>
#include <iostream>
using namespace std;
//四个方向的位置更新：顺时针更新
int nextPosition[4][2] = { { 0, 1 }, { 1, 0 }, { 0, -1 }, { -1, 0 } };
class Solution {
public:
	void dfs(vector<vector<int>>& image, int row, int col, vector<vector<int>>& book,
		int sr, int sc, int oldColor, int newColor)
	{
		//处理当前逻辑，修改颜色，并且标记已经修改过了
		image[sr][sc] = newColor;
		book[sr][sc] = 1;
		//遍历每一种可能，四个方向
		for (int k = 0; k < 4; ++k)
		{
			int newSr = sr + nextPosition[k][0];
			int newSc = sc + nextPosition[k][1];
			//判断新位置是否越界
			if (newSr >= row || newSr < 0
				|| newSc >= col || newSc < 0)
				continue;
			//如果颜色符合要求，并且之前也没有渲染过，则继续渲染
			if (image[newSr][newSc] == oldColor && book[newSr][newSc] == 0)
			{
				dfs(image, row, col, book, newSr, newSc, oldColor, newColor);
			}
		}
	}
	vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int
		newColor) {
		if (image.empty())
			return image;
		int row = image.size();
		int col = image[0].size();
		//建立标记
		vector<vector<int>> book;
		book.resize(row);
		for (int i = 0; i < row; ++i)
		{
			book[i].resize(col, 0);
		}
		//获取旧的颜色
		int oldColor = image[sr][sc];
		dfs(image, row, col, book, sr, sc, oldColor, newColor);
		return image;
	}
};
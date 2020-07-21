//每日一题7-18
//1.解读密码
#include <iostream>
#include <string>
using namespace std;

int main()
{
	string s;
	while (getline(cin, s))
	{
		for (int i = 0; i<s.size(); i++){
			if (s[i] >= '0' && s[i] <= '9')
				cout << s[i];
		}
		cout << endl;
	}
}
//2.走迷宫
#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
using namespace std;
struct pos { int x, y, level; };
int bfs(vector<vector<char> > & map)
{
	const int dir[4][2] = { { -1, 0 }, { 1, 0 }, { 0, -1 }, { 0, 1 } };
	queue<pos> que;
	int m = map.size(), n = map[0].size();
	vector<vector<bool> > visit(m, vector<bool>(n, false));
	pos start{ 0, 1, 0 }, end{ 9, 8, 0 };
	que.push(start);
	visit[start.x][start.y] = true;
	while (!que.empty())
	{
		pos cur = que.front(), next; //定义cur和next
		que.pop();
		for (int i = 0; i < 4; ++i) //BFS,优先四个方向进行搜索
		{
			next.x = cur.x + dir[i][0];
			next.y = cur.y + dir[i][1];
			next.level = cur.level + 1;
			if (next.x == end.x && next.y == end.y)
				return next.level;
			if (next.x >= 0 && next.x < m && next.y >= 0 && next.y < n && \
				!visit[next.x][next.y] && map[next.x][next.y] == '.')
			{
				que.push(next);
				visit[next.x][next.y] = true;
			}
		}
	} 
	return 0;
}
int main()
{
	vector<vector<char> > map(10, vector<char>(10));
	while (cin >> map[0][0]) //由多个测试用例，需要全部读取
	{
		for (int i = 0; i < 10; ++i)
		for (int j = 0; j < 10; ++j)
		{
			if (i == 0 && j == 0) continue;
			cin >> map[i][j];
		}
		cout << bfs(map) << endl;
	} 
	return 0;
}

//走迷宫
#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
using namespace std;
struct pos { int x, y, level; };
int bfs(vector<vector<char> > & map)
{
	const int dir[4][2] = { { -1, 0 }, { 1, 0 }, { 0, -1 }, { 0, 1 } };
	queue<pos> que;
	int m = map.size(), n = map[0].size();
	vector<vector<bool> > visit(m, vector<bool>(n, false));
	pos start{ 0, 1, 0 }, end{ 9, 8, 0 };
	que.push(start);
	visit[start.x][start.y] = true;
	while (!que.empty())
	{
		pos cur = que.front(), next; //定义cur和next
		que.pop();
		for (int i = 0; i < 4; ++i) //BFS,优先四个方向进行搜索
		{
			next.x = cur.x + dir[i][0];
			next.y = cur.y + dir[i][1];
			next.level = cur.level + 1;
			if (next.x == end.x && next.y == end.y)
				return next.level;
			if (next.x >= 0 && next.x < m && next.y >= 0 && next.y < n && \
				!visit[next.x][next.y] && map[next.x][next.y] == '.')
			{
				que.push(next);
				visit[next.x][next.y] = true;
			}
		}
	}
	return 0;
}

int main()
{
	vector<vector<char> > map(10, vector<char>(10));
	while (cin >> map[0][0]) //由多个测试用例，需要全部读取
	{
		for (int i = 0; i < 10; ++i)
		for (int j = 0; j < 10; ++j)
		{
			if (i == 0 && j == 0) continue;
			cin >> map[i][j];
		}
		cout << bfs(map) << endl;
	}
	return 0;
}

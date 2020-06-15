//每日一题6-12
//1.最近公共祖先
class LCA {
public:
	int getLCA(int a, int b) {
		while (a != b)
		{
			
			if (a > b)
				a /= 2;
			else
				b /= 2;
		}
		return a;
	}
};

//2.最大连续bit数
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main()
{
	int n;
	while (cin >> n)
	{
		int count = 0, maxCount = 0;
		// n右移32次就变为0
		while (n)
		{
			//获取当前位的二进制值
			if (n & 1)
			{
				//如果1的值连续，计数累加，并且跟新最大计数
				++count;
				maxCount = max(count, maxCount);
			} 
			else
			{
				//如果1的值不连续，重新累加
				count = 0;
			} 
			// 右移一次，为获取下一位二进制值做准备
				n = n >> 1;
		} 
		cout << maxCount << endl;
	} 
	return 0;
}
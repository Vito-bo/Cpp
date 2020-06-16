//每日一题 6-13
//1.二进制插入
class BinInsert {
public:
	int binInsert(int n, int m, int j, int i) {
		// write code here
		//将m的二进制值插入到n的第j位到第i位
		//只需要把m先左移j位，然后再与n进行或运算
		m = m << j;
		return n | m;
	}
};

//2.查找组成一个偶数最接近的两个素数
#include <iostream>
#include <algorithm>
using namespace std;

//判断素数
bool IsPrime(int num)
{
	int tmp = sqrt(num);
	for (int i = 2; i <= tmp; i++)
	{
		if (num %i == 0)
			return false;
	}
	return true;
}
int main()
{
	int half;
	int num;
	while (cin >> num)
	{
		half = num / 2;
		int i;
		//从中间向两边找
		for (i = half; i>0; i--)
		{
			if (IsPrime(i) && IsPrime(num - i))
				break;
		}
		cout << i << endl << num - i << endl;
	}
	return 0;
}
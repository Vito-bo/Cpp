////每日一题6-16
////1.计算日期转换天数
//#include <iostream>
//using namespace std;
//
//int main()
//{
//	int year, month, day;
//	int arr[] = { 0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365 };
//	while (cin >> year >> month >> day)
//	{
//		int sum = 0;
//		sum += arr[month - 1];
//		sum += day;
//		if (month>2)
//		{
//			if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
//				sum += 1;
//		}
//		cout << sum << endl;
//	}
//	return 0;
//}
//2.幸运的袋子
#include <iostream>
#include <algorithm>
using namespace std;

/*
getLuckyPacket:从当前位置开始搜索符合要求的组合，一直搜索到最后一个位置结束
x[]: 袋子中的所有球
n: 球的总数
pos: 当前搜索的位置
sum: 到目前位置的累加和
multi: 到目前位置的累积值
*/
int getLuckyPacket(int x[], int n, int pos, int sum, int multi)
{
	int count = 0;
	//循环，搜索以位置i开始所有可能的组合
	for (int i = pos; i<n; i++)
	{
		sum += x[i];
		multi *= x[i];
		if (sum > multi)
		{
			//找到符合要求的组合，加1，继续累加后续的值，看是否有符合要求的集合
			count += 1 + getLuckyPacket(x, n, i + 1, sum, multi);
		}
		else if (x[i] == 1)
		{
			//如何不符合要求，且当前元素值为1，则继续向后搜索
			count += getLuckyPacket(x, n, i + 1, sum, multi);
		}
		else
		{
			//如果sum大于multi,则后面就没有符合要求的组合了
			break;
		}
		//要搜索下一个位置之前，首先恢复sum和multi
		sum -= x[i];
		multi /= x[i];
		//数字相同的球，没有什么区别，都只能算一个组合，所以直接跳过
		while (i < n - 1 && x[i] == x[i + 1])
		{
			i++;
		}
	}
	return count;
}
int main()
{
	int n;
	while (cin >> n)
	{
		int x[n];
		for (int i = 0; i < n; i++)
		{
			cin >> x[i];
		}
		sort(x, x + n);
		//从第一个位置开始搜索
		cout << getLuckyPacket(x, n, 0, 0, 1) << endl;
	}
	return 0;
}

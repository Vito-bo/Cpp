////每日一题6-9
////1.两种排序fangfa
//#include <iostream>
//#include <vector>
//#include <string>
//using namespace std;
//
//int main()
//{
//	int n;
//	cin >> n;
//	vector<string> v;
//	v.resize(n);
//	for (auto& str : v)
//		cin >> str;
//
//	bool lenSym = true, lexSym = true;
//	//这里要注意从i=1开始遍历，前后比较，比较长度
//	for (size_t i = 1; i<v.size(); ++i)
//	{
//		if (v[i - 1].size() >= v[i].size())
//		{
//			lenSym = false;
//			break;
//		}
//	}
//	//比较ASCII码
//	for (size_t i = 1; i<v.size(); ++i)
//	{
//		if (v[i - 1] >= v[i])
//		{
//			lexSym = false;
//			break;
//		}
//	}
//	if (lenSym && lexSym)
//		cout << "both" << endl;
//	else if (!lenSym && lexSym)
//		cout << "lexicographically" << endl;
//	else if (lenSym && !lexSym)
//		cout << "lengths" << endl;
//	else if (!lenSym && !lexSym)
//		cout << "none" << endl;
//	return 0;
//}

//2.求最小公倍数
//最小公倍数=两数之积除以最大公约数
#
include<iostream>
using namespace std;
int gcd(int a, int b)
{
	int r;
	while (r = a%b){
		a = b;
		b = r;
	} r
		eturn b;
} i
nt main()
{
	int a, b;
	while (cin >> a >> b){
		cout << a*b / gcd(a, b) << endl;
	} r
		eturn 0;
}

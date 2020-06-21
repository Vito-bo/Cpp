////每日一题6-18
////1.完全数计算
//#include<iostream>
//#include<algorithm>
//using namespace std;
//
//int count(int n)
//{
//	int cnt = 0;
//	if ((n < 0) | (n>500000))
//		return -1;
//	else {
//		for (int i = 2; i <= n; i++) {
//			int sum = 0;
//			//遍历范围
//			int sq = sqrt(i);
//			for (int j = 2; j <= sq; j++) {
//				if (i%j == 0) {
//					//如果j^2 = i，说明两个约数相同，只加一个
//					if (i / j == j)
//						sum += j;
//					else
//						//否则，两个不同的约数都要相加
//						sum += j + (i / j);
//				}
//			}
//			if (sum + 1 == i)
//				cnt++;
//		}
//		return cnt;
//	}
//}
//int main()
//{
//	int input;
//	while (cin >> input)
//		cout << count(input) << endl;
//	return 0;
//}

//2.扑克牌大小
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main(){
	string line;
	while (getline(cin, line)){
		//王炸最大，直接输出
		if (line.find("joker JOKER") != -1)
			cout << "joker JOKER" << endl;
		else{
			int dash = line.find('-');
			//分开两手牌
			string car1 = line.substr(0, dash);
			string car2 = line.substr(dash + 1);
			//获取空格的次数，牌数为c + 1
			int c1 = count(car1.begin(), car1.end(), ' ');
			int c2 = count(car2.begin(), car2.end(), ' ');
			//拿到第一张牌
			string first1 = car1.substr(0, car1.find(' '));
			string first2 = car2.substr(0, car2.find(' '));
			string str = "345678910JQKA2jokerJOKER";
			if (c1 == c2){
				//只要牌数相等，则第一张牌大的即为大
				if (str.find(first1) > str.find(first2))
					cout << car1 << endl;
				else
					cout << car2 << endl;
			} 
			else
			{
				//牌数不相同，说明类型不同,只有炸弹可以和其它牌比较
				//其它类型都是错误的
				if (c1 == 3)
				cout << car1 << endl;
				else if (c2 == 3)
					cout << car2 << endl;
				else
					cout << "ERROR" << endl;
			}
		}
	}
}

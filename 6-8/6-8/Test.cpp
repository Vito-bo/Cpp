//每日一题6-8
////1.Fibonacci数列
//#include <iostream>
//using namespace std;
//int main()
//{
//	int f0 = 0, f1 = 1, f;
//	int N;
//	int L = 0, R = 0;
//	cin >> N;
//	while (1)
//	{
//		f = f0 + f1;
//		f0 = f1;
//		f1 = f;
//		//找到比N小且距离N最近的数，求出距离
//		if (f<N)
//			L = N - f;
//		else
//		{
//			//找到比N大且距离N最近的数，求出距离
//			R = f - N;
//			break;
//		}
//	}
//	//获取最小距离
//	cout << min(L, R) << endl;
//	return 0;
//}

//2.合法括号序列判断
class Parenthesis {
public:
	bool chkParenthesis(string A, int n) {
		// write code here
		stack<char> sc;
		for (auto ele : A) {
			switch (ele) {
			case '(':
				sc.push(ele);
				break;
			case ')':
			{
						if (sc.empty() || sc.top() != '(')
							return false;
						else
							sc.pop();
			}
				break;
			default:
				return false;
			}
		}
		return true;
	}
};
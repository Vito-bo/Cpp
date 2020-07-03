//每日一题7.1
//1.不再加减乘除的加法运算
class Solution {
public:
	int Add(int num1, int num2)
	{
		while (num2 != 0)
		{
			int sum = num1^num2; //得到相加后不包含进位的数据
			int carray = (num1&num2) << 1;//得到两数相加的进位
			num1 = sum;           //两个数相加，直到进位为0
			num2 = carray;
		}
		return num1;
	}
};
//2.三角形
#include <iostream>
using namespace std;
#define ADD(x, y) ((x) + (y))
#define CMP(x, y) ((x) > (y))
int main()
{
	double a, b, c;
	while (cin >> a >> b >> c)
	{
		//对两边进行求和与第三遍进行比较
		if (CMP(ADD(a, b), c) && CMP(ADD(b, c), a) && CMP(ADD(a, c), b)) {
			cout << "Yes" << std::endl;
		}
		else {
			cout << "No" << std::endl;
		}
	}
	return 0;
}
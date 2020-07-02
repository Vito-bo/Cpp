//每日一题6-30
//1.变态跳台阶
class Solution {
public:
	int jumpFloorII(int number) {
		//2^(n-1) == 1 << (n-1)
		return 1 << (number - 1);
	}
};

//2.快到碗里来
#include <iostream>
using namespace std;
int main()
{
	double n, r;
	while (cin >> n >> r)
	{
		//周长：2*r*3.1415
		//身长：n
		if (n > (2 * r*3.1415))
			cout << "No" << endl;
		else
			cout << "Yes" << endl;
	}
	return 0;
}
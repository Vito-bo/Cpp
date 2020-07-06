//每日一题7-3
//1.最难的问题
#include <stdio.h>
int main() {
	char c;
	while ((c = getchar()) != EOF){
		if ('A' <= c && 'Z' >= c) {
			c = (c > 'E') ? (c - 5) : (c + 21);
		} 
		putchar(c);
	} 
	return 0;
}
//2.因子个数
#include <iostream>
#include<math.h>
using namespace std;
int main()
{
	int n, k, i;
	while (cin >> n){
		k = 0;
		for (i = 2; i <= sqrt(n); i++) {
			if ((n % i) == 0) {
				while ((n % i) == 0){
					n = n / i;
				} k
					++;
			}
		} 
		if (n != 1)
			k++;
		cout << k << endl;
	} 
	return 0;
}

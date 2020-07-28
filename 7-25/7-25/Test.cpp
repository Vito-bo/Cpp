//每日一题7-25
//1.左右最值最大差
class MaxGap {
public:
	int findMaxGap(vector<int> A, int n) {
		vector<int> mxL(n, 0);//记录i位左侧最大值
		vector<int> mxR(n, 0);//记录i位右侧最大值
		int ma = INT_MIN;
		for (int i = 0; i<n; i++){//左侧
			if (i == 0)
				mxL[i] = A[i];
			else
				mxL[i] = max(A[i], mxL[i - 1]); // 第 i 位左侧的最大值就是 i - 1 位最大值和 i 的值的较大值
		} 
		for (int i = n - 1; i >= 0; i--){//右侧
			if (i == n - 1)
				mxR[i] = A[i];
			else
				mxR[i] = max(A[i], mxR[i + 1]);
		} 
			// 例如输入数据为[2, 7, 3, 1, 1]
			// mxL 中的值为: [2,7,7,7,7]
			// mxR 中的值为: [7,7,3,1,1]
			int res = INT_MIN;
		// 接下来的循环就依次求差找最大值即可.
			for (int i = 0; i<n - 1; i++){//求差
				res = max(res, abs(mxL[i] - mxR[i + 1]));
			} 
			return res;
	}
};
//2.顺时针打印矩阵
class Printer {
public:
	vector<int> clockwisePrint(vector<vector<int> > mat, int n, int m) {
		vector<int> ret;
		int x1 = 0, y1 = 0; //左上角坐标
		int x2 = n - 1, y2 = m - 1; //右下角坐标
		// 这两个坐标表示了一个矩形(最开始的矩阵)
		// 然后按照要求打印最外圈的数据.
		// 打印完毕之后, 缩小矩形的大小.
		while (x1 <= x2 && y1 <= y2){
			for (int j = y1; j <= y2; ++j)
				ret.push_back(mat[x1][j]);
			for (int i = x1 + 1; i < x2; ++i)
				ret.push_back(mat[i][y2]);
			for (int j = y2; x1 < x2 && j >= y1; --j) //x1 < x2：只有在不是单一的横行时才执行这个循环
				ret.push_back(mat[x2][j]);
			for (int i = x2 - 1; y1 < y2 && i > x1; --i)//y1 < y2：只有在不是单一的竖列时才执行这个循环
				ret.push_back(mat[i][y1]);
			x1++; y1++;
			x2--; y2--;
		} 
		return ret;
	}
};

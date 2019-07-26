#include<iostream>
#include<algorithm>
using namespace std;

const int maxn = 5;
int a[maxn][maxn] = {     //不要开data数组名
	{ 22,32,14,77,45 },
	{ 0,12,34,37,23 },
	{ 0,0,44,23,15 },
	{ 0,0,0,34,54 },
	{ 0,0,0,0,88 }
};

//设dp[i][j]表示访问到顶点a[i][j]处时，所有path中的最大sum
int dp[maxn][maxn];

int main() {
	int i, j, sum, maxsum;
	maxsum = sum = 0;
	//第一行
	for (i = 0; i < maxn; i++) {
		sum += a[0][i];
		dp[0][i] = sum;
		if (sum > maxsum) {
			maxsum = sum;
		}
	}

	//其他行
	for (i = 1; i < maxn; i++) {
		for (j = i; j < maxn; j++) {
			dp[i][j] = a[i][j] + max(dp[i - 1][j - 1], dp[i][j - 1]);
			if (dp[i][j] > maxsum) {
				maxsum = dp[i][j];
			}
		}
	}

	cout << maxsum << endl;

	return 0;
}

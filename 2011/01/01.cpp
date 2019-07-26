#include<iostream>
#include<algorithm>
using namespace std;

const int maxn = 5;
int a[maxn][maxn] = {     //��Ҫ��data������
	{ 22,32,14,77,45 },
	{ 0,12,34,37,23 },
	{ 0,0,44,23,15 },
	{ 0,0,0,34,54 },
	{ 0,0,0,0,88 }
};

//��dp[i][j]��ʾ���ʵ�����a[i][j]��ʱ������path�е����sum
int dp[maxn][maxn];

int main() {
	int i, j, sum, maxsum;
	maxsum = sum = 0;
	//��һ��
	for (i = 0; i < maxn; i++) {
		sum += a[0][i];
		dp[0][i] = sum;
		if (sum > maxsum) {
			maxsum = sum;
		}
	}

	//������
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

//最长回文子序列 
#include<iostream>
#include<string>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn = 310;
int dp[maxn][maxn];

int main() {
	string str;
	getline(cin,str);
	int len = str.size();
	memset(dp, 0, sizeof(dp));
	
	//统一大小写,这里将小写转化成大写 
	for(int i=0;i<len;i++){
		if(str[i]>='a'&&str[i]<='z'){
			str[i]=toupper(str[i]);
		}
	}

	//边界
	for (int i = 0; i<len; i++) {
		dp[i][i] = 1;
	}

	//状态转移方程
	for (int i = len-2; i >= 0; i--) {
		for (int j = i+1; j < len; j++) {
			if (str[i] ==str[j]) {
				if(j==i+1){
					dp[i][j]=2;
				}else{
					dp[i][j] = dp[i + 1][j - 1] + 2;
				}
			}
			else {
				dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
			}
		}
	}

	cout << dp[0][len - 1] << endl;
	return 0;
}

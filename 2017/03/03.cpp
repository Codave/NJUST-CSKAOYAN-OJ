#include<iostream>
#include<algorithm>
using namespace std;
const int maxn=1000010;
int a[maxn];

int main(){
	int c,x;
	cin>>c>>x;
	for(int i=0;i<c;i++){
		cin>>a[i]; 
	}
	int count=0;
	//int cursum=0;
	for(int i=0;i<c;i++){
		for(int j=i;j<c;j++){   //ÈÃj´Ó0¿ªÊ¼ 
			int sum=0;
			for(int k=i;k<=j;k++){
				sum+=a[k];
			}
			if(sum>=x){
				count++;
			}
		}
	}
	cout<<count<<endl;
	return 0;
} 

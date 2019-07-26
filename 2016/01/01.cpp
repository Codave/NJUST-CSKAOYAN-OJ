//Çó½×³Ë
#include<iostream>
using namespace std;
typedef long long ll;

ll a[14];

ll fun1(int n){
	if(n<=1){
		return 1;
	}
	return fun1(n-1)*n;
}

ll fun2(int n){
	if(a[n]){
		return a[n];
	}
	if(n<=1){
		a[n]=1;
		return a[n];
	}
	return fun2(n-1)*n;
}

int main(){
	int n;
	cin>>n;
	cout<<fun1(n)<<endl;
	cout<<fun2(n)<<endl;

	return 0;
} 

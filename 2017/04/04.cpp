#include<iostream>
using namespace std;
 
void change(int x,int r){
	if(x==0){
		return;
	}
	change(x/r,r);
	if(r<16){
		cout<<x%r;
	}else if(r==16){
		int c=x%r;
		if(c>=10){
			char ch=c-10+'A';
			cout<<ch;
		}else{
			cout<<c;
		}
	}
}
 
int main(){
	int x;
 	cin>>x;
 	change(x,2);
 	cout<<endl;
 	change(x,8);
 	cout<<endl;
 	change(x,16);
 	cout<<endl;
 	
 	return 0;
}

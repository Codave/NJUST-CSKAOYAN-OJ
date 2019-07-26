#include<iostream>
#include<string>
using namespace std;

int main(){
	int k,count[105]={1};
	cin>>k;

	for(int j=0;j<k;j++){
		string str;
		cin>>str;
		
		int max=1;
		for(int i=0;i<str.length();i++){
			if(str[i]==str[i+1]){
				max++;
			}else{
				if(max>count[j]){
					count[j]=max;
					max=1;
				}
			}
		} 
	}
	
	for(int i=0;i<k;i++){
		cout<<count[i]<<endl;
	}
	
	return 0;
}



#include<iostream>
#include<string>
using namespace std;

bool NeedChange(string str){
	int len=str.length();
	if(len<2)  return false;
	if((str.find("MF"))!=str.npos){ 
		return true;
	}else{
		return false;
	}
}

void Change(string& str){
    int pos=0;
	while((pos=str.find("MF",pos))!=str.npos)  
	{  
	    str.replace(pos,2,"FM");
		pos+=2;
	} 
}

//学长的笨方法 
//void changeOnce(string &str)
//{
//	int len = str.length(); 
//	
//	bool flag = false;
//	for (int i=0;i<len-1;i++)
//	{
//		if(flag)
//		{
//			flag = false;
//			continue;
//		}
//		if(str[i]=='M' && str[i+1]=='F' && (!flag) )
//		{
//			// str[i] <--> str[i+1]
////			char temp = str[i];
////			str[i] = str[i+1];
////			str[i+1]= temp;
//			str.replace(i,2,"FM");
//			flag = true;
//		}
//	}
//}


int main(){
	string str;
	cin>>str;
	
	int ans;
	while(NeedChange(str)){
		Change(str);
		ans++;
	}
	cout<<ans;
	return 0;
}

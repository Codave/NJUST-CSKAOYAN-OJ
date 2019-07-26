//¿®∫≈∆•≈‰ 
#include<iostream>
#include<string>
#include<vector>
#include<stack>
using namespace std;

bool isOK(string str){
	stack<char> s;
	for(int i=0;i<str.length();i++){
		char temp = str[i];
		if((temp=='(')||(temp=='[')||(temp=='{')||(temp=='<')){
			s.push(temp);
		}else if(temp==')'){
			if(s.empty()){
				return false;
			}else{
				if(s.top()!='('){
					return false;
				}else{
					s.pop();
				}
			}
		}else if(temp=='}'){
			if(s.empty()){
				return false;
			}else{
				if(s.top()!='{'){
					return false;
				}else{
					s.pop();
				}
			}
		}else if(temp=='>'){
			if(s.empty()){
				return false;
			}else if(s.top()!='<'){
				return false;
			}else{
				s.pop();
			}
		}else if(temp==']'){
			if(s.empty()){
				return false;
			}else if(s.top()!='['){
				return false;
			}else{
				s.pop();
			}
		}
	}
	if(s.empty()){
		return true;
	}else{
		return false;
	}
}

int main(){
	string str;
	for(int i=0;i<6;i++){
		cin>>str;
		if(isOK(str)){
			cout<<"yes"<<endl;
		}else{
			cout<<"no"<<endl;
		}
	}
	
	
	return 0;
}

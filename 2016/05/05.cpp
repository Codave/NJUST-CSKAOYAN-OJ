#include<iostream>
using namespace std;

const int maxn=10010;
int data[maxn][maxn]={0};
bool visited[maxn]={false};

void dfs(int nowVisit,int N,int cursum, int& max){
	//cursum++;
	visited[nowVisit]=true;
	if(cursum>max) max=cursum;
	for(int v=0;v<N;v++){
		if(visited[v]==false&&data[nowVisit][v]!=0){
			dfs(v,N,cursum+1,max);
		}
	}
}

int main(){
	int N,M;  //M是根，起点 
	cin>>N>>M;
	int u,v;
	for(int i=0;i<N-1;i++){
		cin>>u>>v;
		data[u][v]=data[v][u]=true;
	}
	int cursum=0,max=0;
	visited[M]=true;
	dfs(M,N,cursum,max);
	cout<<max<<endl;
	return 0;
}

#include<iostream>
#include<algorithm> 
//#include<cstring>  //因为memset函数的头文件是cstring 
using namespace std;

const int INF=0x3f3f3f3f;
const int maxv=1005;
int G[maxv][maxv];
int d[maxv];  //顶点与集合S最短的距离

 
int prim(int n,int m){
	bool vis[maxv]={false};
	fill(d,d+maxv,INF);
	d[0]=0;
	int ans=0;
	for(int i=0;i<n;i++){
		int u=-1,MIN=INF;
		for(int j=0;j<n;j++){
			if(vis[j]==false&&d[j]<MIN){
				u=j;
				MIN=d[j];
			}
		}
		if(u==-1) return -1;
		vis[u]=true;
		ans+=d[u];
		for(int v=0;v<n;v++){
			if(vis[v]==false&&G[u][v]!=INF&&G[u][v]<d[v]){
				d[v]=G[u][v];
			}
		}
	}
	return ans;
}


int main(){
	int k;
	cin>>k;
	int u,v,w;
	while(k--){
		int n,m;
		cin>>n>>m;
		
//		for(int i=0;i<n;i++){
//			for(int j=0;j<n;j++){
//				G[i][j]=INF;
//			}
//		}
		fill(G[0],G[0]+maxv*maxv,INF);
		
		for(int i=0;i<m;i++){
			cin>>u>>v>>w;
			G[u][v]=G[v][u]=w;
		}
		int ans=prim(n,m);
		cout<<ans<<endl;
	}
	
	return 0;
}

//0 1 1
//0 2 1
//1 2 2
//
//0 1 5
//0 4 1
//0 3 2
//1 4 6
//1 2 1
//3 2 3
//2 4 3
//3 4 5

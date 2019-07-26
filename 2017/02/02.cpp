#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

int n,m; 
int st=1;  //ÆðµãÎª1 
const int INF=0x3f3f3f3f;
const int maxn=110;
int G[maxn][maxn];
bool visited[maxn][maxn];
int dis[maxn];
int pre[maxn];
bool vis[maxn]={false};

int Dijkstra(int s){
	fill(dis,dis+maxn,INF);
	for(int i=1;i<=n;i++){
		pre[i]=i;
	}
	dis[s]=0;
	for(int i=1;i<=n;i++){
		int u=-1,MIN=INF;
		for(int j=1;j<=n;j++){
			if(vis[j]==false&&dis[j]<MIN){
				u=j;
				MIN=dis[j];
			}
		}
		if(u==-1)  return -1;
		vis[u]=true;
		for(int v=1;v<=n;v++){
			if(vis[v]==false&&G[u][v]!=INF&&dis[u]+G[u][v]<dis[v]){
				dis[v]=dis[u]+G[u][v];
				pre[v]=u;
			}
		}
	}
}

void dfs(int v){
	if(v==st){
		cout<<v<<" ";
		return; 
	}
	dfs(pre[v]);
	if(v!=n){
		cout<<v<<" ";
	}else{
		cout<<v;
	}
}

int main(){
	
	cin>>n>>m;
	fill(G[0],G[0]+maxn*maxn,INF);
	int a,b,c;
	for(int i=1;i<=m;i++){
		
		cin>>a>>b>>c;
		if(visited[a][b]&&c<G[a][b]){
			G[a][b]=G[b][a]=c;
		}else{
			G[a][b]=G[b][a]=c;
			visited[a][b]=visited[b][a]=true;
		}
	}
	
	if(Dijkstra(st)==-1){
		cout<<-1;
	}else{
		dfs(n);
	}
	
//	for(int i=1;i<=n;i++){
//		cout<<dis[i]<<" ";
//	}
	return 0;
}

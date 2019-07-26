#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;

const int maxn = 105;
const int INF = 0x3f3f3f3f;
int n;
double G[maxn][maxn];
double dis[maxn];
bool vis[maxn] = { false };

struct point {
	int x;
	int y;
	point() {}
	point(int _x, int _y) :x(_x), y(_y) {}
}p[maxn];

double distance1(point a,point b) {
	double ans = sqrt((a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y));
	return ans;
}

double prim() {
	fill(dis, dis + maxn, INF);
	dis[1] = 0.0;
	
	double curres=0.0;
	for (int i = 1; i <= n; i++) {
		int u = -1;
		double MIN = INF;
		for (int j = 1; j <= n; j++) {
			if (!vis[j] && dis[j]<MIN) {
				u = j;
				MIN = dis[j];
			}
		}
		if (u == -1)  return -1;
		vis[u] = true;
		curres += MIN;
		for (int v = 1; v <= n; v++) {
			if (!vis[v] && G[u][v] != INF&&G[u][v]<dis[v]) {
				dis[v] = G[u][v];
			}
		}
	}
	return curres;
}

int main() {
	cin >> n;
	fill(G[0], G[0] + maxn*maxn, INF);
	int a,b;
	for (int i = 1; i <= n; i++) {
		//cin >> p[i].x >> p[i].y;
		cin>>a>>b;
		p[i]=point(a,b);
	}
	for (int i = 1; i <= n; i++) {
		for (int j = i+1; j <= n; j++) {
			G[i][j] = distance1(p[i], p[j]);  //= G[j][i] 
		}
	}

	double res = prim();
	printf("%.2lf\n", res);

	return 0;
}

#include <iostream>
#include <cmath>
#include <cstring>
#include <iomanip>
#include <algorithm>
using namespace std;
#define inf 0x3f3f3f3f

const int maxn = 210;
int n,cnt;
double x[maxn],y[maxn];
double l[maxn][maxn];
double d[maxn];
int vis[maxn];

double Pow(double a,double b){
	return (a - b) * (a - b);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cnt = 0;

	while(cin >> n){
		// cnt ++;
		memset(vis,0,sizeof(vis));
		
		if(!n)break;

		for(int i = 1;i <= n;i ++){
			cin >> x[i] >> y[i];
		}

		for(int i = 1;i <= n;i ++){
			for(int j = 1;j <= i;j ++){
				l[i][j] = l[j][i] = sqrt(Pow(x[i],x[j]) + Pow(y[i],y[j]));
			}
		}

		// for(int k = 1;k <= n;k ++){
		// 	for(int i = 1;i <= n;i ++){
		// 		for(int j = 1;j <= n;j ++){
		// 			if(l[i][j] > max(l[i][k],l[k][j]))
		// 				l[i][j] = max(l[i][k],l[k][j]);
		// 		}
		// 	}
		// }

		for(int i = 1;i <= n;i ++){
			d[i] = l[1][i];
		}

		for(int i = 1;i <= n;i ++){
			double mn = inf;
			int to = -1;
			for(int j = 1;j <= n;j ++){
				if(!vis[j] && mn > d[j]){
					to = j;
					mn = d[j];
				}
			}
			if(to != -1){
				vis[to] = 1;
				for(int j = 1;j <= n;j ++){
					if(!vis[j] && d[j] > max(d[to],l[to][j]))d[j] = max(d[to],l[to][j]);
				}
			}
		}

		cout << "Scenario #" << ++cnt << endl;
		cout << "Frog Distance = "<< fixed << setprecision(3) << d[2] << endl << endl;
	}
}
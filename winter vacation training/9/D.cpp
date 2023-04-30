#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <map>
#include <queue>
#include <algorithm>
#include <utility>
#define pii pair<int,int>
using namespace std;
#define inf -1000000

const int maxn = 1e3 + 10;
int g[maxn][maxn];
int vis[maxn];
int d[maxn];


int t,n,m;

int main()
{
    ios::sync_with_stdio(false);

    cin >> t;
    int cnt = 1;//作孽TAT
    while(t--){
        cin >> n >> m;
        // vector<pii> d[n+1];//存放每个点位的路径，first是前面一个点，second是后面一个点
        // pii cnt;
        int a,b,c;
        // int ans = 0;
        
        memset(g,0,sizeof(g));//初始化为0
        for(int i=1;i<=m;i++){
            cin >> a >> b >> c;
            g[a][b] = max(g[a][b],c);//要求最大权重，同时去重
            g[b][a] = g[a][b];//无向图
        }

        for(int i=1;i<=n;i++)d[i] = g[1][i];

        // ans = max(ans,d[n]);//先更新一下
        memset(vis,0,sizeof(vis));
        vis[1] = 1;
        for(int i=1;i<=n;i++){
            int to = 0;
            for(int j=1;j<=n;j++)if(!vis[j]&&d[j] > d[to])to = j;

            vis[to] = 1;
            for(int j=1;j<=n;j++){
                if(!vis[j]){
                    d[j] = max(d[j],min(d[to],g[to][j]));//通过先判断经过的点的路和到j的路之间的比小，再与原本确定的j的承重比大
                }
            }
        }
        cout << "Scenario #" << cnt++ << ":" << endl;
        cout << d[n] << endl;
        cout << endl;
    }
    return 0;
}
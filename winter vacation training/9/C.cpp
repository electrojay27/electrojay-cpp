#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>
#include <utility>
#include <map>
using namespace std;
#define pii pair<int,int>
#define inf 2000000//注意inf的取值，可能超出int范围，导致最后出来的是一个负数

const int maxn = 1e3 + 10;
int g[maxn][maxn];
int d[maxn];
int vis[maxn];
int t,n;

int main()
{
    ios::sync_with_stdio(false);
    
    while(cin >> t >> n){
        // vector<pii> g[n+1];
        // map<int,int> all;//去重
        // pii s;
        // int ans = 0x3f3f3f3f;
        int a,b,c;
        // memset(g,0x3f,sizeof(g));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=i;j++){
                if(i == j)g[i][j] = 0;
                else g[i][j] = g[j][i] = inf;
            }
        }
        
        memset(vis,0,sizeof(vis));
        for(int i=1;i<=t;i++){
            cin >> a >> b >> c;
            // // if(all[a] == b * 10 + c)continue;
            // // all[a] = b*10 + c;
            // s.first = c;
            // s.second = b;
            // g[a].push_back(s);//存进去,建立反图
            g[a][b] = min(g[a][b],c);
            g[b][a] = g[a][b];//双向图
        }
        for(int i=1;i<=n;i++)d[i] = g[1][i];
        // d[1] = 0;//起点距离为0
        // priority_queue<pii,vector<pii>,greater<pii> > q;
        // s.first = 0,s.second = 1;
        // q.push(s);//存入起点
        for(int i=1;i<=n;i++){
            int to;
            int min = inf;
            for(int j=1;j<=n;j++)
                if(!vis[j]&&min > d[j])
                    to = j,min = d[j];

            vis[to] = 1;

            for(int j=1;j<=n;j++){
                if(!vis[j] && d[j] > g[to][j] + d[to]){
                    d[j] = g[to][j] + d[to];
                }
            }
        }
        cout << d[n] << endl;
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
#define inf 2147483647
#define pii pair<int,int>

//Dijkstra算法

const int maxn =5e5 + 10;
// int g[maxn][maxn];//邻接表
// struct A
// {
    // vector<pii> edge;//first -> 终点，second -> 距离
// }g[maxn];
int d[maxn];//表示最短路距离
int vis[maxn];//表示最短路是否确定
int n,m,s;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    while(cin >> n >> m >> s){
        // cin >> n >> m >> s;
        vector<pii> edge[n+1];//first -> 终点，second -> 距离
        int a,b,c;
        // memset(g,0x3f,sizeof(g));
        memset(vis,0,sizeof(vis));

        for(int i=1;i<=n;i++)d[i] = inf;//初始化
        d[s] = 0;//起点确定

        for(int i=1;i<=m;i++){
            cin >> a >> b >> c;
            edge[a].push_back({b,c});//存边
        }

        priority_queue<pii,vector<pii>,greater<pii>> q;
        q.push({0,s});//存入的是最短距离和起点
        
        while(q.size()){
            pii cnt = q.top();
            q.pop();
            int x = cnt.first;
            int y = cnt.second;
            if(vis[y])continue;
            vis[y] = 1;
            for(int i=0;i<edge[y].size();i++){
                pii cmp = edge[y][i];
                int dist = cmp.second;//距离
                int ny = cmp.first;//终点
                if(d[ny] > d[y] + dist){
                    d[ny] = d[y] + dist;//更新
                    q.push({d[ny],ny});//存入
                }
            }
        }
        
        for(int i=1;i<=n;i++)cout << d[i] << " ";
        cout << endl;
    }
    return 0;
}
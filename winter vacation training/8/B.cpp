#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
int n,m;
int vis[maxn],A[maxn];
vector<int> mp[maxn];
void dfs(int d,int mx){
    // if(vis[mx])return;
    // vis[mx] = 1;
    // if(A[d] < mx)A[d] = mx;
    // // vis[d] = mx;
    // for(int i = 0;i < mp[mx].size();i ++)dfs(d,mp[mx][i]);
    // vis[mx] = 0;
    if(A[d])return;//如果有值就说明已经访问过
    A[d] = mx;
    for(int i=0;i<mp[d].size();i++)dfs(mp[d][i],mx);
}
int main()
{
    // memset(vis,0,sizeof(vis));
    memset(A,0,sizeof(A));
    scanf("%d%d",&n,&m);
    int a,b;
    for(int i=1;i<=m;i++){
        scanf("%d%d",&a,&b);
        // mp[a].push_back(b);
        mp[b].push_back(a);//反向建图
    }
    for(int i=n;i>0;i--)dfs(i,i);//从大的点出发，可以到达的小点反向说明小点可以到大点
    for(int i=1;i<=n;i++)printf("%d ",A[i]);
    printf("\n");
    return 0;
}
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
#define i64 long long

int mp[25][25];
int vis[25];
int n,ans;

void dfs(int now,int sum)
{
    if(ans < sum)ans=sum;
    if(now > n)return;
    // if(vis[now])return;
    vis[now] = 1;
    int cmp = sum;
    for(int i=1;i<=n;i++){
        if(vis[i])cmp -= mp[now][i];
        else cmp += mp[now][i];
    }
    dfs(now+1,cmp);//继续探索这一步
    vis[now] = 0;
    dfs(now+1,sum);//去下一个点测试
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    while(cin >> n){
        memset(vis,0,sizeof(vis));
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                cin >> mp[i][j];
        ans = 0;
        dfs(1,0);
        cout << ans << endl;
    }
    return 0;
}
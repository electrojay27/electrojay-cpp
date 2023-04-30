#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll mp[15][15];
map<ll,ll> vis;
ll H,W,ans;

void dfs(ll x,ll y){
    if(x > H || y > W ||(vis.count(mp[x][y]) && vis[mp[x][y]]))return;
    if(x == H&&y == W){
        ans ++;
        return;
    }
    vis[mp[x][y]] = 1;
    dfs(x+1,y);
    dfs(x,y+1);
    vis[mp[x][y]] = 0;
}

int main()
{
    ios::sync_with_stdio(0);

    while(cin >> H >> W){
        for(int i=1;i<=H;i++)
            for(int j=1;j<=W;j++)
                cin >> mp[i][j];
        ans = 0;
        dfs(1,1);
        cout << ans << endl;
    }
    return 0;
}
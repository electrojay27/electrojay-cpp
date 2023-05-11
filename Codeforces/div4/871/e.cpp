#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

int mp[1010][1010];
int vis[1010][1010];

int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

int n,m;

void dfs(int x,int y,int id){
    for(int i = 0;i < 4;i ++){
        int xx = x + dx[i];
        int yy = y + dy[i];
        if(xx < 0 || yy < 0 || xx >= n || yy >= m || vis[xx][yy] || !mp[xx][yy]){
            continue;
        }
        vis[xx][yy] = id;
        dfs(xx,yy,id);
    }
}

void solve()
{
    cin >> n >> m;

    for(int i = 0;i < n;i ++){
        for(int j = 0;j < m;j ++){
            vis[i][j] = 0;
        }
    }
        
    for(int i = 0;i < n;i ++){
        for(int j = 0;j < m;j ++){
            cin >> mp[i][j];
        }
    }

    int id = 0;
    for(int i = 0;i < n;i ++){
        for(int j = 0;j < m;j ++){
            if(!vis[i][j] && mp[i][j]){
                vis[i][j] = ++ id;
                dfs(i,j,id);
            }
        }
    }

    int ans = 0;
    vector<int> v(id + 1,0);
    for(int i = 0;i < n;i ++){
        for(int j = 0;j < m;j ++){
            if(vis[i][j]){
                v[vis[i][j]] += mp[i][j];
                ans = max(v[vis[i][j]],ans);
            }
        }
    }

    cout << ans << "\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t --){
        solve();
    }
    return 0;
}
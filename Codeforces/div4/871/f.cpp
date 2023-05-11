#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve()
{
    int n,m;
    cin >> n >> m;

    vector<int> mp[n + 1];
    int u,v;
    for(int i = 0;i < m;i ++){
        cin >> u >> v;
        mp[u].push_back(v);
        mp[v].push_back(u);
    }

    int x = 0,y = 0;
    for(int i = 1;i <= n;i ++){
        int dx = 0,dy = 0;
        if(!mp[i].size() || mp[i].size() == 1)continue;
        dx = mp[i].size();
        dy = mp[mp[i][0]].size() - 1;
        for(int j = 1;j < mp[i].size();j ++){
            if(dy != mp[mp[i][j]].size() - 1){
                dy = 0;
                break;
            }
        }
        if(!dy)continue;
        x = max(x,dx);
        y = max(y,dy);
    }

    cout << x << " " << y << "\n";
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
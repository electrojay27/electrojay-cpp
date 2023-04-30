#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 10;
vector<int> mp[maxn];
int in[maxn],out[maxn];
int dp[maxn];
int n,m,ans;

int dfs(int x)
{
    if(dp[x])return dp[x];
    int ans = 0;
    if(!out[x])return 1;
    for(int i=0;i<mp[x].size();i++){
        ans += dfs(mp[x][i]);
    }
    dp[x] = ans;
    return ans;
}

int main()
{
    ios::sync_with_stdio(false);
    while(cin >> n >> m){
        memset(in,0,sizeof(in));
        memset(out,0,sizeof(out));
        memset(dp,0,sizeof(dp));
        ans = 0;
        int a,b;
        for(int i=1;i<=m;i++){
            cin >> a >> b;
            out[a]++;//出度加一
            in[b]++;//入度加一
            mp[a].push_back(b);
        }
        int ans = 0;
        for(int i=1;i<=n;i++){
            if(!in[i] && out[i])
                ans += dfs(i);
        }
        cout << ans << endl;
    }
    return 0;
}
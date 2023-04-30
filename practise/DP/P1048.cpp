#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e3 + 10;
// int a[maxn];
int dp[110][maxn];
struct Node
{
    int t,v;
}a[maxn];
int n,m;

void solve()
{
    memset(dp,0,sizeof(dp));
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            dp[i][j] = dp[i-1][j];
            if(a[i].t <= j)dp[i][j] = max(dp[i][j],dp[i-1][j-a[i].t]+a[i].v);
        }
    }
    cout << dp[m][n] << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    while(cin >> n >> m){
        for(int i=1;i<=m;i++)
            cin >> a[i].t >> a[i].v;
        solve();
    }
    return 0;
}
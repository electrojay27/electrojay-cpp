#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int maxn = 1e3 + 10;
int dp[maxn];//以药物和打哪个人为主
struct Node
{
    int l;
    int w;
    int cost;
}a[maxn];
int n,x;

void solve()
{
    memset(dp,0,sizeof(dp));
    for(int i=1;i<=n;i++){
        for(int j=0;j<=x;j++){
            dp[j] = dp[j-1];
            if(j >= a[i].cost)dp[j] = max(dp[j]+a[i].l,dp[j-a[i].cost]+a[i].w);
            else dp[j] += a[i].l;
        }
    }
    cout << 5ll * dp[x] << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    while(cin >> n >> x){
        for(int i=1;i<=n;i++)
            cin >> a[i].l >> a[i].w >> a[i].cost;
        solve();
    }
    return 0;
}
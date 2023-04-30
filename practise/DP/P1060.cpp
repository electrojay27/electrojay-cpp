#include <bits/stdc++.h>
using namespace std;

const int maxn = 3e4 + 10;
int dp[maxn];//花i钱买到的最大价值
int n,m;
struct P1060
{
    int v,p;
}a[30];


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    while(cin >> n >> m){
        for(int i=1;i<=m;i++)
            cin >> a[i].v >> a[i].p;

        memset(dp,0,sizeof(dp));

        for(int i=1;i<=m;i++){
            for(int j=n;j>=a[i].v;j--){
                dp[j] = max(dp[j],dp[j-a[i].v]+a[i].v*a[i].p);
            }
        }
        cout << dp[n] << endl;
    }
}
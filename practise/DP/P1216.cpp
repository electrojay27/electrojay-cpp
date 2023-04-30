#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e3 + 10;
// int a[maxn][maxn];
int dp[maxn][maxn];
// struct Node
// {
    
// }a[maxn];
int n;

void solve()
{
    for(int i=n-1;i>0;i--){
        for(int j=1;j<=i;j++){
            dp[i][j] += max(dp[i+1][j],dp[i+1][j+1]);
        }
    }
    cout << dp[1][1] << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    while(cin >> n){
        for(int i=1;i<=n;i++)
            for(int j=1;j<=i;j++)
                cin >> dp[i][j];
        solve();
    }
    return 0;
}
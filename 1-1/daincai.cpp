#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e4 + 10;
int dp[110][maxn];
int a[110];
int n,m;
int main()
{
    while(scanf("%d%d",&n,&m)!=EOF){
        memset(dp,0,sizeof(dp));
        for(int i=1;i<=n;i++)
            scanf("%d",&a[i]);
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(j>a[i])dp[i][j] = dp[i-1][j-a[i]] + dp[i-1][j];
                if(j==a[i])dp[i][j] = dp[i-1][j]+1;
                if(j<a[i])dp[i][j] = dp[i-1][j];
            }
        }printf("%d\n",dp[n][m]);
    }
}
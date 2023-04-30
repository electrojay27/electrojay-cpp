#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e3 + 10;
int dp[maxn][maxn];
int a[maxn],b[maxn];

int main()
{
    int t,n,v;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&v);
        for(int i=1;i<=n;i++)scanf("%d",&a[i]);
        for(int i=1;i<=n;i++)scanf("%d",&b[i]);
        memset(dp,0,sizeof(dp));//01背包问题
        for(int i=1;i<=n;i++){
            for(int j=v;j>=0;j--){
                dp[i][j] = dp[i-1][j];
                if(j >= b[i])dp[i][j] = max(dp[i][j],dp[i-1][j-b[i]]+a[i]);
            }
        }
        printf("%d\n",dp[n][v]);
    }return 0;
}
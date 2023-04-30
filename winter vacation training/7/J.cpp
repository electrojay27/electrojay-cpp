#include <bits/stdc++.h>
using namespace std;

const int maxn = 110;
int  dp[maxn];
int a[maxn][maxn];

int main()
{
    int n,m;
    while(scanf("%d%d",&n,&m)!=EOF&&n&&m){
        for(int i=1;i<=n;i++){
            a[i][0] = 0;
            for(int j=1;j<=m;j++)
                scanf("%d",&a[i][j]);
        }
        memset(dp,0,sizeof(dp));
        for(int i=1;i<=n;i++){
            for(int j=m;j>=0;j--){
                for(int k=0;k<=m;k++){
                    if(j >= k)dp[j] = max(dp[j],dp[j-k]+a[i][k]);
                }
            }
        }
        printf("%d\n",dp[m]);
    }return 0;
}
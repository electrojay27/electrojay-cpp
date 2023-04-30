#include <bits/stdc++.h>
using namespace std;

const int maxn = 410;
int dp[55][maxn][maxn];
struct D
{
    int h,t,k;//h:体积,t:质量,k:卡路里
}p[55];

int main()
{
    int h,t;
    scanf("%d%d",&h,&t);
    int n;
    scanf("%d",&n);
    memset(dp,0,sizeof(dp));
    for(int i=1;i<=n;i++)scanf("%d%d%d",&p[i].h,&p[i].t,&p[i].k);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=h;j++){
            for(int k=1;k<=t;k++){
                dp[i][j][k] = dp[i-1][j][k];
                if(j >= p[i].h&&k >= p[i].t)dp[i][j][k] = max(dp[i][j][k],dp[i-1][j-p[i].h][k-p[i].t]+p[i].k);
            }
        }
    }
    printf("%d\n",dp[n][h][t]);
}

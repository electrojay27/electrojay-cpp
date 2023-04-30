#include <bits/stdc++.h>
using namespace std;;
const int maxn = 1e3 + 10;
int dp[maxn][maxn];
struct A
{
    int val,qua;
}p[maxn];

int T,n,v,sum;
int main()
{
    scanf("%d",&T);
    while(T--){
        memset(dp,0,sizeof(dp));
        scanf("%d%d",&n,&v);
        for(int i=1;i<=n;i++)
            scanf("%d",&p[i].val);
        for(int i=1;i<=n;i++)
            scanf("%d",&p[i].qua);
        for(int i=1;i<=n;i++){
            for(int j=0;j<=v;j++){
                dp[i][j] = dp[i-1][j];//先继承上一件物品对应这个体积的最大值
                if(p[i].qua<=j)dp[i][j] = max(dp[i-1][j],dp[i-1][j-p[i].qua]+p[i].val);
                // else dp[i][j] = dp[i-1][j];
            }
        }printf("%d\n",dp[n][v]);
    }return 0;
}
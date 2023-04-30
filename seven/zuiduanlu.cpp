#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e7;
int dp[110][110];//记录两个节点之间最短路径
int main()
{
    int n,m,a,b,c;
    while(scanf("%d%d",&n,&m)!=EOF&&(n&&m)){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                dp[i][j] = maxn;//初始化
            }
        }
        for(int i=1;i<=m;i++){
            scanf("%d%d%d",&a,&b,&c);
            dp[a][b] = dp[b][a] = c;
        }
        for(int k=1;k<=n;k++){
            for(int i=1;i<=n;i++){
                for(int j=1;j<=n;j++){
                    dp[i][j] = min(dp[i][j],dp[i][k]+dp[k][j]);
                }
            }
        }printf("%d\n",dp[1][n]);
    }
}
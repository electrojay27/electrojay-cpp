#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e3 + 10;
int dp[maxn],n,W;
struct Node
{
    int v,w,m;//v->价值;w->重量;m->数量;
}p[110];
int main()
{
    while(scanf("%d%d",&n,&W)!=EOF){
        for(int i=1;i<=n;i++)
            scanf("%d%d%d",&p[i].v,&p[i].w,&p[i].m);
        memset(dp,0,sizeof(dp));
        for(int i=1;i<=n;i++){
            for(int j=W;j>0;j--)
                for(int k=1;k<=p[i].m&&k*p[i].w<=j;k++)
                    dp[j] = max(dp[j],dp[j-k*p[i].w]+k*p[i].v);
        }printf("%d\n",dp[W]);
    }
}

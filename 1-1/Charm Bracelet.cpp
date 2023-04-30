#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e4;
int dp[maxn];
struct bb
{
    int w,v;
}a[maxn];
int n,M;
int main()
{
    while(scanf("%d%d",&n,&M)!=EOF){
        for(int i=1;i<=n;i++)
            scanf("%d%d",&a[i].w,&a[i].v);
        memset(dp,0,sizeof(dp));
        for(int i=1;i<=n;i++)
            for(int j=M;j>0;j--)
                if(j>=a[i].w)dp[j] = max(dp[j],dp[j-a[i].w]+a[i].v);
        printf("%d\n",dp[M]);
    }return 0;
}
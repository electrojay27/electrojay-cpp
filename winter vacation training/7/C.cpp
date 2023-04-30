#include <bits/stdc++.h>
using namespace std;

const int maxn = 4e4 + 10;
int dp[maxn];
struct C
{
    int v,w;
}p[110];

int main()
{
    int n,w;
    scanf("%d%d",&n,&w);
    memset(dp,0,sizeof(dp));
    int a,b,m;
    for(int i=1;i<=n;i++){
        int cnt = 1;
        scanf("%d%d%d",&a,&b,&m);
        for(int i=1;i<=m;i<<=1){
            p[cnt].v = i * a;
            p[cnt++].w = i * b;
            m -= i;
        }
        if(m > 0){
            p[cnt].v = m*a;
            p[cnt++].w = m*b;
        }
        for(int i=1;i<cnt;i++){
        for(int j=w;j>0&&j>=p[i].w;j--){
            dp[j] = max(dp[j],dp[j-p[i].w]+p[i].v);
        }
    }
    }
    printf("%d\n",dp[w]);
}
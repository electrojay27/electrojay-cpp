#include <bits/stdc++.h>
using namespace std;
const int maxt = 1e7 + 10;
const int maxn = 1e4 + 10;
long long dp[maxt];
int t[maxn],v[maxn];
int n,T;
int main()
{
    while(scanf("%d%d",&T,&n)!=EOF){
        for(int i=1;i<=n;i++)
            scanf("%d%d",&t[i],&v[i]);
        for(int i=1;i<=n;i++)
            // if(t[i]>T||(t[i]>t[i+1]&&v[i]<v[i+1]))continue;
            for(int j=1;j<=T;j++)
                if(j>=t[i])dp[j] = max(dp[j],dp[j-t[i]]+v[i]);
        printf("%lld\n",dp[T]);
    }return 0;
}
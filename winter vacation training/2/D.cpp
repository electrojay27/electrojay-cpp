#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 10;
int a[maxn],dp[maxn];
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF){
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i]);
            dp[i] = -1e4;
        }
        dp[0] = -1e4;
        int ans = -1e4;
        for(int i=1;i<=n;i++){
            dp[i] = max(dp[i-1]+a[i],a[i]);
            ans = max(dp[i],ans);
        }printf("%d\n",ans);
    }
}
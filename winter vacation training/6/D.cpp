#include <bits/stdc++.h>
using namespace std;

const int maxn = 3e4 + 10;
int dp[maxn];
int a[maxn];

int main()
{
    int n;
    while(scanf("%d",&n)!=EOF){
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    memset(dp,0,sizeof(dp));
    int mx = 0;
    for(int i=1;i<=n;i++){
        dp[i] = 1;
        for(int j=1;j<=i;j++){
            if(a[i] > a[j])dp[i] = max(dp[i],dp[j]+1);
        }
        mx = max(mx,dp[i]);
    }
    printf("%d\n",mx);
    }return 0;
}
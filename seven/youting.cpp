#include <bits/stdc++.h>
using namespace std;
int dp[250],a[250][250];
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<n;i++){
        for(int j=1+i;j<=n;j++)
            scanf("%d",&a[i][j]);
            dp[i] = 1e9;
    }
    for(int i=n-1;i>=1;i--)
        for(int j=i+1;j<=n;j++)
            dp[i] = min(dp[i],a[i][j]+dp[j]);
    printf("%d\n",dp[1]);
    return 0;
}
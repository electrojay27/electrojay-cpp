#include <bits/stdc++.h>
using namespace std;
int dp[400][400],a[400][400];
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=i;j++){
                scanf("%d",&a[i][j]);
                dp[i][j] = a[i][j];
            }
        }
        for(int i=n-1;i>0;i--)
            for(int j=1;j<=i;j++)
                dp[i][j] = max(dp[i+1][j],dp[i+1][j+1]) + a[i][j];
            printf("%d\n",dp[1][1]);
    }
}
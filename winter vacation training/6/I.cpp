#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn = 110;
int dp[maxn][maxn];
// int a[maxn][maxn];

int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            scanf("%d",&dp[i][j]);
        }
    }
    // memset(dp,0,sizeof(dp));
    for(int i=n-1;i>0;i--){
        for(int j=1;j<=i;j++){
            dp[i][j] = max(dp[i+1][j],dp[i+1][j+1]) + dp[i][j];
        }
    }
    printf("%d\n",dp[1][1]);
    return 0;
}
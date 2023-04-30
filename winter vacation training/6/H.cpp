#include <bits/stdc++.h>
using namespace std;

const int maxn = 4e3 + 10;
int dp[maxn];
int a[5];

int main()
{
    int n;
    scanf("%d",&n);
    memset(dp,0,sizeof(dp));
    int p,q,r;
    dp[0] = 1;
    for(int i=1;i<=3;i++)scanf("%d",&a[i]);
    for(int i=1;i<=3;i++){
        for(int j=0;j<=n;j++){
            if(j >= a[i]&&dp[j-a[i]])dp[j] = max(dp[j],dp[j-a[i]]+1);
        }
    }
    printf("%d\n",dp[n]-1);
}
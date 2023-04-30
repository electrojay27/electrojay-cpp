#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int maxt = 1e7 + 10;
const int maxm = 1e4 + 10;
ll dp[maxt];//表示时间为i时所取得的药材最大值
int a[maxm],b[maxm];

int main()
{
    int m,t;
    scanf("%d%d",&t,&m);
    for(int i=1;i<=m;i++)scanf("%d%d",&a[i],&b[i]);
    memset(dp,0,sizeof(dp));//01背包问题，时间不用完完整整花完
    for(int i=1;i<=m;i++){
        for(int j=1;j<=t;j++){
            dp[j] = dp[j];
            if(j >= a[i])dp[j] = max(dp[j],dp[j-a[i]]+b[i]);
        }
    }
    printf("%lld\n",dp[t]);
}
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

const int maxn = 1e3 + 10;
int dp[maxn];//标记每个为最后一个元素时的子序列长度
int a[maxn];

int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    // memset(dp,0,sizeof(dp));
    for(int i=1;i<=n;i++)dp[i] = 1;
    int cnt;
    for(int i=1;i<=n;i++){
        // cnt = i;
        // for(int j=i-1;j>0;j--){
        //     if(a[cnt] > a[j])dp[i]++,cnt = j;
        // }
        for(int j=1;j<i;j++){
            if(a[i] > a[j])dp[i]=max(dp[j]+1,dp[i]);
        }
    }
    int mx = 0;
    for(int i=1;i<=n;i++)mx = max(mx,dp[i]);
    printf("%d\n",mx);
    return 0;
}
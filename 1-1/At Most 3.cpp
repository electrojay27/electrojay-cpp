#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 +10;
int dp[maxn];
int a[350];
int n,w,all;
int main()
{
    while(scanf("%d%d",&n,&w)!=EOF){
        all = 0;
        memset(dp,0,sizeof(dp));
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i]);
            if(a[i]<=w&&!dp[a[i]])dp[a[i]] = 1,all++;
        }
        for(int i=1;i<=n-1;i++)
            for(int j=i+1;j<=n;j++)
                if(a[i]+a[j]<=w&&!dp[a[i]+a[j]])dp[a[i]+a[j]]=1,all++;
        for(int i=1;i<=n-2;i++)
            for(int j=i+1;j<=n-1;j++)
                for(int k=j+1;k<=n;k++)
                    if(a[i]+a[j]+a[k]<=w&&!dp[a[i]+a[j]+a[k]])dp[a[i]+a[j]+a[k]]=1,all++;
        printf("%d\n",all);
    }
}
#include <bits/stdc++.h>
using namespace std;

const int maxn = 3e6 + 10;
int dp[maxn];
vector<int> a[maxn];

int main()
{
    int n;
    scanf("%d",&n);
    int x,y,cnt;
    cnt = 0;
    for(int i=1;i<=n;i++){
        scanf("%d%d",&x,&y);
        a[y].push_back(x);
        cnt = max(cnt,y);
    }
    memset(dp,0,sizeof(dp));
    for(int i=1;i<=cnt;i++){
        dp[i] = dp[i-1];
        for(int j=0;j<a[i].size();j++){
            dp[i] = max(dp[i],dp[a[i][j]-1]+i-a[i][j]+1);
        }
    }
    printf("%d\n",dp[cnt]);
}
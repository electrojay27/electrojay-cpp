#include <bits/stdc++.h>
using namespace std;

const int maxn =1e3 + 10;
int dp[maxn][maxn];
vector<int> zu[maxn];
struct E
{
    int m,v;
}p[maxn];


int main()
{
    int n,m;
    scanf("%d%d",&m,&n);
    int a,b,c,mx;
    mx = 0;
    for(int i=1;i<=n;i++){
        scanf("%d%d%d",&a,&b,&c);
        p[i].m = a;
        p[i].v = b;
        zu[c].push_back(i);
        mx = max(mx,c);
    }
    memset(dp,0,sizeof(dp));
    // dp[0][0] = 0;
    for(int i=1;i<=mx;i++){
        for(int j=0;j<=m;j++){
            dp[i][j] = dp[i-1][j];
            for(int k=0;k<zu[i].size();k++){
                if(j >= p[zu[i][k]].m)dp[i][j] = max(dp[i][j],dp[i-1][j-p[zu[i][k]].m]+p[zu[i][k]].v);
            }
        }
    }
    printf("%d\n",dp[mx][m]);
}
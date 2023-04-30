#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e3 + 10;
int dp[maxn][maxn];
// char a[maxn],b[maxn];
int main(){
    // scanf("%s%s",a+1,b+1);
    string a,b;
    cin >> a >> b;
    a = '\0' + a;
    b = '\0' + b;
    int x = a.size(),y = b.size();
    // memset(dp,0,sizeof(dp));
    for(int i=1;i<x;i++)dp[i][0] = i;
    for(int i=1;i<y;i++)dp[0][i] = i;
    for(int i=1;i<x;i++){
        for(int j=1;j<y;j++){
            dp[i][j] = min(dp[i-1][j],dp[i][j-1]) + 1;
            if(a[i]==b[j])dp[i][j] = min(dp[i][j],dp[i-1][j-1]);
            else dp[i][j] = min(dp[i][j],dp[i-1][j-1]+1);
        }
    }
    // printf("%d",y);
    printf("%d\n",dp[x-1][y-1]);
}
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <iostream>
using namespace std;
const int maxn = 5e3 + 10;
int dp[2][maxn];
char a[maxn],b[maxn];
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF){
        memset(a,'\0',sizeof(a));
        memset(b,'\0',sizeof(b));
        scanf("%s",a);
        for(int i=0;i<n;i++)
            b[n-i-1] = a[i];
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                // int flag = i%2;
                if(i%2){
                    dp[1][j] = max(dp[0][j],dp[1][j-1]);
                    if(a[i-1]==b[j-1])dp[1][j] = max(dp[0][j],dp[0][j-1]+1);
                }else{
                    dp[0][j] = max(dp[1][j],dp[0][j-1]);
                    if(a[i-1]==b[j-1])dp[0][j] = max(dp[1][j],dp[1][j-1]+1);
                }
            }
        }printf("%d\n",n-dp[n%2][n]);
    }
}
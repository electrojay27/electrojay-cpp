#include <iostream>
#include <cstring>
#include <algorithm>
#include <string>

const int maxn = 1e3 + 10;
int dp[maxn][maxn];
using namespace std;

int main()
{
    string a,b;
    while(cin >> a >> b){
        memset(dp,0,sizeof(dp));
        a = '\0' + a;
        b = '\0' + b;
        int lena = a.size();
        int lenb = b.size();
        for(int i=1;i<lena;i++){
            for(int j=1;j<=lenb;j++){
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                if(a[i] == b[j]){
                    dp[i][j] = max(dp[i-1][j-1]+1,dp[i][j]);
                }
            }
        }
        printf("%d\n",dp[lena-1][lenb-1]);
    }
}
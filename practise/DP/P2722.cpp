#include <bits/stdc++.h>
using namespace std;
#define i64 long long

const int maxn = 1e4 + 10;
i64 dp[maxn];
int val,t;
int n,m;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    while(cin >> m >> n){
        memset(dp,0,sizeof(dp));
        for(int i=1;i<=n;i++){
            cin >> val >> t;
            for(int j=0;j<=m;j++){
                if(j >= t)dp[j] = max(dp[j],dp[j-t]+val);
            }
        }
        cout << dp[m] << endl;
    }
}

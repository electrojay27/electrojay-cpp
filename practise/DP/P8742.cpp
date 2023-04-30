#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 10;
int dp[maxn];
int a[110];
int n;

int main()
{
    ios::sync_with_stdio(false);

    while(cin >> n){
        int total = 0;
        int ans = 0;
        for(int i=1;i<=n;i++){
            cin >> a[i];
            total += a[i];//总和
        }

        memset(dp,0,sizeof(dp));
        dp[total] = 1;
        dp[0] = 1;
        ans ++;

        for(int i=1;i<=n;i++){
            for(int j=total;j>=a[i];j--){
                if(dp[j-a[i]]&&!dp[j]){
                    dp[j] = 1;
                    ans ++;
                }
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=total-a[i];j++){
                if(dp[j+a[i]]&&!dp[j]){
                    dp[j] = 1;
                    ans ++;
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}
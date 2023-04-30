#include <bits/stdc++.h>
using namespace std;

const int maxn = 5e4 + 10;
int dp[maxn];
int all[5050];
int h,c;

int main()
{
    ios::sync_with_stdio(false);

    while(cin >> c >> h){
        for(int i=1;i<=h;i++)cin >> all[i];

        memset(dp,0,sizeof(dp));
        for(int i=1;i<=h;i++){
            for(int j=c;j>=all[i];j--){
                if(dp[j-all[i]]+all[i] <= c)dp[j] = max(dp[j],dp[j-all[i]]+all[i]);
            }
        }

        cout << dp[c] << endl;
    }
}
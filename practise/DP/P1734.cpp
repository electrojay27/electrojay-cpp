#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e3 + 10;
int dp[maxn];//表示总和在i时约数的最大值
int S;

int main()
{
    ios::sync_with_stdio(false);

    while(cin >> S){
        memset(dp,0,sizeof(dp));
        for(int i=2;i<=S;i++){
            int cnt = 0;
            for(int j=1;j*j <= i;j++){
                if(i % j == 0){
                    if(j == 1)cnt ++;
                    else if(j == i / j)cnt += j;
                    else{
                        cnt += (j + i / j);
                    }
                }
            }
            for(int j=S;j>=i;j--){
                dp[j] = max(dp[j],dp[j-i]+cnt);
            }
        }
        cout << dp[S] << endl;
    }
}
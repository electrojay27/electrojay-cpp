#include <bits/stdc++.h>
using namespace std;
#define i64 long long

const int maxn = 2e6 + 10;
int dp[maxn];
int s,n,d;
int a[20],b[20];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);

    while(cin >> s >> n >> d){
        for(int i=1;i<=d;i++){
            cin >> a[i] >> b[i];
            a[i] /= 1000;
        }
        
        int toa = s;
        for(int i=1;i<=n;i++){//第一轮遍历年数
            int more = 0;//每一年的利润
            memset(dp,0,sizeof(dp));//每一年初始化一次

            for(int j=1;j<=d;j++){
                for(int k=1;k<=toa/1000;k++){
                    if(k >= a[j])dp[k] = max(dp[k],dp[k-a[j]]+b[j]);
                    more = max(dp[k],more);
                }
            }

            toa += more;
        }

        cout << toa << endl;
    }
    return 0;
}
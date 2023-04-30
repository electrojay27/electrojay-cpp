#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e3 + 10;
int dp[maxn];
int m[6] = {1,2,3,5,10,20};
int a[6];
int num[maxn];
int all,sum,cnt;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    all = 0;
    sum = 0;
    cnt = 1;
    for(int i=0;i<6;i++){
        cin >> a[i];//输入数量
        all += a[i] * m[i];
    }

    memset(dp,0,sizeof(dp));
    dp[0] = 1;
    dp[all] = 1;
    sum ++;

    for(int i=0;i<6;i++){
        for(int j=all;j>=0;j--){
            for(int k=1;k<=a[i];k++){
                if(dp[j-k*m[i]]&&!dp[j]&&j-k*m[i]>=0){
                    dp[j] = 1;
                    sum ++;
                }
            }
        }
    }
    cout << "Total=" << sum << endl;
    return 0;
}
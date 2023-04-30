#include <bits/stdc++.h>
using namespace std;
#define i64 long long

const int maxn = 1e3 + 10;
i64 dp[maxn];
bool vis[maxn];
int n;

// bool judge(int x){
//     if(x == 1)return false;
//     if(x == 2)return true;
//     for(int i=2;i*i <= x;i++)
//         if(x % i == 0)return false;
//     return true;
// }//素数判断
void prime(){
    vis[1] = true;
    for(int i=2;i<=500;i++){
        if(!vis[i])for(int j=2;i*j <= 1000;j++)vis[i*j] = true;
    }
}//将素数判断好，直接使用,可以避免重复计算的缺陷，但内存占用会大一点（影响不大）

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    memset(vis,false,sizeof(vis));
    prime();
    while(cin >> n){
        memset(dp,0,sizeof(dp));
        dp[0] = 1;
        // for(int i=2;i<=n;i++){
        //     for(int j=2;j<=i;j++){
        //         if(!vis[j])dp[i] += dp[i-j];
        //     }//但是会重复计算
        // }
        for(int i=2;i<=n;i++){
            if(!vis[i]){
                for(int j=i;j<=n;j++)dp[j] += dp[j-i];//更新
            }
        }
        cout << dp[n] << endl;
    }
}
#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e3 + 10;
int N,M,K,T;
int dp[maxn][40];
struct G
{
    int val,m;
}a[maxn];


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> T;
    while(T--){
        cin >> N >> M >> K;
        for(int i=1;i<=N;i++)cin >> a[i].val;
        for(int i=1;i<=N;i++)cin >> a[i].m;

        memset(dp,0,sizeof(dp));
        for(int i=1;i<=N;i++){
            for(int j=M;j>=a[i].m;j--){
                int b[40] = {0},c[40] = {0};

                for(int k=1;k<=K;k++){
                    b[k] = dp[j][k];
                    c[k] = dp[j-a[i].m][k] + a[i].val;
                }
                b[K+1] = -1;
                c[K+1] = -1;
                int l = 1,r = 1,to = 1;
                while(to <= K&&(b[l] != -1||c[r] != -1)){
                    if(b[l] > c[r])dp[j][to] = b[l++];
                    else dp[j][to] = c[r++];

                    if(dp[j][to] != dp[j][to-1])to++;
                }
            }
        }
        cout << dp[M][K] << endl;
    }
    return 0;
}
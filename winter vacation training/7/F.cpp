#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 10;
int dp[65][maxn];
struct F
{
    int val;//价格
    int p;//重要度
}ans[65];
int n,m;

int main()
{
    // ios::sync_with_stdio(false);

    while(scanf("%d%d",&m,&n)!=EOF){
        vector<int> a[65];
        int v,p,q;
        m /= 10;

        for(int i=1;i<=n;i++){
            scanf("%d%d%d",&v,&p,&q);
            ans[i].val = v/10;//因为价格都是10的倍数，可以节省时间
            ans[i].p = p;
            a[q].push_back(i);//表示是谁的附件
        }
        //先对附件进行遍历
        for(int i=1;i<=n;i++){
            for(int j=0;j<a[i].size();j++){
                int cnt = a[i][j];
                for(int k=m;k>=ans[cnt].val;k--){
                    dp[i][k] = max(dp[i][k],dp[i][k-ans[cnt].val] + ans[cnt].val * ans[cnt].p);
                }
            }
        }
        //再对主件遍历
        for(int i=0;i<a[0].size();i++){
            int cnt = a[0][i];
            for(int j=m;j>=ans[cnt].val;j--){
                for(int k = j - ans[cnt].val;k>=0;k--){
                    dp[0][j] = max(dp[0][j],dp[cnt][k]+ans[cnt].val*ans[cnt].p+dp[0][j-k-ans[cnt].val]);
                }
            }
        }
        // cout << dp[0][m] << endl;
        printf("%d\n",dp[0][m] * 10);
    }
    return 0;
}
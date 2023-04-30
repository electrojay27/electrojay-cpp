#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e4 + 10;
int dp[maxn];
int n;
int h1,h2,m1,m2;//时间
struct I
{
    int t,c,p;
}a[maxn];
struct more
{
    int t,c;
}b[maxn];


int main()
{
    int T;
    scanf("%d:%d",&h1,&m1);
    scanf("%d:%d",&h2,&m2);
    T = (h2-h1)*60 + (m2-m1);
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d%d%d",&a[i].t,&a[i].c,&a[i].p);
    }
    memset(dp,0,sizeof(dp));
    for(int i=1;i<=n;i++){
        if(!a[i].p){
            //完全背包
            for(int j=a[i].t;j<=T;j++){
                dp[j] = max(dp[j],dp[j-a[i].t]+a[i].c);
            }
        }else if(a[i].p>1){
            //多重背包
            //利用二进制优化
            int to = 1;
            for(int j=1;j<=a[i].p;j*=2){
                b[to].t = a[i].t * j;
                b[to++].c = a[i].c * j;
                a[i].p -= j;
            }
            if(a[i].p > 0){
                b[to].t = a[i].p * a[i].t;
                b[to++].c = a[i].p * a[i].c;
            }
            for(int j=1;j<to;j++){
                for(int k=T;k>=b[j].t;k--){
                    dp[k] = max(dp[k],dp[k-b[j].t]+b[j].c);
                }
            }
        }else{
            //01背包
            for(int j=T;j>=a[i].t;j--){
                dp[j] = max(dp[j],dp[j-a[i].t]+a[i].c);
            }
        }
    }
    printf("%d\n",dp[T]);
}
#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn = 1e5 + 10;
ll a[maxn],vis[maxn];
ll T,n,k;
int main()
{
    scanf("%d",&T);
    while(T--){
        scanf("%lld%lld",&n,&k);
        for(int i=1;i<=n;i++)
            scanf("%lld",&a[i]);
        sort(a+1,a+1+n);
        // memset(vis,0,sizeof(vis));
        // ll sum = 0;
        ll cnt = 0;
        ll l = 1,r = 1;
        while(l <= r&&r <= n){
            while(l<r&&a[r] - a[l] > k)l++;//溢出右移
            cnt += (r - l);
            r ++;
        }
        // for(int i=2;i<=n;i++){
        //     if(a[i]-a[i-1]>k)continue;//超过就跳过
        //     cnt = a[i] - a[i-1];
        //     if(a[i]-a[vis[i-1]+1]<k){
        //         sum += (i - 2 + vis[i-1]);
        //         vis[i] = vis[i-1] + 1;
        //         continue;
        //     }
        //     sum ++;
            
        //     for(int j=vis[i-1]+2;j<i-1;j--){
        //         if(a[i]-a[j]<k){
        //             sum += (i - 1 + j);
        //             vis[i] = j;
        //             continue;
        //         }
        //     }
        // }
        printf("%lld\n",cnt);
    }
}
//第一次超时，时间复杂度是n^2,即10^10
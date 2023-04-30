#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll n;
// bool judge(ll x,ll y){
//     ll cmp = 0;
//     for(int i = 1;i <= x;i ++){
//         cmp = cmp * y + y;
//         if(cmp + 1 >= n&& i < x)return false;
//     }
//     if(cmp + 1 == n|| cmp == n)return true;
//     return false;
// }
int judge(int x,ll y){
    ll cmp = 0,ans = 1;
    for(int i = 1;i <= x;i ++){
        if(n/ans<y)return 0;
        ans *= y;
        cmp += ans;
        if(n - cmp < 0)return 0;
    }
    if(n - cmp == 1|| n - cmp == 0)return 1;
    return -1;
}
// ll pow_zj(ll a,int b){
//     ll ans = 1;
//     for(int i=1;i<=b;i++){
//         ans = ans * a;
//         if(ans > n)return n+1;
//     }
//     return ans;
// }
int main()
{
    while(scanf("%lld",&n)!=EOF){
        // scanf("%lld",&n);
        ll ant = 1,cnt = n - 1;
        for(int i = 2;i <= 50;i ++){
            ll l = 2,r = n;
            while(l <= r){
                ll mid = (l + r) / 2;
                int cmp = judge(i,mid);
                if(cmp == 1){
                    if(ant * cnt > i * mid)ant = i,cnt = mid;
                    if(ant * cnt == i * mid&&i < ant)i = ant,cnt = mid;
                    break;
                }
                if(cmp == 0)r = mid - 1;
                if(cmp == -1)l = mid + 1;
            }
        }
        printf("%lld %lld\n",ant,cnt);
    }
}
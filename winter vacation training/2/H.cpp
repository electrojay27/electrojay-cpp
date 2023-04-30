#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll solve(ll a,ll b,ll p){
    ll ans = 1;
    ll cnt = a;
    while(b > 0){
        if(b & 1){
            ans *= cnt;
            ans %= p;
        }
        cnt *= cnt;
        cnt %= p;
        b >>= 1;
    }
    return ans;
}

int main()
{
    ll a,b,p;
    scanf("%lld%lld%lld",&a,&b,&p);
    printf("%lld^%lld mod %lld=%lld\n",a,b,p,solve(a,b,p));
    return 0;
}
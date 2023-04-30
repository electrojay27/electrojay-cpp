#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll a,b;
double f(ll x){
    double sum;
    sum = 1.0 * b * x + 1.0 * a / sqrt(x + 1.0) ;
    return sum;
}
int main()
{
    scanf("%lld%lld",&a,&b);
    ll l = 0,r = 1e18;
    while(l + 3 < r){//因为三分，又是ll型，所以用3作为分界
        ll midl = l + (r - l) / 3;
        ll midr = r - (r - l) / 3;
        if(f(midl) < f(midr))r = midr;
        else l = midl;
    }
    double cnt;
    for(ll i = l;i <= r;i ++){
        if(i == l)cnt = f(i);
        cnt = min(cnt,f(i));
    }
    printf("%.10f\n",cnt);
}
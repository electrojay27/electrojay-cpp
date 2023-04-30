#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll a,x,mod;

int main()
{
    ios::sync_with_stdio(false);

    while(cin >> a >> x >> mod){
        ll ans = 1;
        ll cnt = a;
        while(x > 0){
            if(x & 1)cnt = (cnt * a)%mod;
            a = a * a;
            a %= mod;
            ans = (ans + cnt)%mod;
            x >>= 1;
        }
        cout << ans << endl;
    }
}
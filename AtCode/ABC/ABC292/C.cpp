#include <bits/stdc++.h>
using namespace std;
#define i64 long long

int n;

bool prime(int x){
    if(x == 1)return false;
    if(x == 2)return true;
    for(int i=2;i<=sqrt(n);i++){
        if(x % i == 0)return false;
    }
    return true;
}

void solve()
{
    i64 ans = 0;
    for(int i=1;i<n;i++){
        int x = i,y=n-i;
        i64 cntx = 0,cnty = 0;
        for(int j=1;j*j <= x;j++){
            if(x % j == 0){
                cntx ++;
                if(j*j != x)cntx++;
            }
        }
        for(int j=1;j*j <= y;j++){
            if(y % j == 0){
                cnty ++;
                if(j*j != y)cnty++;
            }
        }
        ans += cntx * cnty;
    }
    cout << ans << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    while(cin >> n){
        solve();
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
    
int two[30],three[30];

void init()
{
    two[0] = three[0] = 1;
    for(int i = 1;i < 30;i ++){
        two[i] = two[i - 1] * 2;
        three[i] = three[i - 1] * 3;
    }
}

void solve()
{
    int n,m;
    cin >> n >> m;

    if(n == m){
        cout << "YES\n";
        return;
    }
    
    int v = __gcd(n,m);
    n /= v;
    m /= v;
    int a = -1;
    int b = -1;
    for(int i = 0;i < 30;i ++){
        if(n == three[i]){
            a = i;
            break;
        }
    }

    for(int i = 0;i < 30;i ++){
        if(m == two[i]){
            b = i;
            break;
        }
    }

    if(a == -1 || b == -1 || a < b)cout << "NO\n";
    else cout << "YES\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    init();
    while(t --){
        solve();
    }
    return 0;
}
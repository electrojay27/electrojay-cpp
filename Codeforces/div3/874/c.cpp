#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve()
{
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0;i < n;i ++) cin >> a[i];

    sort(a.begin(),a.end());

    if (a[0] % 2 == 0) {
        for (int i = 1;i < n;i ++){
            if (a[i] % 2) {
                cout << "NO\n";
                return;
            }
        }
    }

    cout << "YES\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t --){
        solve();
    }
    return 0;
}
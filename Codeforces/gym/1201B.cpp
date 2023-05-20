#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
    int n;
    cin >> n;

    int x,mx = 0;
    i64 sum = 0;
    for (int i = 0;i < n;i ++) {
        cin >> x;
        sum += x;
        mx = max(mx,x);
    }

    if (sum % 2 || sum < 2 * mx) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
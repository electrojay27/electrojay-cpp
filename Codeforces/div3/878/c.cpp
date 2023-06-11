#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
    int n,k,q;
    cin >> n >> k >> q;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<int> p;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] <= q) {
            cnt ++;
        } else {
            if (cnt >= k) {
                p.push_back(cnt);
            }
            cnt = 0;
        }
    }
    if (cnt >= k) {
        p.push_back(cnt);
    }

    i64 ans = 0;
    for (int i = 0; i < p.size(); i++) {
        i64 res = 1LL * (p[i] - k + 1) * (p[i] - k + 2) / 2;
        // i64 ret = 1LL * 1000000000 * 1000000000;
        // cout << ret << "\n";
        ans += res;
    }

    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
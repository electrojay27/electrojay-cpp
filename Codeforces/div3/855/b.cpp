#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
    int n,k;
    cin >> n >> k;
    string s;
    cin >> s;

    vector<int> a(26,0),b(26,0);
    for (int i = 0; i < n; i++) {
        if (s[i] >= 'a' && s[i] <= 'z') {
            a[s[i] - 'a'] ++;
        } else {
            b[s[i] - 'A'] ++;
        }
    }

    int ans = 0;
    for (int i = 0; i < 26; i++) {
        ans += min(a[i],b[i]);
        if (k >= int(fabs(a[i] - b[i]) / 2)) {
            k -= int(fabs(a[i] - b[i]) / 2);
            // cout << k << "\n";
            ans += int(fabs(a[i] - b[i]) / 2);
            // cout << a[i] << " " << b[i] << "\n";
            // cout << int(fabs(a[i] - b[i]) / 2) << "\n";
        } else {
            ans += k;
            k = 0;
        }
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
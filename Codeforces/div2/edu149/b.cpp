#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    int to = 0;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (!i || s[i - 1] == s[i]) {
            to ++;
        } else {
            ans = max(ans,to);
            to = 1;
        }
    }
    ans = max(ans,to);

    cout << ans + 1 << "\n";
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
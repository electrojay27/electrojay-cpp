#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
    string s;
    cin >> s;
    int x;
    cin >> x;

    string w(s.size(),'1');
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '0') {
            if (i >= x) {
                w[i - x] = '0';
            }
            if (i + x < s.size()) {
                w[i + x] = '0';
            }
        }
    }
    for (int i = 0;i < s.size();i ++) {
        if (s[i] == '1') {
            if (i >= x) {
                if (w[i - x] == '1') continue;
            }

            if (i + x < s.size()) {
                if (w[i + x] == '1') continue;
            }

            cout << "-1\n";
            return;
        }
    }

    cout << w << "\n";
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
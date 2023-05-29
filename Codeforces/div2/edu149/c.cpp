#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
    string s;
    cin >> s;

    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '?') {
            if (!i) {
                if (s[i + 1] == '1') {
                    s[i] = '1';
                } else {
                    s[i] = '0';
                }
            } else {
                if (s[i - 1] == '1' || s[i + 1] == '1') {
                    s[i] = '1';
                } else {
                    s[i] = '0';
                }
            }
        }
    }

    cout << s << "\n";
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
#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
    int n;
    string s;

    cin >> n >> s;
    if (n % 2) {
        cout << -1 << "\n";
        return;
    }

    stack<char> a,b;
    vector<int> ans(n);

    int to = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '(') {
            if (b.empty()) {
                a.push('(');
                ans[i] = ++to;
            } else {
                a.push('(');
            }
        } else {
            if (a.empty()) {
                b.push(')');
                ans[i] = ++to;
            } else {

            }
        }
    }
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
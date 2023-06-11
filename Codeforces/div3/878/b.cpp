#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
    int n,k;
    cin >> n >> k;
    
    int cnt = 1;
    while (k) {
        cnt *= 2;
        k --;
        if (cnt > n) break;
    }

    cout << (cnt > n ? n + 1 : cnt) << "\n";
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
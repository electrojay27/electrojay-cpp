#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<i64> x(n);
    vector<i64> y(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
    }

    vector<i64> dp(2,0);
    for (int i = 0; i < n; i++) {
        vector<i64> a(2,0);
        if (x[i] == 0) {
            a[1] = dp[1];
            a[0] = dp[0];
            a[0] = max(a[0],max(a[0] + y[i],a[1] + y[i]));
        } else {
            a[0] = dp[0];
            a[1] = dp[1];
            a[1] = max(a[1],a[0] + y[i]);
        }

        // cout << a[0] << " " << a[1] << "\n";

        dp = a;
    }

    cout << max(dp[1],dp[0]) << "\n";
}
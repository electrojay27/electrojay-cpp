#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    i64 x,y,z;
    cin >> x >> y >> z;

    string s;
    cin >> s;

    vector<i64> dp(2);
    dp[0] = 0;
    dp[1] = z;
    for (int i = 0; i < s.size(); i++) {
        vector<i64> v(2);
        v[0] = dp[0] + (s[i] == 'a' ? x : y);
        v[1] = dp[1] + (s[i] == 'A' ? x : y);

        v[0] = min(v[0],v[1] + z);
        v[1] = min(v[1],v[0] + z);

        dp = v;
    }

    cout << min(dp[0],dp[1]) << "\n";
}
#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve(){
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0;i < n;i ++) cin >> a[i];

    vector<int> dp(n,1);
    map<int,int> st;
    for (int i = 0;i < n;i ++) {
        if (st.count(a[i] - 1)) {
            dp[i] = dp[st[a[i] - 1]] + 1;
        }

        st[a[i]] = i;
    }

    int ans = 0,to = 0;
    for (int i = 0;i < n;i ++) {
        ans = max(ans,dp[i]);
        if (ans == dp[i]) to = i;
    }

    cout << ans << "\n";

    vector<int> Ans;
    int cnt = a[to];
    for (int i = to;i >= 0;i --) {
        if (a[i] == cnt) {
            Ans.push_back(i);
            cnt --;
        }
    }

    reverse(Ans.begin(),Ans.end());
    for (auto it : Ans) {
        cout << it + 1 << " ";
    }
    cout << "\n";
}

int main () {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
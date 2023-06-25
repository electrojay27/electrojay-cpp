#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,k,q;
    cin >> n >> k >> q;

    vector<i64> a(n,0);
    set<i64> st;
    for (int i = 0; i < q; i++) {
        i64 ans = 0;
        int x;
        i64 y;
        cin >> x >> y;

        x --;

        if (!a[x]) {
            a[x] = y;
            st.insert(y);
        } else {
            st.erase(a[x]);
            a[x] = y;
            st.insert(y);
        }

        if (st.size() > k) {
            auto it = st.begin();
            for (int i = 0; i < k; i++,it ++) {
                if (i >= st.size() - k)ans += *it;
            }
        } else {
            for (auto it : st) {
                ans += it;
            }
        }

        // for (auto it : st) cout << it << " ";
        // cout << "\n";

        cout << ans << "\n";
    }
}
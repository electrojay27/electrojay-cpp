#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

struct node
{
    int a,b;

    bool operator < (const node& t) const{
        if (a != t.a) {
            return a < t.a;
        } else {
            return b > t.b;
        }
    }
};

void solve() {
    int n;
    cin >> n;

    vector<node> p(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i].a >> p[i].b;
    }

    sort(p.begin(),p.end());

    int ans = 0,x = 0;
    for (int i = 0; i < n; i++) {
        if (x < p[i].a) {
            ans += p[i].b;
            x ++;
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
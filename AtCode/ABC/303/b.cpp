#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,m;
    cin >> n >> m;

    vector<vector<int>> a(m,vector<int>(n,0));
    set<pair<int,int>> f;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
            if (j) {
                if (a[i][j] < a[i][j - 1]) {
                    f.insert({a[i][j],a[i][j - 1]});
                } else {
                    f.insert({a[i][j - 1],a[i][j]});
                }
            }
        }
    }

    int ans = ( (n - 1) * n ) / 2 - f.size();
    cout << ans << "\n";
}
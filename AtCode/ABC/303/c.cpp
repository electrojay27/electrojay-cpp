#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,m,h,k;
    cin >> n >> m >> h >> k;

    string s;
    cin >> s;

    set<pair<int,int>> f;
    for (int i = 0; i < m; i ++) {
        int x,y;
        cin >> x >> y;
        f.insert({x,y});
    }

    int dx = 0,dy = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'R') {
            dx ++;
        } else if (s[i] == 'L') {
            dx --;
        } else if (s[i] == 'U') {
            dy ++;
        } else if (s[i] == 'D') {
            dy --;
        }

        h --;

        if (h < 0) {
            cout << "No\n";
            return 0;
        }

        if (f.count({dx,dy}) && h < k) {
            h = k;
            f.erase({dx,dy});
        }
    }

    cout << "Yes\n";
}
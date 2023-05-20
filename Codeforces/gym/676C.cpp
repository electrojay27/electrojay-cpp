#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve(){
    int n,k;
    string s;
    cin >> n >> k >> s;

    queue<int> a;
    queue<int> b;

    int ans = 0;
    int cnt = k;
    for (int i = 0;i < n;i ++) {
        if (s[i] == 'b') {
            if (cnt > 0) {
                cnt --;
            } else {
                ans = max(ans,int(a.size()));
                int to = -1;
                while (!a.empty() && (to == -1 || s[to] == 'a')) {
                    to = a.front();
                    a.pop();
                }
            }
        }
        
        if(s[i] == 'b' && !k)continue;
        a.push(i);
    }

    ans = max(int(a.size()),ans);

    cnt = k;
    for (int i = 0;i < n;i ++) {
        if (s[i] == 'a') {
            if (cnt > 0) {
                cnt --;
            } else {
                ans = max(ans,int(b.size()));
                // cout << b.size() << "\n";
                int to = -1;
                while (!b.empty() && (to == -1 || s[to] == 'b')) {
                    to = b.front();
                    b.pop();
                }
            }
        }

        if(s[i] == 'a' && !k)continue;
        b.push(i);
    }

    ans = max(int(b.size()),ans);
    // cout << b.size() << "\n";

    cout << ans << "\n";
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
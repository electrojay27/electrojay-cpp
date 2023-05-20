#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve(){
    int n;
    string s;
    cin >> n >> s;

    vector<int> a(n,0);
    queue<int> q0,q1;
    int ans = 0;
    for(int i = 0;i < n;i ++){
        if(!i){
            a[i] = ans + 1;
            if (s[i] == '0') q0.push(ans);
            else q1.push(ans);
        }else{
            if (s[i] == '0') {
                if (q1.empty()) {
                    ans ++;
                    q0.push(ans);
                    a[i] = ans + 1;
                } else {
                    int cnt = q1.front();
                    q1.pop();
                    a[i] = cnt + 1;
                    q0.push(cnt);
                }
            } else {
                if (q0.empty()) {
                    ans ++;
                    q1.push(ans);
                    a[i] = ans + 1;
                } else {
                    int cnt = q0.front();
                    q0.pop();
                    a[i] = cnt + 1;
                    q1.push(cnt);
                }
            }

            // cout << "1 = " << q1.size() << " " << "0 = " << q0.size() << "\n";
        }
    }

    cout << ans + 1 << "\n";
    for (auto it : a){
        cout << it << " ";
    }
    cout << "\n";
}

int main () {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
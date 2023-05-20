#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve()
{
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0;i < n;i ++) cin >> a[i];

    int l = 0,r = 0,goal = n;
    if (a[0] == n) goal --;
    if (a[n - 1] == goal) r = n - 1;

    // cout << goal << "\n";

    if (!r) {
        for (int i = 1;i < n;i ++) {
            if(a[i] == goal){
                // cout << i << "\n";
                r = i - 1;
                break;  
            }
        }
    }

    l = r;
    while (l) {
        if (a[l - 1] > a[0]) {
            l --;
        } else {
            break;
        }
    }

    // cout << "r = " << r << " " << "l = " << l << "\n";

    for (int i = r + 1;i < n;i ++) {
        cout << a[i] << " ";
    }

    for (int i = r;i >= l;i --) {
        cout << a[i] << " ";
    }

    for (int i = 0;i < l;i ++) {
        cout << a[i] << " ";
    }

    cout << "\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t --){
        solve();
    }
    return 0;
}
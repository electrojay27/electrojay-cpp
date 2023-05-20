#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

const int maxn = 2e5 + 10;
int id[maxn];

int find(int x){
    return id[x] == x ? id[x] : id[x] = find(id[x]);
}

void solve()
{
    int n;
    cin >> n;

    vector<int> a(n + 1);
    vector<int> v(n + 1,0);
    for (int i = 1;i <= n;i ++) {
        cin >> a[i];
        id[i] = i;
    }

    int mx = 0,mi = 0;

    for (int i = 1; i <= n;i ++) {
        id[find(i)] = find(a[i]);
        // cout << find(i) << " " << find(a[i]) << "\n";
    }

    for (int i = 1;i <= n;i ++) {
        if (find(i) == i)mx ++;
        if (a[a[i]] == i)v[find(i)] ++;
    }

    for (int i = 1;i <= n;i ++){
        if (v[i] && find(i) == i)mi ++;
    }

    mi = mx - (mi == 0 ? 0 : mi - 1);

    cout << mi << " " << mx << "\n";
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
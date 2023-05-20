#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

struct node
{
    int v,id;

    bool operator < (const node & t)const{
        return v < t.v;
    }
};

void solve()
{
    int n,k;
    cin >> n >> k;

    vector<node> a(n);
    vector<int> b(n);
    for (int i = 0;i < n;i ++) cin >> a[i].v,a[i].id = i;
    for (int i = 0;i < n;i ++) cin >> b[i];

    sort(a.begin(),a.end());
    sort(b.begin(),b.end());

    vector<int> ans(n);
    for(int i = 0;i < n;i ++){
        ans[a[i].id] = b[i];
    }

    for (auto it : ans) {
        cout << it << " ";
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
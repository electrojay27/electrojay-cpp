#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,q;
    cin >> n >> q;
    vector<int> a(n);
    vector<int> vis(n,0);
    for(int i = 0;i < n;i ++){
        cin >> a[i];
        if(i > 1 && a[i] <= a[i - 1] && a[i - 1] <= a[i - 2]){
            vis[i] = 1;
        }
    }

    for(int i = 2;i < n;i ++){
        vis[i] += vis[i - 1];
    }

    int l,r;
    while(q --){
        cin >> l >> r;
        int ans = r - l + 1;
        if(ans >= 3){
            ans = ans + vis[l] - vis[r - 1];
        }

        cout << ans << "\n";
    }
}
#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve()
{
    int n,k;
    string s;
    cin >> n >> k >> s;

    sort(s.begin(),s.end());

    if(s[0] != s[k - 1]){
        cout << s[k - 1] << "\n";
        return;
    }

    cout << s[0];

    if(s[k] != s[n - 1]){
        cout << s.substr(k) << "\n";
        return;
    }

    for(int i = 0;i < (n - 1) / k;i ++)cout << s[n - 1];

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
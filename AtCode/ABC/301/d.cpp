#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    i64 t;
    cin >> s >> t;

    i64 ans = 0;
    int l = s.size();
    for(int i = 0;i < l;i ++){
        if(s[i] == '1'){
            ans += (1ll << (l - i - 1));
        }
    }

    if(ans > t){
        cout << -1 << "\n";
        return 0;
    }

    for(int i = 0;i < l;i ++){
        if(s[i] == '?' && ans + (1ll << (l - i - 1)) <= t){
            ans += (1ll << (l - i - 1));
        }
    }

    cout << ans << "\n";

    return 0;
}
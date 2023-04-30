#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
    string s;
    cin >> s;

    int ans = 0;

    int cnt = 0;
    int cmp = 0;

    for(int i = 0;i < s.size();i ++)
    {
        if(s[i] == '1'){
            cmp ++;
        }
        if(s[i] == '0'){
            cnt = max(cmp,cnt);
            cmp = 0;
        }
        if(cmp == s.size()){
            ans = cmp * cmp;
            break;
        }
        if(i == s.size() - 1 && s[i] == '1'){
            for(int i = 0;i < s.size();i ++){
                if(s[i] == '0')break;
                cmp ++;
            }
        }
    }
    cnt = max(cnt,cmp);

    for(int i = 1;i <= (cnt + 1) / 2;i ++){
        ans = max(ans,i * (cnt - i + 1));
    }

    cout << ans << endl;
}

signed main()
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
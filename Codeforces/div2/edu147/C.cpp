#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

const int N = 2e5 + 10;
int f[N];
void init()
{
    f[1] = 1;
    for(int i = 2;i < N;i ++){
        f[i] = 1 + f[i - (i + 1) / 2];
        // cout << two[i] << "\n";
    }
}

int judge(string s,char x)
{
    int ans = 0;
    for(int i = 0;i < s.size();){
        if(s[i] == x){
            i ++;
            continue;
        }
        int to = i ++;
        while(i < s.size() && s[i] != x)i ++;
        ans = max(ans,f[i - to]);
    }
    return ans;
}

void solve()
{
    string s;
    cin >> s;

    int ans = s.size();
    for(int i = 0;i < 26;i ++)ans = min(ans,judge(s,char(i + 'a')));

    cout << ans << "\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    init();
    while(t --){
        solve();
    }
    return 0;
}
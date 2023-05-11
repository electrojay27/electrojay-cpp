#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

int nex[1000001];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    while(cin >> n){
        i64 ans = 0;
        string s;

        unordered_map<string,int> st;
        for(int i = 0;i < n;i ++){

            cin >> s;

            int len = s.size();

            s = '0' + s;

            nex[0] = nex[1] = 0;
            for(int j = 2,k = 0;j <= len;j ++){
                while(k && s[j] != s[k + 1])k = nex[k];
                if(s[j] == s[k + 1])k ++;
                nex[j] = k;
            }

            // cout << len - nex[len] << "\n";

            if(len % (len - nex[len]) == 0){
                string op = s.substr(1,len - nex[len]);
                // cout << op << "\n";
                st[op] ++;
                ans += st[op] - 1;
            }else{
                s = s.substr(1);
                st[s] ++;
                ans += st[s] - 1;
            }
        }

        cout << ans << "\n";
    }
    return 0;
}

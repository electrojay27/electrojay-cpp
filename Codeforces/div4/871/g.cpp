#include <bits/stdc++.h>
using namespace std;
#define pii pair<i64,int>

using i64 = long long;
i64 res[1000010] = {0};
i64 a[2024][2];
void init()
{
    a[1][0] = a[1][1] = 1;
    for(int i = 2;i <= 2023;i ++){
        a[i][0] = a[i - 1][1] + 1;
        a[i][1] = a[i][0] + i - 1;
    }
}

void solve()
{
    i64 n;
    cin >> n;

    if(res[n]){
        cout << res[n] << "\n";
        return;
    }

    int flag = 0;
    for(int i = 1;i <= 2023;i ++){
        if(a[i][0] <= n && n <= a[i][1]){
            flag = i;
            break;
        }
    }

    i64 ans = n * n;
    i64 x = n;
    i64 y = n;
    for(i64 i = flag - 1;i > 0;i --){
        x -= (i + 1);
        y -= i;
        for(i64 j = max(x,a[i][0]);j <= min(a[i][1],y);j ++){
            ans += j * j;
        }
    }    

    res[n] = ans;

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
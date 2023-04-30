#include <bits/stdc++.h>
using namespace std;

int n;
int a[110];
int ans[110];

void solve()
{
    sort(a+1,a+1+n);
    int cmp = 1;
    for(int i=1;i<=n;i++){
        if(i > 1){
            if(a[i] != a[i-1])ans[cmp++] = a[i];
        }else ans[cmp++] = a[i];
    }
    cout << cmp - 1 << endl;
    for(int i=1;i<cmp;i++){
        if(i==1)cout << ans[i];
        else cout << " " << ans[i];
    }
    cout << endl;
}

int main()
{
    while(cin >> n){
        for(int i=1;i<=n;i++)cin >> a[i];
        solve();
    }
    return 0;
}
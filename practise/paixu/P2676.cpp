#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e4 + 10;
int n,b;
int a[maxn];

void solve()
{
    int sum = 0;
    int ans = 0;
    sort(a+1,a+1+n);
    for(int i=n;i>0;i--){
        sum += a[i];
        ans ++;
        if(sum >= b){
            break;
        }
    }
    printf("%d\n",ans);
}

int main()
{
    ios::sync_with_stdio(false);
    while(cin >> n >> b){
        for(int i=1;i<=n;i++)
            cin >> a[i];
        solve();
    }
    return 0;
}
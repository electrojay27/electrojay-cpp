#include <bits/stdc++.h>
using namespace std;
#define i64 long long

const int maxn = 1e6 + 10;
// int a[maxn];
int dp[maxn];//以第i个为底，能容纳多少个
struct Node
{
    int l,d;
    bool operator <(const Node&t)const{
        if(l != t.l)return l < t.l;
        return d < t.d;
    }
}a[maxn];
int t,n;

void solve()
{
    sort(a+1,a+1+n);
    memset(dp,0,sizeof(dp));

    int ans = 0;
    for(int i=1;i<=n;i++){
        // cmp = a[i];
        dp[i] = 1;//自己算上
        for(int j=1;j<i;j++){
            if(a[i].l != a[j].l&&a[i].d > a[j].d){
                dp[i] = max(dp[i],dp[j]+1);
            }
        }
        ans = max(dp[i],ans);
    }
    cout << ans << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin >> t;
    while(t--){
        cin >> n;
        for(int i=1;i<=n;i++){
            cin >> a[i].l >> a[i].d;
            if(a[i].d > a[i].l)swap(a[i].l,a[i].d);//长宽互换
        }
        solve();
    }
    return 0;
}
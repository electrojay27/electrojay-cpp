#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e6 + 10;
int id[maxn];
// int a[maxn];
struct Edge
{
    int u,v;
    int l;
    bool operator < (const Edge&t)const{
        return l < t.l;
    }
}a[maxn];
int n,m;

int find(int x){
    if(id[x] != x)id[x] = find(id[x]);
    return id[x];
}

void solve()
{
    int sum = 0;
    int ans = 0;
    sort(a+1,a+1+m);
    for(int i=1;i<=n;i++)
        id[i] = i;
    for(int i=1;i<=m;i++){
        if(find(a[i].u)!=find(a[i].v)){
            id[find(a[i].u)] = find(a[i].v);
            sum ++;
            ans += a[i].l;
        }
        if(sum == n - 1)break;
    }
    if(sum == n - 1)cout << ans << endl;
    else cout << "orz" << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    while(cin >> n >> m){
        for(int i=1;i<=m;i++)
            cin >> a[i].u >> a[i].v >> a[i].l;
        solve();
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e6 + 10;
int a[maxn];
int n;

void solve()
{
    int flag = 1;
    for(int i=1;i<=n;i++)
        a[i] = fabs(a[i+1] - a[i]);
    sort(a+1,a+n);
    for(int i=1;i<=n-1;i++){
        if(a[i]!=i){
            flag = 0;
            break;
        }
    }
    if(flag)printf("Jolly\n");
    else printf("Not jolly\n");
}

int main()
{
    ios::sync_with_stdio(false);
    while(cin >> n){
        for(int i=1;i<=n;i++)
            cin >> a[i];
        solve();
    }
    return 0;
}
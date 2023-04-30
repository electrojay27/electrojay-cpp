#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int maxn = 1e6 + 10;
ll a[maxn];
// struct Node
// {
    
// }a[maxn];
int n;

ll solve(int x)
{
    if(a[x])return a[x];
    return a[x] = solve(x-1) + solve(x-2);
}

int main()
{
    ios::sync_with_stdio(false);
    memset(a,0,sizeof(a));
    while(cin >> n){
        a[1] = 1;
        a[2] = 2;
        // for(int i=1;i<=n;i++)
        //     cin >> a[i];
        cout << solve(n) << endl;
    }
    return 0;
}
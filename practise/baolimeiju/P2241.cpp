#include <bits/stdc++.h>
using namespace std;
#define i64 long long

// const int maxn = 1e6 + 10;
// int a[maxn];
// struct Node
// {
    
// }a[maxn];
int n,m;

void solve()
{
    i64 sum_1 = 0;//正方形
    i64 sum_2 = 0;//长方形
    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            if(i == j)sum_1 += (n-i) * (m-j);
            else sum_2 += (n-i) * (m-j);
        }
    }
    cout << sum_1 << " " << sum_2 << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    while(cin >> n >> m){
        solve();
    }
    return 0;
}
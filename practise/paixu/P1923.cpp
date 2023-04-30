#include <bits/stdc++.h>
using namespace std;

const int maxn = 5e6 + 10;
int a[maxn];
int ans[maxn];
// struct Node
// {
    
// }a[maxn];
int n,k;

void solve(int l,int r){
    int nl = l,nr = r,mid = a[(l + r)/2];
    int cnt = l;
    while(nl <= nr){
        while(a[nl] < mid)nl++;
        while(a[nr] > mid)nr--;
        if(nl <= nr){
            swap(a[nl],a[nr]);
            nl++;
            nr--;
        }
    }
    if(k <= nr)solve(l,nr);
    else if(nl <= k)solve(nl,r);
    else{
        cout << a[nl - 1] << endl;
    }

}

int main()
{
    ios::sync_with_stdio(false);
    while(cin >> n >> k){
        for(int i=0;i<n;i++)
            cin >> a[i];
        solve(0,n-1);
    }
    return 0;
}
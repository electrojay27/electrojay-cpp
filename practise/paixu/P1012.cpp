#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e6 + 10;
// int a[maxn];
struct Node
{
    string sum;
    int len;
    bool operator < (const Node&t)const{
        // int cnt,cmp,flag;
        // if(len > t.len)cnt = t.len,cmp = len,flag = 1;
        // else cnt = len,cmp = t.len,flag = 0;
        // for(int i=0;i<cnt;i++){
        //     if(sum[i] != t.sum[i])return sum[i] > t.sum[i];
        // }
        // if(cnt == cmp)return len >= t.len;
        // for(int i=cnt;i<cmp;i++){
        //     if(flag){
        //         if(sum[i] != t.sum[i-cnt])return sum[i] >  t.sum[i-cnt];
        //     }else{
        //         if(sum[i-cnt] != t.sum[i])return sum[i-cnt] >  t.sum[i];
        //     }
        // }
        // return len < t.len;
        return (sum + t.sum > t.sum + sum);
    }
}a[maxn];
int n;

void solve()
{
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++)cout << a[i].sum;
    cout << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    while(cin >> n){
        for(int i=1;i<=n;i++){
            cin >> a[i].sum;
            a[i].len = a[i].sum.size();
        }
        solve();
    }
    return 0;
}
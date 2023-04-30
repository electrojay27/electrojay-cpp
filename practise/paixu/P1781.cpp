#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e6 + 10;
// int a[maxn];
string op;
struct Node
{
    string sum;
    int len;
    int id;
    bool operator < (const Node& t)const{
        if(len!=t.len)return len > t.len;
        else{
            for(int i=0;i<len;i++){
                if(sum[i] != t.sum[i]){
                    return sum[i] > t.sum[i];
                }
            }
        }
        return id < t.id;
    }
}a[25];

int n;

void solve()
{
    sort(a+1,a+1+n);
    cout << a[1].id << endl << a[1].sum << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    while(cin >> n){
        for(int i=1;i<=n;i++){
            cin >> a[i].sum;
            a[i].id = i;
            a[i].len = a[i].sum.size();
        }
        solve();
    }
    return 0;
}
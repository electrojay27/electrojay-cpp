#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e6 + 10;
// int a[maxn];
struct Node
{
    int c,m,e,all,id;
    bool operator < (const Node& t) const {
        if(all != t.all)return all > t.all;
        else if(c != t.c)return c > t.c;
        else return id < t.id;
    }
}a[310];
int n;

// bool cmp(Node a,Node b){
//     if(a.all != b.all)return a.all > b.all;
//     else if(a.c != b.c)return a.c > b.c;
//     return a.id < b.id;
// }

void solve()
{
    sort(a+1,a+1+n);
    for(int i=1;i<=5;i++)cout << a[i].id << " " << a[i].all << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> a[i].c >> a[i].m >> a[i].e;
        a[i].all = a[i].c + a[i].m + a[i].e;
        a[i].id = i;
    }
    solve();
        // sort(a+1,a+1+n,cmp);
        // for(int i=1;i<=5;i++)cout << a[i].id << " " << a[i].all << endl;
    return 0;
}
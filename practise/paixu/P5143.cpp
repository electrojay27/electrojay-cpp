#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e6 + 10;
// int a[maxn];
struct Node
{
    int x,y,z;
    bool operator < (const Node&t)const{
        return z < t.z;
    }
}a[maxn];
int n;

void solve()
{
    double sum = 0;
    sort(a+1,a+1+n);
    for(int i=2;i<=n;i++){
        sum += sqrt(pow(a[i].x-a[i-1].x,2)+pow(a[i].y-a[i-1].y,2)+pow(a[i].z-a[i-1].z,2));
    }
    cout << fixed << setprecision(3) <<sum << endl;
    //fixed << setprecision(3) 是cout用来保留几位有效数字，其中fixed是保留0
}

int main()
{
    ios::sync_with_stdio(false);
    while(cin >> n){
        for(int i=1;i<=n;i++)
            cin >> a[i].x >> a[i].y >> a[i].z;
        solve();
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e6 + 10;
// int a[maxn];
struct Node
{
    int id;
    int score;
    bool operator < (const Node&t)const{
        if(score!=t.score)return score > t.score;
        return id < t.id;
    }
}a[maxn];
int n,m;

void solve()
{
    sort(a+1,a+1+n);
    int cnt;
    cnt = floor(m * 1.5);
    for(int i=cnt+1;i<=n;i++){
        if(a[i].score != a[cnt].score)break;
        cnt++;
    }
    cout << a[cnt].score << " " << cnt << endl;
    for(int i=1;i<=cnt;i++)cout << a[i].id << " " << a[i].score << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    while(cin >> n >> m){
        for(int i=1;i<=n;i++)
            cin >> a[i].id >> a[i].score;
        solve();
    }
    return 0;
}
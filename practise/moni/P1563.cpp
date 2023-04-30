#include <bits/stdc++.h>
using namespace std;

int n,m,x,y;

// void solve()
// {
//     int cnt = 0;//定义起点
//     for(int i=1;i<=m;i++){
//         scanf("%d%d",&x,&y);
//         if(x == 0){
//             if(a[cnt].first==0)cnt = (cnt + a.size() - y + 1) % n;
//             else cnt = (cnt + y) % n;
//         }else{
//             if(a[cnt].first == 0)cnt = (cnt + y) % n;
//             else cnt = (cnt + a.size() - y + 1) % n;
//         }
//     }
//     cout << a[cnt].second << endl;
// }

int main()
{
    ios::sync_with_stdio(false);
    while(cin >> n >> m){
        pair<int,string> p;
        vector<pair<int,string>> a;
        for(int i=1;i<=n;i++){
            cin >> p.first >> p.second;
            a.push_back(p);
        }
        int cnt = 0;//定义起点
        for(int i=1;i<=m;i++){
            cin >> x >> y;
            if(x == 0){
                if(a[cnt].first==0)cnt = (cnt + a.size() - y) % n;
                else cnt = (cnt + y) % n;
            }else{
                if(a[cnt].first == 0)cnt = (cnt + y) % n;
                else cnt = (cnt + a.size() - y) % n;
            }
        }
        cout << a[cnt].second << endl;
    }
    return 0;
}
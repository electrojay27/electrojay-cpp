#include <bits/stdc++.h>
using namespace std;

int r[110];//red
int y[110];//yellow
int vis[110];
int n,q;

// void solve()
// {
    
//     cout << endl;
// }

int main()
{
    ios::sync_with_stdio(false);
    while(cin >> n >> q){
        memset(vis,0,sizeof(vis));
        memset(r,0,sizeof(r));
        memset(y,0,sizeof(y));
        int c,x;
        while(q--){
            cin >> c >> x;
            if(c == 1){
                y[x]++;
                if(y[x]==2)vis[x] = 1;
            }else if(c == 2){
                r[x]++;
                if(r[x]==1)vis[x] = 1;
            }else{
                if(vis[x])cout << "Yes" << endl;
                else cout << "No" << endl;
            }
        }
        // solve();
    }
    return 0;
}
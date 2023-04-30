#include <bits/stdc++.h>
using namespace std;

int n;
string op;

void solve()
{
    pair<int,int> p(0,0);//起点
    map<pair<int,int>,int> mp;
    mp[p] = 1;//标记起点
    int flag = 0;

    for(int i=1;i<=n;i++){
        if(op[i] == 'R'){
            p.first ++;
            mp[p] ++;
        }else if(op[i] == 'L'){
            p.first --;
            mp[p] ++;
        }else if(op[i] == 'U'){
            p.second ++;
            mp[p] ++;
        }
        else if(op[i] == 'D'){
            p.second --;
            mp[p] ++;
        }
        if(mp[p] > 1){
            flag = 1;
            break;
        }
    }
    if(flag)printf("Yes\n");
    else printf("No\n");
}

int main()
{
    while(cin >> n){
        cin >> op;
        op = '\0' + op;
        solve();
    }
    return 0;
}
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
using namespace std;

// #define eps 1e-6;
int n;
char ans[2500][2500];//用来存储第i个盒子的形状

int ming(int x){
    int ans = 1;
    for(int i=1;i<=x;i++)
        ans *= 3;
    return ans;
}

void solve(int x,int y,int cnt){
    if(cnt == 1){
        ans[x][y] = 'X';
        return;
    }else{
        int cmp = ming(cnt-2);
        solve(x,y+2*cmp,cnt-1);
        solve(x+2*cmp,y,cnt-1);
        solve(x+2*cmp,y+2*cmp,cnt-1);
        solve(x+cmp,y+cmp,cnt-1);
        solve(x,y,cnt-1);
        //利用dfs，因为最开始定义的是(0，0)，所以先去定位每个分形的(0,0)点位，再以中心为去逐步搜索
    }
}

int main()
{
    ios::sync_with_stdio(false);
    for(int i=0;i<2200;i++){
        for(int j=0;j<2200;j++){
            ans[i][j] = ' ';
        }
    }
    while(cin >> n && n != -1){
        int cmp = ming(n-1);
        solve(0,0,n);
        for(int i=0;i<cmp;i++){
            for(int j=0;j<cmp;j++){
                cout << ans[i][j];
            }cout << endl;
        }cout << "-" << endl;
    }
}
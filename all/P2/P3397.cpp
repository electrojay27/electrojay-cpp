#include <bits/stdc++.h>
using namespace std;

int vis[3][50];//0->竖 1->对角线（从左到右） 2->对角线（从右到左）
int c[20];//表示每一行的列序号
int n,ans;

void solve(int cur){
    if(cur == n+1){
        if(ans<3){
            for(int i=1;i<=n;i++)cout << c[i] << " ";
            cout << endl;
        }
        ans ++;
    }//到达最后一点
    else{
        for(int i=1;i<=n;i++){
            if(!vis[0][i]&&!vis[1][cur+i]&&!vis[2][cur-i+2*n]){
                c[cur] = i;
                vis[0][i] = vis[1][cur+i] = vis[2][cur-i+2*n] = 1;//标记
                solve(cur+1);
                vis[0][i] = vis[1][cur+i] = vis[2][cur-i+2*n] = 0;//回溯
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    while(cin >> n){
        ans = 0;
        memset(vis,0,sizeof(vis));
        solve(1);
        cout << ans << endl;
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
#define i64 long long

i64 a[4][4];//地图
i64 dx[4] = {1,0,-1,0};
i64 dy[4] = {0,1,0,-1};
i64 n;
// bool vis[1][1];

void solve(){
    map<i64,i64> vis;
    queue<i64> q;
    q.push(n);//先记录初始地图
    vis[n] = 0;
    while(!q.empty()){
        i64 s = q.front();
        q.pop();
        n = s;
        int x,y;//空格的位置
        if(s == 123804765)break;
        for(i64 i=2;i>=0;i--){
            for(i64 j=2;j>=0;j--){
                a[i][j] = n % 10;
                n /= 10;
                if(!a[i][j])x = i,y = j;
            }
        }

        for(i64 i=0;i<4;i++){//进行位移
            i64 cnt = 0;
            i64 nx = x + dx[i],ny = y + dy[i];
            if(nx < 0||nx > 2||ny < 0||ny > 2)continue;
            swap(a[nx][ny],a[x][y]);
            for(i64 i=0;i<3;i++){
                for(i64 j=0;j<3;j++){
                    cnt = cnt * 10 + a[i][j];
                }
            }//还原数字
            if(!vis.count(cnt)){
                q.push(cnt);
                vis[cnt] = vis[s] + 1;
            }
            swap(a[nx][ny],a[x][y]);//回溯
        }
    }
    cout << vis[123804765] << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    while(cin >> n){
        solve();
    }
    return 0;
}
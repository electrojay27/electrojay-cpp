#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <cstdlib>
using namespace std;

int dp[110][100];
int ma[110][100];
int r,c,ans;
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

int dfs(int x,int y){
    if(dp[x][y]!=-1)return dp[x][y];//记忆化搜索
    dp[x][y] = 1;
    for(int i=0;i<4;i++){
        if(x+dx[i]>0&&y+dy[i]>0&&x+dx[i]<=r&&y+dy[i]<=c&&ma[x][y]>ma[x+dx[i]][y+dy[i]])
            dp[x][y] = max(dfs(x+dx[i],y+dy[i])+1,dp[x][y]);//通过寻找距离最近的一个距离差为1的点，否则依旧不变
    }return dp[x][y];
}

int main()
{
    while(scanf("%d%d",&r,&c)!=EOF){
        memset(dp,-1,sizeof(dp));
        ans = 0;
        for(int i=1;i<=r;i++)
            for(int j=1;j<=c;j++)
                scanf("%d",&ma[i][j]);
        for(int i=1;i<=r;i++){
            for(int j=1;j<=c;j++){
                ans = max(dfs(i,j),ans);
            }
        }printf("%d\n",ans);
    }return 0;
}
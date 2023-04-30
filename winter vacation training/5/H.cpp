#include <bits/stdc++.h>
using namespace std;
int dp[110][110],ma[110][110],r,c,ans;
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};//移动步数
int DFS(int x,int y){
    if(dp[x][y])return dp[x][y];//记忆化搜索
    dp[x][y] = 1;
    for(int i=0;i<4;i++){
        if(x+dx[i]>0&&y+dy[i]>0&&x+dx[i]<=r&&y+dy[i]<=c&&ma[x][y]>ma[x+dx[i]][y+dy[i]])//限定在范围内
            dp[x][y] = max(DFS(x+dx[i],y+dy[i])+1,dp[x][y]);//通过寻找距离最近的一个距离差为1的点，否则依旧不变
    }return dp[x][y];
}
int main()
{
    while(scanf("%d%d",&r,&c)!=EOF){
        memset(dp,0,sizeof(dp));//初始化
        ans = 0;
        for(int i=1;i<=r;i++)
            for(int j=1;j<=c;j++)
                scanf("%d",&ma[i][j]);//记录地图
        for(int i=1;i<=r;i++){
            for(int j=1;j<=c;j++){
                ans = max(DFS(i,j),ans);//遍历每个点寻找最大值
            }
        }printf("%d\n",ans);
    }
}
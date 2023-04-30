#include <bits/stdc++.h>
using namespace std;
char ma[10][10];
int vis[10][10];
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
int n,m,t;
int ax,ay,bx,by;
int flag;
void DFS(int x,int y,int T){
    // if((t-T-(abs(x-bx)+abs(y-by)))%2!=0) return;
    if(x==bx&&y==by){
        if(T==t)flag = 1;
        return;
    }//判断是否满足条件
    if(x<0||y<0||y>=m||x>=n)return;//去除超出范围的点
    /*奇偶剪枝*/
    int a = abs(bx-x) + abs(by-y);
    int b = abs(t-T);
    int cnt = abs(a-b);
    if(cnt%2!=0)return;

    for(int i=0;i<4;i++){
        int xx = x+dx[i];
        int yy = y+dy[i];
        if(xx>=0&&yy>=0&&xx<n&&yy<m){//再次判断
            if(ma[xx][yy]=='X'||vis[xx][yy])continue;
            vis[xx][yy] = 1;//判重标记
            DFS(xx,yy,T+1);
            if(flag)return;
            vis[xx][yy] = 0;//回溯
        }
    }
}
int main()
{
    while(scanf("%d%d%d",&n,&m,&t)!=EOF&&(n&&m&&t)){
        flag = 0;//记录状态
        int w = 0;
        memset(vis,0,sizeof(vis));
        memset(ma,'\0',sizeof(ma));
        for(int i=0;i<n;i++){
            cin >> ma[i];
            for(int j=0;j<m;j++){
                if(ma[i][j]=='X')w++;//记录x数
                if(ma[i][j]=='S')ax=i,ay=j;//定位起点
                if(ma[i][j]=='D')bx=i,by=j;//定位终点
            }
        }
        if(n*m-w<=t){
            printf("NO\n");
            continue;
        }//初步判断
        vis[ax][ay] = 1;//记录起点
        DFS(ax,ay,0);
        if(flag)printf("YES\n");
        else printf("NO\n");
    }
}
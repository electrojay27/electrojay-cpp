#include <bits/stdc++.h>
using namespace std;

int dx[3] = {0,1,-1};
int dy[3] = {0,1,-1};
char mp[110][110];
int n,m;

void DFS(){

}

void solve(){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(mp[i][j] == '*'){
                for(int k=0;k<3;k++){
                    for(int l=0;l<3;l++){
                        if(k == l&&k == 0)continue;
                        if(i + dy[k] < 1||j + dx[l] < 1)continue;
                        if(mp[i + dy[k]][j + dx[l]] != '*'){
                            mp[i + dy[k]][j + dx[l]] ++;
                        }
                    }
                }
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            printf("%c",mp[i][j]);
        }printf("\n");
    }
}

int main()
{
    while(scanf("%d%d",&n,&m)!=EOF){
        // char op;
        getchar();
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                scanf("%c",&mp[i][j]);
                if(mp[i][j] == '?')mp[i][j] = '0'; 
            }getchar();
        }
        solve();
    }
    return 0;
}
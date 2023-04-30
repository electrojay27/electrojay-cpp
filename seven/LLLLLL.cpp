#include <bits/stdc++.h>
using namespace std;
char s[35][35];
int main()
{
    int n,m;
    while(scanf("%d%d",&n,&m)!=EOF){
        for(int i=1;i<=n;i++)
            scanf("%s",s[i]);
        int flag = 1;//判断
        int cnt = 0;
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                for(int k=0;k<m;k++){
                    if(s[i][k]!='o'&&s[j][k]!='o'){
                        flag = 0;
                        break;
                    }
                }
                if(flag)cnt++;
                else flag = 1;
            }
        }printf("%d\n",cnt);
    }
}
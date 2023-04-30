#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
struct lu
{
    int b,e,t;
    bool operator < (const lu&that) const{
        return t < that.t;
    }
}p[maxn];
int id[maxn];
int find(int a){
    if(id[a]==a)return id[a];
    return id[a] = find(id[a]);
}
void he(int a,int b){
    id[find(a)] = find(b);
}
int n,m;
int main()
{
    while(scanf("%d%d",&n,&m)!=EOF){
        for(int i=1;i<=n;i++)
            id[i] = i;
        for(int i=1;i<=m;i++)
            scanf("%d%d%d",&p[i].b,&p[i].e,&p[i].t);
        sort(p+1,p+1+m);
        int cnt = -1;
        for(int i=1;i<=m;i++){
            he(p[i].b,p[i].e);
            if(i>=n-1){
                int bz = find(1);
                int flag = 1;
                for(int j=2;j<=n;j++){
                    if(bz!=find(j)){
                        flag = 0;
                        break;
                    }
                }if(flag){cnt = p[i].t;break;}
            }
        }printf("%d\n",cnt);
    }
}
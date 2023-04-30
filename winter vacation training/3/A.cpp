#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e4 + 10;
int id[maxn];
int n,m;
int find(int a){
    // if(id[a]==a)return id[a];
    // return id[a] = find(id[a]);
    return id[a] == a ? id[a] : id[a] = find(id[a]);
}
void he(int a,int b){
    id[find(a)] = find(b);
}
int main()
{
    while(scanf("%d%d",&n,&m)!=EOF){
        for(int i=1;i<=n;i++)
            id[i] = i;
        for(int i=1;i<=m;i++){
            int a,b,c;
            scanf("%d%d%d",&a,&b,&c);
            if(a==1)he(b,c);
            else{
                if(find(b)==find(c))printf("Y\n");
                else printf("N\n");
            }
        }
    }return 0;
}
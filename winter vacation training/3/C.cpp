#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e3 + 10;
int id[maxn];
int find(int a){
    if(id[a]==a)return id[a];
    return id[a] = find(id[a]);
}
void he(int a,int b){
    id[find(a)] = find(b);
}
int n,m,p;
int main()
{
    while(scanf("%d%d%d",&n,&m,&p)!=EOF){
        for(int i=1;i<=n;i++)
            id[i] = i;
        int a,b;
        for(int i=1;i<=m;i++){
            scanf("%d%d",&a,&b);
            he(a,b);
        }
        for(int i=1;i<=p;i++){
            scanf("%d%d",&a,&b);
            if(find(a)==find(b))printf("Yes\n");
            else printf("No\n");
        }
    }return 0;
}
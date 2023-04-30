#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e4 + 10;
int id[maxn];
int sum = 0;
int all = 0;
int n,m,k;
struct mht
{
    int u,v;
    int cost;
    bool operator <(const mht& t)const{
       return cost < t.cost;
    }
}p[maxn];
int find(int x){
    if(id[x] != x)id[x] = find(id[x]);
    return id[x];
}
void solve(){
    sort(p+1,p+1+m);
    for(int i=1;i<=n;i++)id[i] = i;
    for(int i=1;i<=m;i++){
        if(find(p[i].u)!=find(p[i].v)){
            id[find(p[i].u)] = find(p[i].v);
            sum ++;
            all += p[i].cost;
            if(sum == n - k)break;
        }
    }
    if(sum == n - k)printf("%d\n",all);
    else printf("No Answer\n");
}
int main()
{
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=m;i++)scanf("%d%d%d",&p[i].u,&p[i].v,&p[i].cost);
    solve();
    return 0;
}
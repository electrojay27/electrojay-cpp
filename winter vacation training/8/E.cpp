#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
int id[maxn];
int sum = 0;
int mx = 0;
int n,m;
struct lu
{
    int u,v;
    int cost;
    bool operator <(const lu& t)const{
        return cost < t.cost;
    }
}p[maxn];
// bool cmp(lu a,lu b){
//     return a.cost < b.cost;
// }
int find(int x){
    if(id[x] != x)id[x] = find(id[x]);
    return id[x];
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i <= n;i ++)id[i] = i;
    for(int i=1;i<=m;i ++)scanf("%d%d%d",&p[i].u,&p[i].v,&p[i].cost);
    // sort(p+1,p+1+m,cmp);
    sort(p+1,p+1+m);
    for(int i=1;i<=m;i++){
        if(find(p[i].u)!=find(p[i].v)){
            id[find(p[i].u)]=find(p[i].v);
            if(mx < p[i].cost)mx = p[i].cost;
            sum ++;
            if(sum == n - 1)break;
        }
    }
    printf("%d %d\n",sum,mx);
}
#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 10;
int id[maxn];
int sum = 0;
int all = 0;
int n,m,cnt,num;
struct lw
{
    int u,v;
    int cost;
    bool operator <(const lw& t)const{
       return cost < t.cost;
    }
}p[maxn];
int find(int x){
    if(id[x] != x)id[x] = find(id[x]);
    return id[x];
}
void solve(){
    sort(p+1,p+1+cnt);
    for(int i=1;i<=m;i++)id[i] = i;
    for(int i=1;i<=cnt;i++){
        if(find(p[i].u)!=find(p[i].v)){
            id[find(p[i].u)] = find(p[i].v);
            sum ++;
            all += p[i].cost;
            // if(sum == n - k)break;
        }
    }
    // if(sum == n - k)printf("%d\n",all);
    // else printf("No Answer\n");
    printf("%d\n",all + n * (m - sum));
}
int main()
{
    scanf("%d%d",&n,&m);
    int x;
    cnt = 1;
    num = 0;
    for(int i=1;i<=m;i++){
        for(int j=1;j<=m;j++){
            // scanf("%d%d%d",&x,&y,&z);
            scanf("%d",&x);
            if(i >= j||x == 0||x > n)continue;
            p[cnt].u = i;
            p[cnt].v = j;
            p[cnt].cost = x;
            // if(p[cnt].cost >= n)num++;
            cnt ++;
        }
    }
    solve();
    return 0;
}
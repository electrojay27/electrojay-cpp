#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 10;
int lu_sum = 0;//路线总数
int lu_all = 0;//权值综合
int id[maxn];//序号
int n,m;
int cnt = 1;
struct dian
{
    int x,y;
}q[maxn];
double longth(int a,int b){
    return sqrt(pow(q[a].x-q[b].x,2)+pow(q[a].y-q[b].y,2));
}
struct lu
{
    int u,v;
    // int cost;
    double l;
    //bool operator <(const lu& t)const{
    //    return cost < t.cost;
    //}
}p[maxn];
bool cmp(lu a,lu b){
    return a.l < b.l;
}//也可以用重载运算符
int find(int x){
    if(id[x] != x)id[x] = find(id[x]);
    return id[x];
}
void solve(){
    sort(p+1,p+cnt+1,cmp);
    for(int i=1;i<=n;i++)id[i] = i;
    for(int i=1;i<=cnt;i++){
        if(find(p[i].u)!=find(p[i].v)){
            id[find(p[i].u)] = find(p[i].v);
            lu_sum ++;
            // lu_all += p[i].l;
            if(lu_sum == n-m+1){
                printf("%.2f\n",p[i].l);
                break;
            }
        }
    }
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)scanf("%d%d",&q[i].x,&q[i].y);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            p[cnt].u = i;
            p[cnt].v = j;
            p[cnt++].l = longth(i,j);
        }
    }
    cnt --;
    solve();
    return 0;
}
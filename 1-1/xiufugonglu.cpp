#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;//注意数据不要定义错了
struct lu
{
    int b,e,t;
    bool operator < (const lu&that) const{
        return t<that.t;
    }//进行时间上的排序
}p[maxn];
// bool cmp(const lu &a,const lu &b){
//     return a.t<b.t;
// }
int id[1010],n,m,cnt,flag;
int find(int a){
    if(id[a]==a)return id[a];
    return id[a] = find(id[a]);
}//寻找
// void bing(int a,int b){
//     id[find(a)] = find(b);
// }//合并，两个村子有路，合在一起
int main()
{
    while(scanf("%d%d",&n,&m)!=EOF){
        for(int i=1;i<=n;i++)
            id[i] = i;
        for(int i=1;i<=m;i++)
            scanf("%d%d%d",&p[i].b,&p[i].e,&p[i].t);
        sort(p+1,p+1+m);//进行排序
        flag = 0;
        cnt = -1;
        for(int i=1;i<=m;i++){
            if(find(p[i].b)!=find(p[i].e))id[find(p[i].b)] = find(p[i].e),n--;//进行合并(排除相同的情况),然后满足条件的路需要n-1条
            if(n==1){
                cnt = p[i].t;
                break;
            }//满足条件时输出t
        }printf("%d\n",cnt);
    }return 0;
}

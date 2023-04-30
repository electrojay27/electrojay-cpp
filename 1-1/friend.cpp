#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e4 + 10;
// int id1[maxn],id2[maxn];//1男生；2女生
// int id[maxn];
map<int,int> id;//利用map的任意下标
int find(int a){
    // if(x==1){
    //     if(id1[a]==a)return id1[a];
    //     return id1[a] = find(id1[a],1);
    // }else{
    //     a = -a;//变成整数
    //     if(id2[a]==-a)return id2[a];
    //     return id2[a] = find(id2[a],-1);
    // }
    if(id[a]==a)return id[a];
    return id[a] = find(id[a]);
}
int n,m,p,q,x,y,cnt1,cnt2;
int main()
{
    while(scanf("%d%d%d%d",&n,&m,&p,&q)!=EOF){
        cnt1 = cnt2 = 1;//初始有一对
        for(int i=-1*m;i<=n;i++)
            id[i] = i;//男生先记录//利用map可以直接全部读取
        // for(int i=1;i<=m;i++)
        //     id2[i] = -i;
        for(int i=1;i<=p;i++){
            scanf("%d%d",&x,&y);
            // if(find(x)==find(1)||find(y)==find(1))cnt1++;
            id[find(x)] = find(y);
        }//男生统计
        // for(int i=1;i<=m;i++)
        //     id[i] = i;//女生记录
        for(int i=1;i<=q;i++){
            scanf("%d%d",&x,&y);
            // x = -x;
            // y = -y;//取绝对值
            // if(find(x)==find(-1)||find(y)==find(-1))cnt2++;
            id[find(x)] = find(y);
        }
        for(int i=2;i<=n;i++)
            if(find(1)==find(i))cnt1++;
        for(int i=-2;i>=-m;i--)
            if(find(-1)==find(i))cnt2++;
        if(cnt1>cnt2)printf("%d\n",cnt2);
        else printf("%d\n",cnt1);
    }
}
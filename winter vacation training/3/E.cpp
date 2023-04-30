#include <bits/stdc++.h>
using namespace std;
const int maxn = 4e3 + 10;
// int idm[maxn];
// int idw[maxn];
// int findm(int a){
//     if(idm[a] == a)return idm[a];
//     return  idm[a] = findm(idm[a]);
// }
// int findw(int a){
//     if(idw[a] == a)return idw[a];
//     return  idw[a] = findw(idw[a]);
// }
map<int,int> id;
int find(int a){
    if(id[a] == a)return id[a];
    return id[a] = find(id[a]);
}
int n,m,p,q;
int main()
{
    while(scanf("%d%d%d%d",&n,&m,&p,&q)!=EOF){
        for(int i=1;i<=n;i++){
            // idm[i] = i;
            id[i] = i;
        }
        for(int i=1;i<=m;i++){
            // idw[i] = i;
            id[-i] = -i;
        }
        int a,b;
        for(int i=1;i<=p;i++){
            scanf("%d%d",&a,&b);
            id[find(a)] = find(b);
        }
        for(int i=1;i<=q;i++){
            scanf("%d%d",&a,&b);
            // idw[findw(-a)] = findw(-b);
            id[find(a)] = find(b);
        }
        int cnt1,cnt2;
        cnt1 = cnt2 = 0;
        for(int i=1;i<=n;i++){
            if(find(i)==find(1))cnt1++;
        }
        for(int i=1;i<=m;i++){
            if(find(-i)==find(-1))cnt2++;
        }
        int cnt;
        cnt = min(cnt1,cnt2);
        printf("%d\n",cnt);
    }
}
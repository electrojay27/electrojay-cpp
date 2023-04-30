#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 10;
int a[maxn];
int n,m;
int main()
{
    cin >> n >> m;
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    for(int i=1;i<=m;i++){
        char op[10];
        int x,y;
        scanf("%s%d%d",&op,&x,&y);
        if(op[0]=='Q'){
            int cnt = 0;
            for(int j=x;j<=y;j++)cnt = max(cnt,a[j]);
            printf("%d\n",cnt);
        }else{
            if(a[x]<y)a[x] = y;
        }
    }return 0;
}
// int g[maxn],t[4*maxn];
// void huisu(int d){
//     t[d] = max(t[2*d],t[2*d+1]);
// }
// void build(int l,int r,int d){
//     if(l==r){
//         t[d] = g[l];
//         return;
//     }
//     int mid = (l+r)/2;
//     build(l,mid,d*2);
//     build(mid+1,r,d*2+1);
//     huisu(d);
// }
// void update(int L,int s,int l,int r,int d){
//     if(l==r){
//         if(t[d]<s)t[d] = s;
//         return;
//     }
//     int mid = (l+r)/2;
//     if(l<=mid)update(L,s,l,mid,d*2);
//     else update(L,s,mid+1,r,d*2+1);
//     huisu(d);
// }
// int query(int L,int R,int l,int r,int d){
//     if(L<=l && R>=r)return t[d];
//     int mid = (l+r)/2;
//     int cnt = 0;
//     if(L<=mid) cnt = max(cnt,query(L,R,l,mid,d*2));
//     if(R>mid) cnt = max(cnt,query(L,R,mid+1,r,2*d+1));
//     return cnt;
// }
// int main()
// {
//     int n,m,a,b;
//     scanf("%d%d",&n,&m)
//     for(int i=1;i<=n;i++)scanf("%d",&g[i]);
//     build(1,n,1);
//     while(m--){
//         char op;
//         scanf("%c",&op);
//         scanf("%d%d",&a,&b);
//         if(op=='Q')printf("%d\n",query(a,b,1,n,1));
//         else update(a,b,1,n,1);
//     }return 0;
// }
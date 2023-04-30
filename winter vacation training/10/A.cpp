#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn = 5e5 + 10;
// int a[maxn];
// int p[maxn];
// int n,m;
// int op,x,y;
// int main()
// {
//     scanf("%d%d",&n,&m);
//     a[0] = 0;
//     for(int i=1;i<=n;i++){
//         scanf("%d",&a[i]);
//         a[i] += a[i-1];//前缀和
//     }
//     memset(p,0,sizeof(p));//差分数组
//     for(int i=1;i<=n;i++){
//         scanf("%d%d%d",&op,&x,&y);
//         if(op == 1)p[x] += y;
//         else{
//             int cnt = a[y] - a[x-1];
//             for(int i=x;i<=y;i++)cnt += p[i];
//             printf("%d\n",cnt);
//         }
//     }
// }
int a[maxn],t[4*maxn];
int ans;
// void push_up(int l,int r,int d){
//     t[d] = t[2*d] + t[2*d+1];
// }
void bulid(int l,int r,int d){
    if(l==r){
        t[d]=a[l];
        return;
    }
    int mid = (l+r)>>1;//>>1相当于除以2
    bulid(l,mid,2*d);
    bulid(mid+1,r,2*d+1);
    t[d] = t[2*d] + t[2*d+1];
}//建立树
void update(int d,int dl,int dr,int x,int k){
    if(dl == dr&&dl == x){
        t[d] += k;
        return;
    }
    int mid = (dl + dr)>>1;
    if(mid >= x)update(2*d,dl,mid,x,k);
    if(mid < x)update(2*d+1,mid+1,dr,x,k);
    t[d] = t[2*d] + t[2*d+1];
}
int query(int d,int dl,int dr,int l,int r){
    if(l == dl&&dr == r)return t[d];
    if(l > dr||r < dl)return 0;
    int mid = (dl + dr)>>1;
    if(r <= mid)return query(2*d,dl,mid,l,r);
    else if(l > mid)return query(2*d+1,mid+1,dr,l,r);
    else return query(2*d,dl,mid,l,mid) + query(2*d+1,mid+1,dr,mid+1,r);
    // if(mid >= r)query(2*d,dl,mid,l,r);
    // if(mid <= l)query(2*d+1,mid+1,dr,l,r);
    // else{
    //     query(2*d,dl,mid,l,mid);
    //     query(2*d+1,mid+1,dr,mid+1,r);
    // }
}//求和
int main()
{
    int n,m;
    while(scanf("%d%d",&n,&m)!=EOF){
        for(int i=1;i<=n;i++)
            scanf("%d",&a[i]);
        bulid(1,n,1);
        for(int i=1;i<=m;i++){
            int op,x,y;
            scanf("%d%d%d",&op,&x,&y);
            if(op==1){
                update(1,1,n,x,y);
            }else{
                ans = query(1,1,n,x,y);
                printf("%lld\n",ans); 
            }
        }
    }
}
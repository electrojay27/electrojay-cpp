#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int maxn = 1e5 + 10;

ll a[maxn],t[4*maxn],lazy[4*maxn];
// ll ans;
// void push_up(int l,int r,int d){
//     t[d] = t[2*d] + t[2*d+1];
// }
void down(ll d,ll l,ll r,ll k){
    t[d] = r - l + 1 - t[d];
    lazy[d] ^= 1;
}
void push_down(ll d,ll l,ll r){
    if(!lazy[d])return;
    ll mid = (l + r)>>1;
    down(2*d,l,mid,lazy[d]);
    down(2*d+1,mid+1,r,lazy[d]);
    lazy[d] = 0;
}
void bulid(ll l,ll r,ll d){
    if(l==r){
        t[d]=a[l];
        return;
    }
    ll mid = (l+r)>>1;//>>1相当于除以2
    bulid(l,mid,2*d);
    bulid(mid+1,r,2*d+1);
    t[d] = t[2*d] + t[2*d+1];
}//建立树
void update(ll d,ll dl,ll dr,ll x,ll y,ll k){
    // if(dl == dr&&dl == x){
    //     t[d] += k;
    //     return;
    // }
    if(x <= dl&&dr <= y){
        down(d,dl,dr,lazy[d]);
        return;
    }
    push_down(d,dl,dr);

    ll mid = (dl + dr)>>1;
    if(x <= mid)update(2*d,dl,mid,x,y,k);
    if(mid < y)update(2*d+1,mid+1,dr,x,y,k);

    t[d] = t[2*d] + t[2*d+1];
}
ll query(ll d,ll dl,ll dr,ll l,ll r){
    if(l == dl&&dr == r)return t[d];
    // if(l > dr||r < dl)return 0;
    ll mid = (dl + dr)>>1;
    push_down(d,dl,dr);

    ll ans = 0;

    if(r <= mid)ans += query(2*d,dl,mid,l,r);
    else if(l > mid)ans += query(2*d+1,mid+1,dr,l,r);
    else return query(2*d,dl,mid,l,mid) + query(2*d+1,mid+1,dr,mid+1,r);
    return ans;
    // if(mid >= r)query(2*d,dl,mid,l,r);
    // if(mid <= l)query(2*d+1,mid+1,dr,l,r);
    // else{
    //     query(2*d,dl,mid,l,mid);
    //     query(2*d+1,mid+1,dr,mid+1,r);
    // }
}//求和
int main()
{
    ll n,m;
    while(scanf("%lld%lld",&n,&m)!=EOF){
        memset(lazy,0,sizeof(lazy));
        // for(int i=1;i<=n;i++)
        //     scanf("%lld",&a[i]);
        memset(a,0,sizeof(a));
        bulid(1,n,1);
        for(int i=1;i<=m;i++){
            ll op,x,y;
            scanf("%lld%lld%lld",&op,&x,&y);
            if(!op){
                update(1,1,n,x,y,1);
            }else{
                printf("%lld\n",query(1,1,n,x,y)); 
            }
        }
    }
}
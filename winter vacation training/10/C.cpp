#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int maxn = 1e5 + 10;

ll a[maxn],t[4*maxn],lazy[4*maxn];
// ll ans;
void push_up_min(ll d){
    t[d] = min(t[2*d],t[2*d+1]);
}
// void down(ll d,ll l,ll r,ll k){
//     lazy[d] += k;
//     t[d] += k*(r-l+1);
// }
// void push_down(ll d,ll l,ll r){
//     ll mid = (l + r)>>1;
//     down(2*d,l,mid,lazy[d]);
//     down(2*d+1,mid+1,r,lazy[d]);
//     lazy[d] = 0;
// }
void bulid(ll l,ll r,ll d){
    if(l==r){
        t[d]=a[l];
        return;
    }
    ll mid = (l+r)>>1;//>>1相当于除以2
    bulid(l,mid,2*d);
    bulid(mid+1,r,2*d+1);
    // t[d] = t[2*d] + t[2*d+1];
    push_up_min(d);
}//建立树
ll query_min(ll l,ll r,ll dl,ll dr,ll d){
    if(l == dl&&dr == r)return t[d];
    ll mid = (dl + dr)>>1;
    if(r <= mid)return query_min(l,r,dl,mid,2*d);
    if(l > mid)return query_min(l,r,mid+1,dr,2*d+1);
    return min(query_min(l,mid,dl,mid,2*d),query_min(mid+1,r,mid+1,dr,2*d+1));
}
int main()
{
    ll n,m;
    while(scanf("%lld%lld",&n,&m)!=EOF){
        vector<ll> ans;
        memset(lazy,0,sizeof(lazy));
        for(int i=1;i<=n;i++)
            scanf("%lld",&a[i]);
        bulid(1,n,1);
        for(int i=1;i<=m;i++){
            ll op,x,y,k;
            // scanf("%lld",&op);
            // if(op==1){
            //     scanf("%lld%lld%lld",&x,&y,&k);
            //     update(1,1,n,x,y,k);
            // }else{
            //     scanf("%lld%lld",&x,&y);
            //     // ans = query(1,1,n,x,y);
            //     printf("%lld\n",query(1,1,n,x,y)); 
            // }
            scanf("%lld%lld",&x,&y);
            ans.push_back(query_min(x,y,1,n,1));
        }
        for(int i=0;i<ans.size();i++){
            if(!i)printf("%lld",ans[i]);
            else printf(" %lld",ans[i]);
        }printf("\n");
    }
}
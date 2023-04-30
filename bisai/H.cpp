#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
#define ll long long
ll b[maxn],t[4*maxn];
int T,n,m;
void push_up_max(int d){
    t[d]=max(t[2*d],t[2*d+1]);
}
void bulid(ll d,ll l,ll r){
    if(l==r){t[d]=b[l];return;}
    ll mid = (l+r)/2;
    bulid(d*2,l,mid);
    bulid(d*2+1,mid+1,r);
    push_up_max(d);
}
void update(ll dl,ll dr,ll l,ll r,ll d){
    if(dl==l&&dr==r){
        t[d] = 0;
        return;
    }
    if(t[d]){
        ll mid = (l+r)/2;
        if(dl>=mid+1) update(dl,dr,mid+1,r,2*d+1);
        else if(dr<=mid) update(dl,dr,l,mid,2*d);
        else{
            update(mid+1,dr,mid+1,r,2*d+1);
            update(dl,mid,l,mid,2*d);
        }
    }else{
        return;
    }
    push_up_max(d);
}
int main()
{
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++){scanf("%lld",&b[i]);}
        bulid(1,1,n);
        while(m--){
            int l,r;
            scanf("%d%d",&l,&r);
            update(l,r,1,n,1);
            printf("%lld\n",t[1]);
        }
    }
}
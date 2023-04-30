#include <iostream>
#include <algorithm>
using namespace std;
#define ll long long
const int maxn = 1e5 + 10;
// const int mx = 1e9;
ll v[maxn];
int n,m,all;
bool judge(ll x)
{
    // ll sum = 0;
    int cnt = 1;
    int cmp = 0;//定位
    for(int i=1;i<=n;i++){
        // if(all <= x)return true;
        // if(v[i] > x)return false;
        // if(sum + v[i] < x)sum+=v[i];
        if(v[i] - v[i-1] > x)cnt ++,cmp = i - 1;//sum = 0;
        //else sum += v[i];
        if(cnt > m)return false;
        // int cmp = upper_bound(v+1,v+1+n,v[i]+x) - v;
        // i = cmp - 2;
        // cnt ++;
    }return true;
}
int main()
{
    while(scanf("%d%d",&n,&m)!=EOF){
        // mx = 0;
        // all = 0;
        // ll sum = 0;
        v[0] = 0;
        ll l = 1,r = 0;
        for(int i=1;i<=n;i++){
            scanf("%d",&v[i]);
            // all += v[i];
            if(l < v[i])l = v[i];
            // r += v[i];
            v[i] += v[i-1];
        }
        ll r = v[n];
            // if(mx < v[i])mx = v[i];
        // long long l = 1,r = 1e18;
        while(l <= r){
            ll mid = (l + r)/2;
            if(judge(mid))r = mid - 1;
            else l = mid + 1;
        }printf("%lld\n",l);
    }
}
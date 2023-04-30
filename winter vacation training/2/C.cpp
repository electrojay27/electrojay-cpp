#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e5 + 10;
int a[maxn],cmp[maxn],n;
long long cnt;
void solve(int l,int r){
    if(l>=r-1)return;
    int mid = (l + r)/2;
    solve(l,mid);
    solve(mid,r);
    int i,j,k;
    for(i=l,j=l,k=mid;i<mid&&k<r;){
        if(a[i]<=a[k])cmp[j++] = a[i++];
        else cnt += mid - i,cmp[j++] = a[k++];
    }
    while(i<mid)cmp[j++] = a[i++];
    while(k<r)cmp[j++] = a[k++];
    memcpy(a + l, cmp + l, sizeof(a[0]) * (r - l));
}
int main()
{
    while(scanf("%d",&n)!=EOF){
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i]);
        }
        cnt = 0;
        solve(1,n+1);
        printf("%lld\n",cnt);
    }
}
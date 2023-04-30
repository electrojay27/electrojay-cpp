#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e7 + 10;
const int mod = 1e9 + 7;
int n,m,k;
int a[maxn];
int quicksort(int l,int r,int cmp){
    int i = l;
    int j = r-1;
    int key = a[l];
    if(l>=r-1)return a[l];
    while(i<j){
        while(i<j&&a[j]>=key)j--;
        a[i] = a[j];
        while(i<j&&a[i]<=key)i++;
        a[j] = a[i];
    }
    a[i] = key;
    if(cmp == i - l + 1)return a[i];
    if(cmp < i - l + 1)return quicksort(l,i,cmp);
    return quicksort(i+1,r,cmp-i+l-1);
}
int main()
{
    while(scanf("%d%d%d",&n,&m,&k)!=EOF){
        a[0] = m;
        for(int i=1;i<n;i++){
            a[i] = 1ll * a[i-1]*m % mod;
        }
        printf("%d\n",quicksort(0,n,k));
    }
}
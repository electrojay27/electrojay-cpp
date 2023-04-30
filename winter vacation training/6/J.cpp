#include <bits/stdc++.h>
using namespace std;

const int maxn = 110;
int l[maxn],r[maxn],h[maxn];

int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d",&h[i]);
    for(int i=1;i<=n;i++){
        l[i] = 1;
        for(int j=1;j<i;j++){
            if(h[i] > h[j])l[i] = max(l[i],l[j]+1);
        }
    }
    for(int i=n;i>=1;i--){
        r[i] = 1;
        for(int j=i+1;j<=n;j++){
            if(h[i] > h[j])r[i] = max(r[i],r[j]+1);
        }
    }
    int mx = 0;
    for(int i=1;i<=n;i++){
        mx = max(mx,l[i] + r[i] - 1);
    }printf("%d\n",n - mx);
}
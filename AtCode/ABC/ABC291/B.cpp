#include <bits/stdc++.h>
using namespace std;

int n,a[510];

void solve()
{
    sort(a+1,a+1+5*n);
    int sum = 0;
    for(int i=n+1;i<=4*n;i++){
        sum += a[i];
    }
    printf("%.5f\n",1.0*sum / (3*n*1.0));
}

int main()
{
    while(scanf("%d",&n)!=EOF){
        for(int i=1;i<=5*n;i++)scanf("%d",&a[i]);
        solve();
    }
    return 0;
}
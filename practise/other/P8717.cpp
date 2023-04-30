#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,x,sum,mx,mn;
    while(scanf("%d",&n)!=EOF){
        sum = 0;
        mx = 0;
        mn = 100;
        for(int i=1;i<=n;i++){
            scanf("%d",&x);
            sum += x;
            mx = max(x,mx);
            mn = min(mn,x);
        }
        printf("%d\n%d\n%.2f\n",mx,mn,1.0 * sum / n * 1.0);
    }
    return 0;
}
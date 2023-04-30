#include <bits/stdc++.h>
using namespace std;
long long a[1001];
int n;
int main()
{
    while(scanf("%d",&n)!=EOF){
        for(int i=1;i<=n;i++)
            scanf("%lld",&a[i]);
        sort(a+1,a+1+n);
        int l = 1,r = n;
        int sum = 1;
        while(l <= r){
            if(sum%2){
                printf("%d\n",a[r]);
                r--;
                sum++;
            }else{
                printf("%d\n",a[l]);
                l++;
                sum++;
            }
        }
    }return 0;
}
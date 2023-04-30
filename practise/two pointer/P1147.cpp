#include <bits/stdc++.h>
// #define ll long long;
using namespace std;
const int maxn = 2e6 + 10;
long long a[maxn];
int n;
int main()
{
    // a[0] = 0;
    // for(int i=1;i<=2e6;i++)
    //     // a[i] = i + a[i-1];
    //     a[i] = i;
    while(scanf("%d",&n)!=EOF){
        // int l = 1,r = 1;
        // int sum = 0;
        // while(l<=r&&r<n){
        //     if(sum == n){
        //         printf("%d %d\n",l,r);
        //     }
        //     if(sum >= n){
        //         l++;
        //         sum = a[r] - a[l-1];
        //     }
        //     if(sum < n){
        //         r++;
        //         sum = a[r] - a[l-1];
        //     }
        // }
        for(int i=1;i<=n/2;i++){
            int sum = 0;
            for(int j=i;j<n;j++){
                sum += j;
                if(sum == n){printf("%d %d\n",i,j);break;}
                if(sum > n)break;
            }
        }
    }return 0;
}
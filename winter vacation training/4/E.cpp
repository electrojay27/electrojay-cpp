#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;
#define ll long long

const int maxn = 2e4;

int main()
{
    ll n;
    cin >> n;
        int nr[maxn],nl[maxn];
        ll l = 1,r = 1;
        ll sum = 1;
        int cnt = 0;
        while(l <= r && r*r <= n){
            while(n > sum){
                r ++,sum += r*r;
            }
            if(sum == n){
                nr[cnt] = r;
                nl[cnt++] = l;
            }
            sum -= l*l,l++;
        }
        cout << cnt << endl;
        for(ll i=0;i<cnt;i++){
            cout << nr[i] - nl[i] + 1;
            for(ll j=nl[i];j<=nr[i];j++)cout << " " << j;
            cout << endl;
        }
    return 0;
}
// #include <iostream>
// #include <cstdio>
// #include <vector>
// #include <cmath>
// using namespace std;
// #define ll long long
// const int maxn = 1e5 + 10;
// // int a[maxn];
// ll n,sum,cnt;
// int main()
// {
//     // while(scanf("%lld",&n)!=EOF){
//         // for(int i=1;i<=sqrt(n);i++)
//         //     a[i] = i;
//         scanf("%lld",&n);
//         int l=1,r=1;
//         sum = 1;
//         cnt = 0;
//         vector<int> a;
//         while(l <= r){
//             if(sum == n){
//                 cnt++;
//                 a.push_back(r-l+1);
//                 for(int i=l;i<=r;i++)a.push_back(i);
//             }
//             if(sum >= n){
//                 sum -= (l*l);
//                 l++;
//             }
//             else if(sum < n){
//                 r++;
//                 sum += (r*r);
//             }
//         }
//         printf("%d\n",cnt);
//         int j = 0;
//         for(int i=0;i<a.size();i+=(j+1)){
//             j = a[i];
//             for(int k=i;k<=i+j;k++){
//                 if(k<i+j)printf("%d ",a[k]);
//                 else printf("%d\n",a[k]);
//             // printf("\n");
//             }
//         }
//     // }
// }
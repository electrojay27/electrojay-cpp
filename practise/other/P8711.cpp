#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ll n;
    while(scanf("%lld",&n)!=EOF){
        while(n > 0){
            printf("%lld ",n);
            n >>= 1;
        }
        printf("\n");
    }
    return 0;
}
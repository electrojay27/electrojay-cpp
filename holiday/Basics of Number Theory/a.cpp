#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
 
using namespace std;
 
using i64 = long long;
 
const int N = 1e5;
 
i64 x[N], a, b, k;
 
int main()
{
    int t;
    scanf("%d", &t);
 
    while(t--)
    {
        memset(x, 0, sizeof(x));
        scanf("%lld%lld%lld", &a, &b, &k);
        i64 d = __gcd(a, b);
        i64 i, j = 0;
        for(i=1; i*i<=d; ++i)
        {
            if(d % i == 0)
            {
                x[j++] = i;
                if(i*i != d)    x[j++] = d/i;
            }
        }
 
        if(j < k)
        {
            printf("-1\n");
            continue;
        }
        sort(x, x+j);
        printf("%I64d\n", x[j-k]);
    }
 
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
#define ull unsigned long long
#define base 107

const int maxn = 2e6 + 10;
ull Hash[maxn];
ull p[maxn];
char op[maxn];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    p[0] = 1;
    for(int i=1;i<=maxn;i++)p[i] = p[i-1] * base;
    while(cin >> op){
        int len = strlen(op);
        
    }
}
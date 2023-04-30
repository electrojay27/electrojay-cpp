#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e5 + 10;
int a[maxn],ans[maxn];
int n,x;
int main()
{
    while(scanf("%d",&n)!=EOF){
        stack<pair<int,int>> S;
        long long ret = 0;
        // for(int i=1;i<=n;i++){
        //     scanf("%d",&a[i]);
        //     ans[i] = 0;
        // }
        for(int i=1;i<=n;i++){
            scanf("%d",&x);
            pair<int,int> s(x,1);
            while(!S.empty()&&S.top().first<=x){
                ret += S.top().second;
                if(S.top().first == x)s.second += S.top().second;
                S.pop();
            }
            if(!S.empty())ret++;
            S.push(s);
        }printf("%lld\n",ret);
    }return 0;
}
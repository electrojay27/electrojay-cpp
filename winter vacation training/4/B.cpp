#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 10;
int h[maxn],v[maxn],sum[maxn];
int n;
int main()
{
    while(scanf("%d",&n)!=EOF){
        for(int i=1;i<=n;i++)
            scanf("%d%d",&h[i],&v[i]);
        stack<int> s;
        int ret = 0;
        for(int i=1;i<=n;i++){
            while(!s.empty()&&h[s.top()]<h[i]){
                sum[i] += v[s.top()];
                s.pop();
            }
            if(!s.empty())sum[s.top()]+=v[i];
            s.push(i);
        }
        for(int i=1;i<=n;i++){
            ret = max(ret,sum[i]);
        }printf("%d\n",ret);
    }
}
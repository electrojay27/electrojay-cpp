#include <bits/stdc++.h>
using namespace std;
const int maxn = 3e6 + 10;
int a[maxn],ans[maxn];
int n;
int main()
{
    while(scanf("%d",&n)!=EOF){
        stack<int> s;
        memset(ans,0,sizeof(ans));
        for(int i=1;i<=n;i++)
            scanf("%d",&a[i]);
        for(int i=1;i<=n;i++){
            while(!s.empty()&&a[s.top()]<a[i]){
                ans[s.top()] = i;
                s.pop();
            }
            s.push(i);
        }
        for(int i=1;i<=n;i++){
            if(i<n)printf("%d ",ans[i]);
            else printf("%d\n",ans[i]);
        }
    }
}
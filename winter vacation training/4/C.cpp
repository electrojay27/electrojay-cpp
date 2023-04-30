#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
int a[maxn];
int n;
int main()
{
    while(scanf("%d",&n)!=EOF){
        for(int i=1;i<=n;i++)
            scanf("%d",&a[i]);
        stack<int> s;
        int ret = 0;
        for(int i=1;i<=n;i++){
            while(!s.empty()&&s.top()>a[i]){
                s.pop();
            }
            if(!s.empty()&&s.top()==a[i])continue;
            if(a[i])s.push(a[i]),ret++;
        }printf("%d\n",ret);
    }
}
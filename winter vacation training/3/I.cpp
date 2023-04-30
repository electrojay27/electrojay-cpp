#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
int a[maxn],b[maxn];
int n;
int main()
{
    while(scanf("%d",&n)!=EOF){
        priority_queue<int,vector<int>,greater<int> >all;
        // int x;
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i]);
            // a.push(x);
        }
        for(int i=1;i<=n;i++){
            scanf("%d",&b[i]);
            // b.push(x);
        }
        for(int i=1;i<=sqrt(n);i++){
            for(int j=i;j<=(n/i);j++)all.push(a[i]+b[j]);
            for(int j=i+1;j<=(n/i);j++)all.push(a[j]+b[i]);
        }
        for(int i=1;i<=n;i++){
            if(i<n)printf("%d ",all.top());
            else printf("%d\n",all.top());
            all.pop();
        }
    }return 0;
}
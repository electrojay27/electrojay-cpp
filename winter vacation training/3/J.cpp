#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e4 + 10;
int a[maxn];
int n,t;
bool judge(int x){
    int ret = 0;
    priority_queue<int,vector<int>,greater<int> > p;
    for(int i=1;i<=x;i++)p.push(a[i]);
    for(int i=x+1;i<=n;i++){
        int cnt = p.top();
        p.pop();
        p.push(cnt+a[i]);
    }
    while(!p.empty()){
        ret = p.top();
        p.pop();
    }
    return ret <= t;
}
int main()
{
    while(scanf("%d%d",&n,&t)!=EOF){
        priority_queue<int,vector<int>,greater<int> >cow;
        // int x;
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i]);
            // cow.push(x);
        }
        int l = 1,r = n;
        while(l<=r){
            int mid = (l+r)/2;
            if(judge(mid))r=mid-1,cow.push(mid);
            else l = mid+1;
        }
        printf("%d\n",cow.top());
    }
}
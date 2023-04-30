#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e5 + 10;
int a[maxn];
int n,m;
int main()
{
    scanf("%d%d",&n,&m);
    a[0] = 0;
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        a[i] += a[i-1];
    }
    deque<int> q;
    int mx = 0;
    q.push_back(0);//赋予一个初始值避免下面第一组数据没法计算
    for(int i=1;i<=n;i++){
        if(!q.empty()&&i - q.front() >= m)q.pop_front();//超出范围删除
        mx = max(mx,a[i] - a[q.front()]);
        while(!q.empty()&&a[q.back()] > a[i])q.pop_back();
        q.push_back(i);
    }
    printf("%d\n",mx);
}
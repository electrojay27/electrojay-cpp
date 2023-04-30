#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 10;
int a[maxn];
int n,k;
int main()
{
    deque<int> q1,q2;
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    for(int i=1;i<=n;i++){
        if(!q1.empty()&& i - q1.front() >= k)q1.pop_front();//超出范围删掉前面的
        while(!q1.empty()&&a[q1.back()] > a[i])q1.pop_back();
        q1.push_back(i);
        if(i < n&&i >= k)printf("%d ",a[q1.front()]);
        else if(i == n)printf("%d\n",a[q1.front()]);
    }
    for(int i=1;i<=n;i++){
        if(!q2.empty()&& i - q2.front() >= k)q2.pop_front();//超出范围删掉前面的
        while(!q2.empty()&&a[q2.back()] < a[i])q2.pop_back();
        q2.push_back(i);
        if(i < n&&i >= k)printf("%d ",a[q2.front()]);
        else if(i == n)printf("%d\n",a[q2.front()]);
    }
}
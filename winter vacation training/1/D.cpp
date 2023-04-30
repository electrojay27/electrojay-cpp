#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e4 + 10;
int a[maxn];
int L,n,m;
bool judge(int x){
    int cs = 0,now = 0;
    int i = 1;
    while(i <= n+1 && cs<=m){
        if(a[i]-a[now] < x)cs++;//搬掉这一块石头
        else now = i;//达到要求后就定位到这块石头上
        i++;
    }return cs<=m;//搬掉的次数是否超过m
}
int main()
{
    while(scanf("%d%d%d",&L,&n,&m)!=EOF){
        for(int i=1;i<=n;i++)
            scanf("%d",&a[i]);
        a[0] = 0;
        a[n+1] = L;//起点和终点
        int l = 0,r = L;
        while(l < r){
            int mid = (l+r+1)/2;
            if(judge(mid))l = mid;
            else r = mid-1;
        }printf("%d\n",l);
    }
}
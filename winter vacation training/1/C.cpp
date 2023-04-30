#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn = 1e5 + 10;
int s[maxn][2];
int n,k;
int main()
{
    while(scanf("%d%d",&n,&k)!=EOF){
        int r = 0;//r记录最大的边长
        for(int i=1;i<=n;i++){
            scanf("%d%d",&s[i][0],&s[i][1]);
            if(r < min(s[i][0],s[i][1]))r = min(s[i][0],s[i][1]);
        }
        // ll S;//因为面积可能超过int
        // int r = 1e9;
        int l = 1;
        while(l<r){
            int mid = (l + r)/2;
            int ret = 0;
            for(int i=1;i<=n;i++){
                ret += (s[i][0]/mid)*(s[i][1]/mid);
                if(ret >= k){
                    l = mid+1;//从左边开始寻找
                    break;
                }
            }
            if(ret < k)r = mid;//经历循环后还是不能达到，就说明大了从右边开始寻找
        }printf("%d\n",l-1);
    }
}
#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 10;
int a[maxn],b[maxn];
int n,m;
int main()
{
    while(scanf("%d%d",&n,&m)!=EOF){
        for(int i=1;i<=n;i++)
            scanf("%d",&a[i]);
        for(int i=1;i<=m;i++)
            scanf("%d",&b[i]);
        for(int i=1;i<=m;i++){
            int l=1,r=n;
            int ret = -1;
            while(l<r){
                int mid = (l+r)/2;
                if(a[mid]==b[i])ret = mid,r = mid;
                else if(a[mid]>b[i])r=mid;
                else l=mid+1;
            }
            printf("%d ",ret);
        }
    }return 0;
}
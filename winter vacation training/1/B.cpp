#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 10;
int a[maxn];
int n,c;
int main()
{
    while(scanf("%d%d",&n,&c)!=EOF){
        map<int,int> all;
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i]);
            all[a[i]]++;//记录每个数出现的次数
        }
        // sort(a+1,a+1+n);//进行排序(用map的话可以不用排序)
        long long ret = 0;
        for(int i=1;i<=n;i++){
            // int l = i;
            // int r = n;
            int cnt = a[i]+c;//表示达到要求的数
            // while(l<r){
                // int mid = (l+r)/2;
                // if(a[mid]==cnt)ret++,l=mid+1;
                // else if(a[mid]<cnt)l = mid+1;
                // else r = mid;
            // while(l<=n&&a[l]<cnt)l++;
            // while(r>=1&&a[r]>cnt)r--;//TLE//暴力枚举寻找左右端点

            // l = lower_bound(a+1,a+n+1,cnt) - a;
            // r = upper_bound(a+1,a+n+1,cnt) - a;
            // ret += (r - l);//利用函数寻找左右端点
            // ret += (upper_bound(a+i,a+n+1,cnt)-lower_bound(a+i,a+n+1,cnt));//寻找左右端点//通过函数来寻找上下端点//注意起点会变化
            
            /*手打二分函数，毕竟不是很会用还是直接自己敲一份*/
            int len = n - i + 1;
            int half;
            while(len > 0){
                half = len >> 1;
                int mid = l + half;
                if(a[mid]<cnt){
                    l = mid + 1;
                    len = len - half - 1;//右边寻找
                }else len = half;//左边寻找
            }
            ret -= l;//先记录下来
            l = i;//回溯
            len = n - i + 1;
            while(len > 0){
                half = len >> 1;
                int mid = l + half;
                if(a[mid]>cnt)len = half;//右
                else{
                    l = mid + 1;
                    len = len - half - 1;//左
                }
            }
            ret += l;
            /*利用map*/
            // ret += all[cnt];

        }printf("%lld\n",ret);
    }return 0;
}
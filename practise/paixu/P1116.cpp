#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e6 + 10;
int a[maxn];
int ans[maxn];
int n;
int sum = 0;

void m_sort(int l,int r){
    if(l == r)return;
    int mid = (l + r)/2;
    m_sort(l,mid);
    m_sort(mid+1,r);
    int nl = l,nr = mid+1,point = l;
    while(nl <= mid && nr <= r){
        if(a[nl] > a[nr]){
            sum += (mid - nl + 1);
            ans[point++] = a[nr];
            nr ++;
        }else{
            ans[point++] = a[nl];
            nl ++;
        }
    }
    while(nl <= mid){
        ans[point++] = a[nl];
        nl ++;
    }
    while(nr <= r){
        ans[point++] = a[nr];
        nr ++;
    }
    for(int i=1;i<point;i++)a[i] = ans[i];
}

void solve()
{
    //冒泡排序，时间复杂度为n^2，题目的数据范围话可以接受
    // for(int i=1;i<=n;i++){
    //     for(int j=1;j<=i;j++){
    //         if(a[j] > a[i])sum ++;
    //     }
    // }
    // printf("%d\n",sum);

    //归并排序，思路就是相当于就逆序对
    m_sort(1,n);
    printf("%d\n",sum);
}

int main()
{
    ios::sync_with_stdio(false);
    while(cin >> n){
        for(int i=1;i<=n;i++)
            cin >> a[i];
        solve();
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
int a[maxn];
int n;
void quicksort(int l,int r){
    int i = l;
    int j = r;
    int mid = (l+r)/2;
    int key = a[mid];
    while(i<j){
        while(i<=r&&a[i]<key)i++;
        while(j>=l&&a[j]>key)j--;
        if(i<=j){
            swap(a[i],a[j]);
            i++,j--;
        }
    }
    if(i<r)quicksort(i,r);
    if(l<j)quicksort(l,j);
}
int main()
{
    while(scanf("%d",&n)!=EOF){
        for(int i=1;i<=n;i++)
            scanf("%d",&a[i]);
        quicksort(1,n);
        for(int i=1;i<=n;i++){
            if(i<n)printf("%d ",a[i]);
            else printf("%d\n",a[i]);
        }
    }
}
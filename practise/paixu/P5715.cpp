#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a[4];
    for(int i=1;i<=3;i++)scanf("%d",&a[i]);
    for(int i=1;i<=3;i++){
        for(int j=i+1;j<=3;j++){
            if(a[i] > a[j])swap(a[i],a[j]);
        }
    }
    for(int i=1;i<=3;i++){
        printf("%d ",a[i]);
    }printf("\n");
    return 0;
}
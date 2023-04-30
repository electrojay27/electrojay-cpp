#include <bits/stdc++.h>
using namespace std;
// const int maxn = 5e6 + 10;
int x[30],n,k;
long long all;//可能会有多种结果
int prime(int curx){
    for(int i=2;i*i<=curx;i++)
        if(curx%i==0)return 0;
    return 1;
}//素数判断
void DFS(int a,int sum,int b){
    if(a==k){
        if(prime(sum))all++;
        return;
    }
    for(int i=b;i<=n;i++){
        DFS(a+1,sum+x[i],i+1);
    }//利用不降原则 使得前面用过的数不会再重复计算
    if(a<k&&b>n)return;
}//以b为起点，a记录数字个数，如果剩余数不够k则return
int main()
{
    while(scanf("%d%d",&n,&k)!=EOF){
        for(int i=1;i<=n;i++){
            scanf("%d",&x[i]);
        }
        all = 0;
        DFS(0,0,1);
        printf("%d\n",all);
    }return 0;
}
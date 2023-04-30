#include <bits/stdc++.h>
using namespace std;

const int maxn = 510;
string sum1,sum2;
int a[maxn];
int b[maxn];
int ans[maxn];
int n;

void solve()
{
    memset(ans,0,sizeof(ans));
    int cnt,cmp;
    int len1 = sum1.size();
    int len2 = sum2.size();
    for(int i=0;i<len1;i++){
        a[sum1.size()-i] = sum1[i] - '0';//转换
    }
    for(int i=0;i<len2;i++){
        b[sum2.size()-i] = sum2[i] - '0';//转换
    }
    if(len1 > len2)cnt = len2,cmp = len1;
    else cnt = len1,cmp = len2;
    for(int i=1;i<=cnt;i++){
        ans[i] = ans[i] + a[i] + b[i];
        if(ans[i] > 9){
            ans[i + 1] += ans[i] / 10;
            ans[i] %= 10;
        }
    }
    for(int i=1 + cnt;i<=cmp;i++){
        if(cmp == len1){
            ans[i] += a[i];
            if(ans[i] > 9){
                ans[i + 1] = ans[i] / 10;
                ans[i] %= 10;
            }
        }else{
            ans[i] += b[i];
            if(ans[i] > 9){
                ans[i + 1] = ans[i] / 10;
                ans[i] %= 10;
            }
        }
    }
    for(int i=cmp+1;i>0;i--){
        if(!ans[i]&&i==cmp+1)continue;
        printf("%d",ans[i]);
    }printf("\n");
}

int main()
{
    ios::sync_with_stdio(false);
    while(cin >> sum1 >> sum2){
        solve();
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

const int maxn = 4010;
string sum1,sum2;
int a[maxn];
int b[maxn];
int ans[maxn];
int n;

void solve()
{
    memset(ans,0,sizeof(ans));
    int cnt = 0;
    int len1 = sum1.size();
    int len2 = sum2.size();
    for(int i=0;i<len1;i++){
        a[sum1.size()-i] = sum1[i] - '0';//转换
    }
    for(int i=0;i<len2;i++){
        b[sum2.size()-i] = sum2[i] - '0';//转换
    }
    for(int i=1;i<=len1;i++){
        for(int j=1;j<=len2;j++){
            ans[i+j-1] += a[i] * b[j];
            cnt = i + j - 1;
            if(ans[i+j-1] > 9){
                ans[i + j] += ans[i+j-1] / 10;
                ans[i + j - 1] %= 10;
                cnt = i + j;
            }
        }
    }
    if((len1 == 1&&a[1] == 0)||(len2 == 1&&b[1] == 0)){
        printf("0\n");
    }else{
        for(int i=cnt;i>0;i--){
            printf("%d",ans[i]);
        }printf("\n");
    }
}

int main()
{
    ios::sync_with_stdio(false);
    while(cin >> sum1 >> sum2){
        solve();
    }
    return 0;
}
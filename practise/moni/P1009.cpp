#include <bits/stdc++.h>
using namespace std;
#define i64 long long

const int maxn = 510;
int a[maxn];
int b[maxn];
int ans[maxn];
int cmp;
// struct Node
// {
    
// }a[maxn];
int n;

void solve(int x)
{
    int cnt = 1;//定义初始位置
    for(int i=1;i<=x;i++){//遍历每个数，求阶乘
        memset(b,0,sizeof(b));//初始化转换数组
        for(int j=1;j<=cnt;j++){
            b[j] += a[j] * i;//运算a的数，存储到转换数组里面
            if(b[j] > 9){
                b[j+1] += b[j]/10;
                b[j] %= 10;
            }//进位
        }
        while(b[cnt + 1]){
            cnt++;
            if(b[cnt] > 9){
                b[cnt + 1] += b[cnt] / 10;
                b[cnt] %= 10;
            }
        }
        for(int i=1;i<=cnt;i++)
            a[i] = b[i];//转换回去
    }
    // for(int i=cnt;i>0;i--)
    //     cout << a[i];
    // cout << endl;
    cmp = max(cmp,cnt);//求最大一位的位置
    for(int i=1;i<=cmp;i++){
        ans[i] += a[i];
        if(ans[i] > 9){
            ans[i+1] += ans[i]/10;
            ans[i] %= 10;
            if(i == cmp)cmp++;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    while(cin >> n){
        cmp = 0;
        memset(ans,0,sizeof(ans));//首先初始化数组
        for(int i=1;i<=n;i++){//遍历每一个数
            memset(a,0,sizeof(a));
            a[1] = 1;//初始值为0
            // for(int i=1;i<=n;i++)
            //     cin >> a[i];
            solve(i);//求阶乘
        }
        for(int i=cmp;i>0;i--)
            cout << ans[i];
        cout << endl;
    }
    return 0;
}
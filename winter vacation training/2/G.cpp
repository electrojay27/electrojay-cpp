#include <bits/stdc++.h>
using namespace std;

// const int maxn = 1100;
// int a[maxn][maxn];
int n,x,y;

int mi(int m){
    int ans = 1;
    for(int i=1;i<=m;i++)
        ans <<= 1;
    return ans;
}

void solve(int m,int a,int b,int l,int r){
    if(m == 1)return;
    if((a - l) <= m/2 - 1&&(b - r) <= m/2 - 1){
        //第一象限
        cout << l + m/2 << " " << r + m/2 << " " << 1 << endl;
        solve(m/2,a,b,l,r);
        solve(m/2,l + m/2 - 1,r + m/2,l,r + m/2);
        solve(m/2,l + m/2,r + m/2 - 1,l + m/2,r);
        solve(m/2,l + m/2,r + m/2,l + m/2,r + m/2);
        //先定义一个初始点(1，1)，然后用这个点进行区域上的划分，避免最开始划分的时候坐标输出完全一样
    }else if((a - l) <= m/2 - 1&&(b - r) > m/2 - 1){
        //第二象限
        cout << l + m/2 << " " << r + m/2 - 1 << " " << 2 << endl;
        solve(m/2,a,b,l,r + m/2);
        solve(m/2,l + m/2,r + m/2 - 1,l + m/2,r);
        solve(m/2,l + m/2 - 1,r + m/2 - 1,l,r);
        solve(m/2,l + m/2,r + m/2,l + m/2,r + m/2);
    }else if((a - l) > m/2 - 1&&(b - r) <= m/2 - 1){
        //第三象限
        cout << l + m/2 - 1 << " " << r + m/2 << " " << 3 << endl;
        solve(m/2,a,b,l + m/2,r);
        solve(m/2,l + m/2 - 1,r + m/2,l,r + m/2);
        solve(m/2,l + m/2 - 1,r + m/2 - 1,l,r);
        solve(m/2,l + m/2,r + m/2,l + m/2,r + m/2);
    }else{
        //第四象限
        cout << l + m/2 - 1 << " " << r + m/2 - 1 << " " << 4 << endl;
        solve(m/2,a,b,l + m/2,r + m/2);
        solve(m/2,l + m/2 - 1,r + m/2,l,r + m/2);
        solve(m/2,l + m/2,r + m/2 - 1,l + m/2,r);
        solve(m/2,l + m/2 - 1,r + m/2 - 1,l,r);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    while(cin >> n >> x >> y){
        // for(int i=1;i<=mi(n);i++){
        //     for(int j=1;j<=mi(n);j++){
        //         a[i][j] = 5;//初始化
        //     }
        // }
        // a[x][y] = 0;//将公主的位置变成0
        solve(mi(n),x,y,1,1);
    }
    return 0;
}
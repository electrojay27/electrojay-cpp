#include <iostream>
#include <cstdio>
#include <cstring>
#include <cctype>
#include <algorithm>
using namespace std;
#define i64 long long
#define mod 10000

const int maxn = 5;
i64 n,k;
struct Node
{
    i64 a[maxn][maxn];
    Node(){
        memset(a,0,sizeof(a));
    }
    inline void build(){//建造单位矩阵
		for(int i=1;i<=2;i++)a[i][i]=1;
	}
};
Node a;

// Node operator *(const Node &x,const Node &y){
//     Node ans;
//     for(int i=1;i<=2;i++){
//         for(int j=1;j<=2;j++){
//             for(int k=1;k<=2;k++){
//                 ans.a[i][j] = (ans.a[i][j] + x.a[i][k]*y.a[k][j]%mod)%mod;
//             }
//         }
//     }
//     return ans;
// }

Node mi(Node x,Node y){
    Node ans;
    // memset(ans.a,0,sizeof ans.a);
    for(int i=1;i<=2;i++)
        for(int j=1;j<=2;j++)
            for(int k=1;k<=2;k++)
                ans.a[i][j] = (ans.a[i][j] + x.a[i][k] * y.a[k][j]%mod)%mod;
    return ans;
}

void solve()
{
    Node cnt;
    cnt.build();
    // memset(cnt.a,0,sizeof cnt.a);

    while(n > 0){
        if(n & 1)cnt = mi(cnt,a);
        a = mi(a,a),n >>= 1;
    }

    cout << cnt.a[1][2] << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    while(cin >> n && n != -1){
        // for(int i=1;i<=n;i++)
        //     for(int j=1;j<=n;j++)
        //         cin >> a.a[i][j];//记录矩阵式
        a.a[1][1] = 1;
        a.a[1][2] = 1;
        a.a[2][1] = 1;
        a.a[2][2] = 0;//定义初始矩阵
        solve();
    }
    return 0;
}
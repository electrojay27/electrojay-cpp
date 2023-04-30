#include <bits/stdc++.h>
using namespace std;
#define i64 long long
#define mod 1000000007

const int maxn = 110;
i64 n,k;
struct Node
{
    i64 a[maxn][maxn];
    Node(){
        memset(a,0,sizeof(a));
    }
    inline void build(){//建造单位矩阵
		for(int i=1;i<=n;++i)a[i][i]=1;
	}
};
Node a,cnt;

// Node operator *(const Node &x,const Node &y){
//     Node ans;
//     for(int i=1;i<=n;i++){
//         for(int j=1;j<=n;j++){
//             for(int k=1;k<=n;k++){
//                 ans.a[i][j] = (ans.a[i][j] + x.a[i][k]*y.a[k][j]%mod)%mod;
//             }
//         }
//     }
//     return ans;
// }

Node mi(Node x,Node y){
    Node ans;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            for(int k=1;k<=n;k++)
                ans.a[i][j] = (ans.a[i][j] + x.a[i][k]*y.a[k][j]%mod)%mod;
    return ans;
}

void solve()
{
    while(k > 0){
        if(k & 1)cnt = mi(cnt,a);
        a = mi(a,a),k >>= 1;
    }

    for(int i=1;i<=n;cout << endl,i++)
        for(int j=1;j<=n;j++)
            cout << cnt.a[i][j] << " ";
}

int main()
{
    ios::sync_with_stdio(false);
    while(cin >> n >> k){
        cnt.build();
        
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                cin >> a.a[i][j];//记录矩阵式
        solve();
    }
    return 0;
}
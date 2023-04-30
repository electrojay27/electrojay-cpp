#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
#define int long long
#define mod 1000000007

struct node
{
    int a[2][2];

    node()
    {
        memset(a,0,sizeof(a));
    }

    inline void bulid(){
        a[0][0] = a[1][1] = 1;
    }

    node operator *(const node& t)
    {
        node ans;
        for(int i = 0;i < 2;i ++){
            for(int j = 0;j < 2;j ++){
                for(int k = 0;k < 2;k ++){
                    ans.a[i][j] = (ans.a[i][j] % mod + a[i][k] * t.a[k][j] % mod) % mod;
                }
            }
        }

        return ans;
    }
};

node Pow(node x,int n){
    node cnt;
    cnt.bulid();

    while(n > 0){
        if(n & 1)cnt = cnt * x;
        x = x * x;
        n >>= 1;
    }

    return cnt;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    while(cin >> n && n != EOF){
        node x;
        x.a[0][1] = x.a[0][0] = x.a[1][0] = 1;

        node ans = Pow(x,n);

        cout << ans.a[0][1] << endl;
    }
}
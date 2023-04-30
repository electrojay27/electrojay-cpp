#include <bits/stdc++.h>
using namespace std;

const int maxn = 5e4 + 10;
int a[maxn],l[7],r[7];
int vl[7],vr[7];
int n;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    while(cin >> n){
        memset(vl,0,sizeof(vl));
        memset(vr,0,sizeof(vr));
        a[0] = 0;
        for(int i=1;i<=n;i++){
            cin >> a[i];
            a[i] += a[i-1];//前缀和
            a[i] %= 7;//对7取余，由于两个数相减想被7整除，那就说明他们单独与7相除的余数也是一样的，这种方法叫做同余
        }
        int ans = 0;
        for(int i=0;i<=n;i++){
            if(!vl[a[i]])l[a[i]] = i;
            vl[a[i]] = 1;
        }
        for(int i=n;i>=0;i--){
            if(!vr[a[i]])r[a[i]] = i;
            vr[a[i]] = 1;
        }
        for(int i=0;i<7;i++)ans = max(ans,r[i]-l[i]);
        cout << ans << endl;
    }
    return 0;
}
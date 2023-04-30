#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define eps 1e-6
// #define pi 3.14159265359
const double pi = acos(-1);
int t,n,f;
double a[10010];
bool judge(double x){
    ll cnt = 0;
    for(int i = 1;i <= n;i ++){
        double s = a[i]*a[i]*pi + eps;
        cnt += floor(s / x);
        if(cnt > f)return true;
    }return false;
}
int main()
{
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&f);
        double l = 0,r = 1e18;
        for(int i=1;i<=n;i++)scanf("%lf",&a[i]);
        while(l + eps < r){
            double mid = (l + r) / 2;
            if(judge(mid)) l = mid;
            else r = mid;
        }
        printf("%.4f\n",l);
    }
}
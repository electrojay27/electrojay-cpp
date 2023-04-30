#include <iostream>
#include <cmath>
using namespace std;
const int maxn = 1e4 + 10;
const double eps = 1e-8;
double a[maxn];
int n,k;
bool judge(double x){
    long long ret = 0;
    int i = 1;
    while(i<=n&&ret<k){
        ret += floor(a[i]/x);//floor:向下取整
        i++;
    }return ret >= k;
}
int main()
{
    while(scanf("%d%d",&n,&k)!=EOF){
        double r = 0;
        for(int i=1;i<=n;i++){
            scanf("%lf",&a[i]);
            // a[i] += eps;
            a[i] += 0.005;
            r = max(r,a[i]);
        }
        double l = 0;
        while(l+eps<r){
            double mid = (l+r)/2.0;
            if(judge(mid))l = mid;
            else r = mid;
        }//printf("%.2f",l);导致四舍五入错误
        printf("%.2f",floor(l*100)/100);
    }
}
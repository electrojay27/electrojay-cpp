#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-6;//注意用double或者#define eps 1e-6
double a[15];
double l,r,N;
double f(double x)
{
    double sum=0;
    for(int i=N;i>=0;i--)sum=sum*x+a[i];
    return sum;
}
int main()
{
    scanf("%lf%lf%lf",&N,&l,&r);
    for(int i=N;i>=0;i--)scanf("%lf",&a[i]);
    while(l + eps <= r){
        double midl = l + (r - l)/3;
        double midr = r - (r - l)/3;
        if(f(midl) > f(midr))r = midr;
        else l = midl;
    }printf("%0.5f\n",l);
    return 0;
}
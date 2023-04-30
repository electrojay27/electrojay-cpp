#include <bits/stdc++.h>
using namespace std;
#define i64 long long
#define p 31536000
#define r 31622400
#define d 86400

int main()
{
    i64 t;
    int h,m,s;
    
    while(scanf("%lld",&t)!=EOF){
        t /= 1000;
        int year = 1970;
        while(t > 0){
            if(!(year%4) && ((year%100) || !(year%400))){
                if(t - r > 0)t -= r,year++;
                else{
                    while(t > d)t -= d;
                    h = t / 3600;
                    t %= 3600;
                    m = t / 60;
                    s = t % 60;
                    printf("%02d:%02d:%02d\n",h,m,s);
                    break;
                }
            }else{
                if(t - p > 0)t -= p,year ++;
                else{
                    while(t > d)t -= d;
                    h = t / 3600;
                    t %= 3600;
                    m = t / 60;
                    s = t % 60;
                    printf("%02d:%02d:%02d\n",h,m,s);
                    break;
                }
            }
        }
    }
    return 0;
}
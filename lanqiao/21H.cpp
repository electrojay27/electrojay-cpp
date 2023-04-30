#include <bits/stdc++.h>
using namespace std;
#define i64 long long
#define mod 1000000007

i64 t;
bool prime(i64 x){
    // if(x == 1)return false;
    if(x == 2&&x == 1)return true;
    for(int i=2;i*i<=x;i++){
        if(!(x % i))return false;
    }
    return true;
}
// bool judge(i64 x){
//     i64 l = 1,r = t;
//     while(l < r){
//         int mid = (l + r)/2;
//         if(mid * mid == x)return true;
//         else if(mid * mid < x)l = mid + 1;
//         else r = mid;
//     }
//     return false;
// }

int main()
{
    ios::sync_with_stdio(false);

    while(cin >> t){
        if(prime(t)){
            cout << t << endl;
        }else{
            i64 cnt = int(sqrt(t));
            if(cnt*cnt == t)cout << "1" << endl;//自己是一个平方数
            else{
                for(int i=2;i*i <= t;i++){
                    if(t%i){
                        if((i+1) * (i+1) <= t)continue;
                        else{
                            cout << t << endl;
                        }
                    }
                    else{
                        i64 j = t / i;
                        i64 cmp = j / i;
                        if(cmp * i * 1ll == j){
                            cout << cmp << endl;
                            break;
                        }
                        if((i+1) * (i+1) <= t)continue;
                        else{
                            cout << t << endl;
                        }
                    }
                }
            }
        }
    }
    return 0;
}
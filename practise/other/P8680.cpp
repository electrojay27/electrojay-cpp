#include <bits/stdc++.h>
using namespace std;
#define ll long long;

long long sum;
int n;
int a[4] = {0,1,2,9};

void solve(){
    for(int i=1;i<=n;i++){
        int flag = 0;
        int cnt = i;
        while(cnt > 0){
            int cmp = cnt % 10;
            for(int j=0;j<4;j++){
                if(a[j]==cmp){
                    flag = 1;
                    break;
                }
            }
            if(flag == 1){
                sum += i * 1ll;
                break;
            }
            cnt /= 10;
        }
    }
    printf("%lld\n",sum);
}

int  main()
{
    while(scanf("%d",&n)!=EOF){
        sum = 0;
        solve();
    }
}
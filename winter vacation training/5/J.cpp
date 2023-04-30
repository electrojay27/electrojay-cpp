#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

const int maxn = 1e4 + 10;
int k[maxn],t[maxn];
int n;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    while(cin >> n && n){
        for(int i=1;i<=n;i++)cin >> t[i];
        for(int i=1;i<=n;i++)cin >> k[i];
        sort(t+1,t+1+n);
        sort(k+1,k+1+n);
        int maxk,maxt,mink,mint;
        int rase = 0;
        maxk = n;
        maxt = n;
        mink = 1;
        mint = 1;
        int ans = 0;
        while((rase++) < n){
            if(t[maxt] > k[maxk]){
                maxk --;
                maxt --;
                ans += 200;
            }
            else if(t[maxt] < k[maxk]){
                mint ++;
                maxk --;
                ans -= 200;
            }else{
                if(t[mint] > k[mink]){
                    mint ++;
                    mink ++;
                    ans += 200;
                }else{
                    if(t[mint] < k[maxk])ans -= 200;
                    mint ++;
                    maxk --;
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}
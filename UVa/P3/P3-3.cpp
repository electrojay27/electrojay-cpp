#include <bits/stdc++.h>
using namespace std;

int n,T;
int a[11];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> T;
    while(T--){
        cin >> n;
        memset(a,0,sizeof(a));
        int cmp;
        for(int i=1;i<=n;i++){
            int cnt = i;
            while(cnt > 0){
                cmp = cnt % 10;
                a[cmp] ++;
                cnt /= 10;
            }
        }
        for(int i=0;i<10;i++){
            if(i == 9)cout << a[i] << endl;
            else cout << a[i] << " ";
            // cout << a[i] << (i==10? "\n" : " " );
        }
    }
    return 0;
}
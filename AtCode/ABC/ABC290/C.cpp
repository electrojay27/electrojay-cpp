#include <bits/stdc++.h>
using namespace std;

const int maxn = 3e5 + 10;
int a[maxn];
int n,k;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    while(cin >> n >> k){
        // map<int,int> mp;
        for(int i=0;i<n;i++)cin >> a[i];
        sort(a,a+n);
        int ans = 1;
        for(int i=0;i<n;i++){
            if(k <= 0)break;
            if(ans > i)continue;
            else if(ans == i)++ans,--k;
            else break;
        }
        cout << ans << endl;
    }
    return 0;
}
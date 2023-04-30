#include <bits/stdc++.h>
using namespace std;

int a[110][110];
int n,m;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    while(cin >> n >> m){
        int ans = 0;
        memset(a,0,sizeof(a));

        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin >> a[i][j];
                if(a[i][j])a[i][j] = min(min(a[i-1][j],a[i][j-1]),a[i-1][j-1])+1;
                ans = max(ans,a[i][j]);
                //前缀和
            }
        }

        cout << ans << endl;
    }
    return 0;
}
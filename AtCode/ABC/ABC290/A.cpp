#include <bits/stdc++.h>
using namespace std;

int a[110];
int n,m;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    while(cin >> n >> m){
        for(int i=1;i<=n;i++)cin >> a[i];
        int sum = 0;
        int cnt;
        for(int i=1;i<=m;i++){
            cin >> cnt;
            sum += a[cnt];
        }
        cout << sum << endl;
    }
}
#include <bits/stdc++.h>
using namespace std;

string a;

void solve()
{
    for(int i=0;i<a.size();i++){
        cout << char(a[i] - 32);
    }
    cout << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    while(cin >> a){
        solve();
    }
    return 0;
}
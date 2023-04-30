#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 10;
int cnt = 0;
char all[maxn];
char op;

void solve()
{
    int a = 0;
    int b = 0;
    for(int i=0;i<cnt;i++){
        if(all[i] == 'W')a++;
        if(all[i] == 'L')b++;
        if((a >= 11||b >= 11) && fabs(a - b) >= 2 ){
            cout << a << ":" << b << endl;
            a = b = 0;
        }
    }
    cout << a << ":" << b << endl << endl;
    
    a = b =0;
    for(int i=0;i<cnt;i++){
        if(all[i] == 'W')a++;
        if(all[i] == 'L')b++;
        if((a >= 21||b >= 21) && fabs(a - b) >= 2 ){
            cout << a << ":" << b << endl;
            a = b = 0;
        }
    }
    cout << a << ":" << b << endl;
}

int main()
{
    while(cin >> op&&op != 'E'){
        if(op == 'W'||op == 'L')
            all[cnt++] = op;
    }
    solve();
    return 0;
}
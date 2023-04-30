#include <bits/stdc++.h>
using namespace std;

string op;
int n,k;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    while(cin >> n >> k){
        cin >> op;

        int sum = 0;
        for(int i=0;i<op.size();i++){
            if(sum != k && op[i] == 'o')sum ++;
            else op[i] = 'x';
        }
        cout << op << endl;
    }
    return 0;
}
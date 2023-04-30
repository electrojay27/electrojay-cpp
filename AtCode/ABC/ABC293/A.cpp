#include <bits/stdc++.h>
using namespace std;

string op;

int main()
{
    ios::sync_with_stdio(false);

    while(cin >> op){
        for(int i=0;i<op.size()-1;i+=2){
            cout << op[i+1]  << op[i];
        }
        cout << endl;
    }
}
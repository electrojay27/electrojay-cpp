#include <bits/stdc++.h>
using namespace std;

string op;

void solve(){
    int ans = 0;
    for(int i=1;i<op.size();i++){
        if(op[i] >= 'A'&&op[i] <='Z'){
            ans = i;
            break;
        }
    }
    printf("%d\n",ans);
}

int main()
{
    while(cin >> op){
        op = '\0' + op;
        solve();
    }
    return 0;
}
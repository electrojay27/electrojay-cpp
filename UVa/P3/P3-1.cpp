#include <bits/stdc++.h>
using namespace std;

char op[100];
int T;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> T;
    while(T--){
        cin >> op;
        int flag = 0;
        int ans = 0;
        int len = strlen(op);
        for(int i=0;i<len;i++){
            if(op[i] == 'O'){
                flag++;
                ans += flag;
            }else flag = 0;
        }
        cout << ans << endl;
    }
}
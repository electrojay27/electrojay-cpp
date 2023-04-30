#include <bits/stdc++.h>
using namespace std;

int T;
const int maxn = 1e6 + 10;
char op[100];
// int a[100];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> T;
    // int ans = 0;
    // getchar();
    while(T--){
        // int flag = 1;
        // int l = 0,r = 0;
        cin >> op;
        int len = strlen(op);
        for(int i=1;i<=len;i++){
            if(!(len % i)){
                for(int j=0;j<len;j++){
                    if(op[j] != op[j%i])break;
                    if(j == len - 1){
                        cout << i << endl;
                        i = len + 1;
                    }
                }
            }
        }
        if(T)cout << endl;
    }
    // for(int i=0;i<ans;i++){
    //     cout << a[i] << endl << endl;
    // }
    return 0;
}
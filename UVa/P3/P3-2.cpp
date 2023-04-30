#include <bits/stdc++.h>
using namespace std;
#define c 12.01
#define h 1.008
#define o 16.00
#define n 14.01

int T;
char op[100];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> T;
    while(T--){
        cin >> op;
        double flag;//记录上一个字符的变量
        int sum;
        double ans = 0;
        int len = strlen(op);
        for(int i=0;i<len;i++){
            if(op[i] == 'C'){
                ans += c;
                flag = c;
            }else if(op[i] == 'H'){
                ans += h;
                flag = h;
            }else if(op[i] == 'O'){
                ans += o;
                flag = o;
            }else if(op[i] == 'N'){
                ans += n;
                flag = n;
            }else{
                if(op[i+1]>='0'&&op[i+1]<='9'){
                    sum = (op[i] - '0')*10 + (op[i+1] - '0');
                    ans += flag * 1.0*(sum - 1);
                    i++;
                }else{
                    sum = op[i] - '0';
                    ans += flag * 1.0 *(sum-1);
                }
            }
        }
        cout << fixed << setprecision(3) << ans << endl;
    }
}
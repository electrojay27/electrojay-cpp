#include <bits/stdc++.h>
using namespace std;
int main()
{
    // while(1){
        // string op;
        // char all[10];
        char op;
        cin >> op;
        putchar(op);
        int a;
        for(int i=1;i<=3;i++){
            scanf("%2X",&a);
            a = 255 - a;
            printf("%02X",a);//x表示小写，X表示大写
        }printf("\n");
        return 0;
        // all[0] = '#';
        // for(int i=1;i<op.size()-1;i+=2){
        //     int sum = 0;
        //     if(op[i]>='A'&&op[i]<='F')
        //         sum += ((op[i] - 'A' + 10) * 16);
        //     else sum += ((op[i] - '0') * 16);
        //     if(op[i+1]>='A'&&op[i+1]<='F')
        //         sum += (op[i+1] - 'A' + 10);
        //     else sum += (op[i+1] - '0');
        //     sum = 255 - sum;
        //     int a,b;
        //     a = sum/16;
        //     b = sum%16;
        //     if(a > 9)
        //         all[i] = (a - 10 + 'A');
        //     else all[i] = (a + '0');
        //     if(b > 9)
        //         all[i+1] = (b - 10 + 'A');
        //     else all[i+1] = (b + '0');
        // }
        // for(int i=0;i<=6;i++){
        //     cout << all[i];
        // }cout << endl;
    // }
}
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a,b,flag,cnt;
    cnt = 1;
    char ch;

    while(1){
        ch = getchar();
        if(ch == 'Z')return 0;
        char mp[5][5];
        flag = 1;
        if(ch == ' ')a = 0,b = 0;

        mp[0][0] = ch;

        for(int i=0;i<5;i++){
            for(int j=0;j<5;j++){
                if(i||j){
                    ch = getchar();
                    if(ch == ' ')a = i,b = j;
                    mp[i][j] = ch;

                }
            }
            getchar();//吸收"\n"
        }

        string op;
        while(ch = getchar()){
            if(ch == '0')break;
            else op.push_back(ch);
        }
        getchar();//\n
        //暂时还没试（不是）出来不用另一个数组的ac方法
        
        // while((ch = getchar())&&ch != '0'){
        for(int i=0;i<op.size();i++){
            ch = op[i];
            int l = a,r = b;

            if(ch == 'A')a --;
            else if(ch == 'B')a ++;
            else if(ch == 'L')b --;
            else if(ch == 'R')b ++;
            
            if(a < 0||b < 0||a > 4||b > 4){
                flag = 0;
                break;
            }else swap(mp[l][r],mp[a][b]);
        }

        if(cnt != 1)cout << endl;
        cout << "Puzzle #" << cnt << ":" << endl;
        cnt++;
        
        if(flag){
            for(int i=0;i<5;i++){
                for(int j=0;j<5;j++){
                    if(j)cout << " ";
                    cout << mp[i][j];
                }
                cout << endl;
            }
        }else{
            cout << "This puzzle has no final configuration." << endl;
        }
    }
    return 0;
}
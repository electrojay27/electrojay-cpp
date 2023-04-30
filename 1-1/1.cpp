#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e4;
int a[maxn][2];
int main()
{
    string s;
    int w,l,cnt,flag;
    w = l = 0;
    cnt = flag = 1;
    while(cin >> s){
        for(int i=0;i<s.size();i++){
            if(s[i]=='W')w++;
            else if(s[i]=='L')l++;
            else flag = 0;
        }
        if((w%11||l%11)&&flag){
            a[cnt][0] = w-a[cnt-1][0];
            a[cnt++][1] = l-a[cnt-1][1];
        }
    }
}
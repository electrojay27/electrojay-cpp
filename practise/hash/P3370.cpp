//题目大意：有n个单词，里面一共有多少个不同的单词
//大概思路：第一思路就是直接用map查重，但就没办法考查hash的做法了，第二思路就是利用一个unsigned long long数组，来作为hash，储存每个单词的地址，针对查重，要是数据小点，
//就可以直接用key做地址，但是数据大，那么就用排序，一样的就靠在旁边，就可以直接比较过去

#include <bits/stdc++.h>
using namespace std;
#define ull unsigned long long
#define base 123//这个也是，不要取太像整数那种
#define mod 21132878718494//这个随便取，但尽量复杂点就可

const int maxn = 1e4 + 10;
ull Hash[maxn];
char op[1510];
ull cnt;

int main()
{
    ios::sync_with_stdio(false);
    
    int T;
    int ans = 0;
    cin >> T;
    int t = T;
    memset(Hash,0,sizeof(Hash));
    while(T--){
        cnt = 0;//预先存储
        cin >> op;
        int len = strlen(op);
        for(int i=0;i<len;i++){
            cnt = ((cnt * base % mod) + op[i] - '0' + 1)%mod;
        }
        Hash[T] = cnt;
    }
    sort(Hash,Hash+t);//排序
    for(int i=0;i<t;i++){
        if(Hash[i] != Hash[i+1])ans++;//如果不一样就相加，一样就不加
    }
    cout << ans << endl;
}

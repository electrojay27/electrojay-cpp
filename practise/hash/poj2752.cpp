//题目大意：一个字符串，查找既是前缀又是后缀的字符串，统计长度，升序输出
//大概思路，前后缀？其实就是前后对比嘛，定义一组双指针，来指定位置，可以的就输出，毕竟是从小到大开始遍历的，其他的就照常hash就行

#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
#define base 107//取整容易只因
#define ull unsigned long long

const int maxn = 4e5 + 10;
ull Hash[maxn];
ull p[maxn];
char a[maxn];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    p[0] = 1;
    for(int i=1;i<=maxn;i++)p[i] = p[i-1] * base;
    while(cin >> a){
        // vector<int> ans;
        
        int len = strlen(a);
        Hash[0] = 0;
        for(int i=0;i<len;i++)Hash[i+1] = Hash[i] * base + a[i] - 'a' + 1;
        int l=1,r=len;
        for(;l<=len;){
            if(Hash[l] == Hash[len] - Hash[r-1]*p[l])cout << l << " ";
            l ++,r --;
        }
        cout << endl;
        // for(int i=0;i<ans.size();i++){
        //     if(i < ans.size()-1)cout << ans[i] << " ";
        //     else cout << ans[i] << endl;
        // }
    }
    return 0;
}

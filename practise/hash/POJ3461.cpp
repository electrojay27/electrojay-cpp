//题目大意：两个字符串，一个为目标字符串，在另一个字符串里面找目标字符串出现了几次，只要位置不完全重叠就算一次
//大概思路：目标字符串和总字符串可以转换成哈希值，然后通过遍历每个字母，比较哈希值即可，得到子字符串的哈希值需要注意好所取的点位

#include <iostream>
#include <string>
#include <cstring>
using namespace std;
#define ull unsigned long long

const int maxn = 1e6 + 10;
ull hash_[maxn];
ull p[maxn];
ull cnt;
int ans,T;
char a[maxn],b[maxn];

int main()
{
    ios::sync_with_stdio(false);

    cin >> T;
    while(T--){
        ans = 0;
        cnt = 0;
        p[0] = 1;
        cin >> a >> b;
        
        int len1 = strlen(a);
        int len2 = strlen(b);
        for(int i=1;i<=len1;i++)p[i] = p[i-1]*100;
        for(int i=0;i<len1;i++)cnt = cnt*100 + a[i] - 'A' + 1;//转换成一串数字
        hash_[0] = b[0] - 'A' + 1;
        for(int i=1;i<len2;i++){
            hash_[i] = hash_[i-1] * 100 + b[i] - 'A' + 1;
        }
        for(int i=len1-1;i<len2;i++){
            if(i==len1-1&&cnt==hash_[i])ans++;
            else if(cnt == hash_[i] - hash_[i-len1]*p[len1])ans++;
        }
        cout << ans << endl;
    }
}

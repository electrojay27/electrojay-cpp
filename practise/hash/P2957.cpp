#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
#define base 107//取整容易只因
#define ull unsigned long long

const int maxn = 4e5 + 10;
ull Hash_1[maxn];
ull Hash_2[maxn];
ull p[maxn];
char a[maxn],b[maxn];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    p[0] = 1;
    for(int i=1;i<=maxn;i++)p[i] = p[i-1] * base;
    while(cin >> a >> b){
        // vector<int> ans;
        int ans = 0;
        int len_1 = strlen(a);
        int len_2 = strlen(b);
        Hash_1[0] = a[0] - 'A' + 1;
        Hash_2[0] = b[0] - 'A' + 1;
        for(int i=1;i<len_1;i++)Hash_1[i] = Hash_1[i-1] * base + a[i] - 'A' + 1;
        for(int i=1;i<len_2;i++)Hash_2[i] = Hash_2[i-1] * base + b[i] - 'A' + 1;
        for(int i=0,j=len_2-1;i<len_1,j>=0;i++,j--){
            if(j == 0){
                if(Hash_2[len_2-1] == Hash_1[len_2-1])ans = max(ans,len_2);
            }else if(i == len_1-1){
                if(Hash_1[i] == Hash_2[len_2-1] - Hash_2[len_2 - i]*p[i])ans = max(ans,len_1);
            }
            if(Hash_1[i] == Hash_2[j] - Hash_2[j-i]*p[i])ans = max(ans,i);
        }
        for(int i=0,j=len_1-1;i<len_2,j>=0;i++,j--){
            if(j == 0){
                if(Hash_1[len_1-1] == Hash_2[len_1-1])ans = max(ans,len_1);
            }else if(i == len_2-1){
                if(Hash_2[i] == Hash_1[len_1-1] - Hash_1[len_1 - i]*p[i])ans = max(ans,len_2);
            }
            if(Hash_2[i] == Hash_1[j] - Hash_1[j-i]*p[i])ans = max(ans,i);
        }
        cout << ans << endl;
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
#define ll long long

int vis[27];//标记是否访问过,顺便记录次数
// string a;

int main()
{
    ll sum;
    int t,n;
    ios::sync_with_stdio(false);//提高cin读取速度
    cin >> t;
    while(t--){
        string a;
        sum = 0;
        memset(vis,0,sizeof(vis));
        // map<int,int> vis;
        cin >> a >> n;
        int l = 0,r = 0;
        int cnt = 0;
        while(l <= r&&l <= a.size() - n){
            while(r < a.size() && cnt < n){
                if(!vis[a[r] - 'a'])cnt ++;
                vis[a[r] - 'a']++;
                r++;
            }
            if(cnt >= n)sum += (a.size() - r + 1);
            else break;
            vis[a[l]-'a']--;
            if(!vis[a[l]-'a'])cnt--;
            l ++;
        }
        printf("%lld\n",sum);
    }return 0;
}
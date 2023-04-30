#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 10;
// vector<string> a;
map<string,int> all;//标记是否背
map<string,int> vis;//标记是否访问
// vector<string> wz;//记录文章
string wz[maxn];

int main()
{
    ios::sync_with_stdio(false);//提高cin读取速度

    int n,m;
    string op;
    cin >> n;
    for(int i = 1;i <= n;i ++){
        cin >> op;
        all[op] = 1;//记录要背的单词
    }

    cin >> m;
    int cnt = 0;//记录文章最多包含的单词数（要背的）
    int ans = 1e5;//记录最短长度
    int cmp = 0;//标记背的单词数
    for(int i = 1;i <= m;i ++){
        cin >> wz[i];
        if(all[wz[i]] == 1)cnt++,all[wz[i]]++;
    }

    int l = 1,r = 1;
    while(l <= r && l <= m){
        while(r <= m&&cmp < cnt){
            if(all[wz[r]]){
                if(!vis[wz[r]])cmp++;
                vis[wz[r]]++;
            }
            if(r < m&&cmp < cnt)r ++;
        }
        // if(cmp >= cnt)ans = min(ans,r-l+1);
        if(!all[wz[l]]){
            l++;
        }
        if(vis[wz[l]]>1){
            vis[wz[l]] --;
            l ++;
        }//移动左端点
        if(cmp == cnt)ans = min(ans,r-l+1);
        if(vis[wz[l]]==1){
            vis[wz[l]]--;
            l ++;
            cmp --;
        }
    }
    cout << cnt << endl << ans << endl;
    return 0;
}
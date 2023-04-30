#include <bits/stdc++.h>
using namespace std;

int n;
int a[100];
int cnt[1000];
int mx,mn;

bool dfs(int goal,int num,int now,int last){
    if(num == 0)return true;
    if(now == goal)return dfs(goal,num - 1,0,mx);
    for(int i = last;i >= mn;i --){
        if(cnt[i] && now + i <= goal){
            cnt[i] --;
            if(dfs(goal,num,now + i,i))return true;
            cnt[i] ++;//回溯

            if(now == 0 || now + i == goal)return false;
        }
    }
    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    while(cin >> n){
        mn = 110;
        mx = 0;
        int all = 0;
        memset(cnt,0,sizeof(cnt));

        for(int i = 1;i <= n;i ++){
            cin >> a[i];
            all += a[i];
            cnt[a[i]] ++;
            mx = max(a[i],mx);
            mn = min(a[i],mn);
        }

        // sort(a + 1,a + 1 + n);

        for(int i = mx;i <= all / 2;i ++){
            if(all % i != 0)continue;

            if(dfs(i,all / i,0,mx)){
                cout << i << endl;
                return 0;
            }
        }

        cout << all << endl;//如果上面的一半都没搜索到，就说明只剩下总和这个答案了
    }
    return 0;
}
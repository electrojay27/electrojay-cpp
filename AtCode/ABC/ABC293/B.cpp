#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 10;
int vis[maxn];
int n,x;

int main()
{
    ios::sync_with_stdio(false);

    while(cin >> n){
        vector<int> ans;
        memset(vis,0,sizeof(vis));
        for(int i=1;i<=n;i++){
            cin >> x;
            if(!vis[i])vis[x]=1;
        }
        for(int i=1;i<=n;i++)if(!vis[i])ans.push_back(i);
        cout << ans.size() << endl;
        for(int i=0;i<ans.size();i++)cout << ans[i] << " ";
        cout << endl;
    }
}
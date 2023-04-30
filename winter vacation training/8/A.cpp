#include <bits/stdc++.h>
using namespace std;
int in[510];//表示入度
int n,m;
int main()
{
    while(scanf("%d%d",&n,&m)!=EOF){
        vector<int> all[510];
        memset(in,0,sizeof(in));
        int a,b;
        for(int i=1;i<=m;i++){
            scanf("%d%d",&a,&b);
            all[a].push_back(b);
            in[b]++;//表示入度加一
        }
        priority_queue<int,vector<int>,greater<int> > q;
        for(int i=1;i<=n;i++){
            if(!in[i])q.push(i);
        }
        // vector<int> ans;
        while(!q.empty()){
            int cnt = q.top();
            // ans.push_back(cnt);
            q.pop();
            for(int i=0;i<all[cnt].size();i++){
                int x = all[cnt][i];
                in[x]--;
                if(!in[x])q.push(x);
            }
            if(!q.empty())printf("%d ",cnt);
            else printf("%d\n",cnt);
        }
    }
    // if(ans.size() == n){
    //     printf("%d",ans[0]);
    //     for(int i=1;i<ans.size();i++){
    //         printf(" %d",ans[i]);
    //     }printf("\n");
    // }
}
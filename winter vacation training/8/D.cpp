#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn = 3e4 + 10;
int in[maxn];
int main()
{
    int T,n,m;
    scanf("%d",&T);
    while(T--){
        memset(in,0,sizeof(in));
        vector<int> p[maxn];
        vector<int> ans;
        // map<int,int> find;//查重
        scanf("%d%d",&n,&m);
        int a,b;
        for(int i=1;i<=m;i++){
            scanf("%d%d",&a,&b);
            // if(find[a*10+b])continue;
            // find[a*10+b] = 1;
            // p[a].push_back(b);//由于出来的答案与原本有所误差，经过演算发现可能会出错，所以尝试反图
            p[b].push_back(a);
            in[a]++;
        }
        // priority_queue<int,vector<int>,greater<int> > q;
        priority_queue<int,vector<int>,less<int> > q;//反向
        for(int i=1;i<=n;i++)if(!in[i])q.push(i);
        while(!q.empty()){
            int cnt = q.top();
            q.pop();
            ans.push_back(cnt);
            for(int i=0;i<p[cnt].size();i++){
                int cmp = p[cnt][i];
                in[cmp] --;
                if(!in[cmp])q.push(cmp);
            }
            // if(!q.empty())printf("%d ",cnt);
            // else printf("%d\n",cnt);
        }
        printf("%d",ans[ans.size()-1]);
        for(int i = ans.size()-2;i>=0;i--){
            printf(" %d",ans[i]);
        }printf("\n");
    }
}
#include <bits/stdc++.h>
using namespace std;
int n;
int main()
{
    while(scanf("%d",&n)!=EOF&&n){
        vector<string> all;
        map<string,int> in;
        string a,b;
        for(int i=1;i<=n;i++){
            cin >> a >> b;
            if(!in[a]){
                all.push_back(a);
                in[a] = 1;
            }else if(in[a]!=1){
                in[a]++;
            }
            if(!in[b])all.push_back(b);
            in[b]+=2;
        }
        int cnt = 0;
        for(int i=0;i<all.size();i++){
            if(in[all[i]]==1)cnt ++;
        }
        if(cnt == 1)printf("Yes\n");
        else printf("No\n");
    }
}
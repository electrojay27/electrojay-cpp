#include <bits/stdc++.h>
using namespace std;
// const int maxn = 2e4 + 10;
int n,m,k;
map<string,string> p;
string find(string op){
    if(p[op]==op)return p[op];
    return p[op] = find(p[op]);
}
int main()
{
    while(scanf("%d%d",&n,&m)!=EOF){
        for(int i=1;i<=n;i++){
            string op;
            cin >> op;
            p[op] = op;
        }
        for(int i=1;i<=m;i++){
            string a,b;
            cin >> a >> b;
            p[find(a)] = find(b);
        }
        scanf("%d",&k);
        for(int i=1;i<=k;i++){
            string a,b;
            cin >> a >> b;
            if(find(a)==find(b))printf("Yes.\n");
            else printf("No.\n");
        }
    }
}
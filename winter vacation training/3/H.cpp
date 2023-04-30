#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
int k,d,m,f,q;
int main()
{
    while(scanf("%d%d%d%d",&k,&d,&m,&f)!=EOF){
        // queue<int> kk;
        // queue<int> dd;
        // queue<int> mm;
        // queue<int> ff;
        priority_queue<int> kk,dd,mm,ff;
        int a,b,c;
        for(int i=0;i<k;i++){
            scanf("%d",&a);
            kk.push(a);
        }
        for(int i=0;i<d;i++){
            scanf("%d",&a);
            dd.push(a);
        }
        for(int i=0;i<m;i++){
            scanf("%d",&a);
            mm.push(a);
        }
        for(int i=0;i<f;i++){
            scanf("%d",&a);
            ff.push(a);
        }
        scanf("%d",&q);
        for(int i=1;i<=q;i++){
            scanf("%d%d%d",&a,&b,&c);
            int ret = 0;
            ret += kk.top();
            kk.pop();
            for(int i=0;i<a;i++){
                ret += dd.top();
                dd.pop();
            }
            for(int i=0;i<b;i++){
                ret += mm.top();
                mm.pop();
            }
            for(int i=0;i<c;i++){
                ret += ff.top();
                ff.pop();
            }
            printf("%.2f\n",ret/11.0);
        }
    }
}
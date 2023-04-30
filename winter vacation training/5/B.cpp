#include <bits/stdc++.h>
using namespace std;

bool flag;
int s,n,m;
int ans;
const int maxn = 110;
bool vis[maxn][maxn][maxn];
struct B
{
    int a,b,c,step;
};


void solve(B cnt){
    queue<B> q;
    B cmp;
    q.push(cnt);
    while(!q.empty()){
        B a = q.front();
        q.pop();
        if(a.a == a.b&&!a.c){
            flag = 1;
            ans = a.step;
            break;
        }else{
            for(int i=1;i<=6;i++){
                //表示6种状态
                //1 -> 2
                if(i==1){
                    if(a.a + a.b <= n){
                        cmp = {0,a.a+a.b,a.c};
                    }else{
                        cmp = {a.a+a.b-n,n,a.c};
                    }
                }
                //1 -> 3
                if(i==2){
                    if(a.a + a.c <= m){
                        cmp = {0,a.b,a.a+a.c};
                    }else{
                        cmp = {a.a+a.c-m,a.b,m};
                    }
                }
                //2 -> 3
                if(i==3){
                    if(a.b + a.c <= m){
                        cmp = {a.a,0,a.c+a.b};
                    }else{
                        cmp = {a.a,a.c+a.b-m,m};
                    }
                }
                //3 -> 2
                if(i==4){
                    if(a.b + a.c <= n){
                        cmp = {a.a,a.b+a.c,0};
                    }else{
                        cmp = {a.a,n,a.c+a.b-n};
                    }
                }
                //3 -> 1
                if(i==5){
                    if(a.a + a.c <= s){
                        cmp = {a.a+a.c,a.b,0};
                    }else{
                        cmp = {s,a.b,a.c+a.a-s};
                    }
                }
                //2 -> 
                if(i==6){
                    if(a.b + a.a <= s){
                        cmp = {a.b+a.a,0,a.c};
                    }else{
                        cmp = {s,a.a+a.b-s,a.c};
                    }
                }
                if(!vis[cmp.a][cmp.b][cmp.c]){
                    cmp.step = a.step + 1;
                    vis[cmp.a][cmp.b][cmp.c] = 1;
                    q.push(cmp);
                }//记录状态
            }
            
        }
    }
    if(!flag)cout << "NO\n";
    else cout << ans << "\n";
}
int main()
{
    ios::sync_with_stdio(false);
    while(cin >> s >> n >> m&&s&&n&&m){
        if(s & 1){
            cout << "NO" << endl;
            continue;
        }else{
            memset(vis,0,sizeof(vis));//初始化
            ans = -1;
            flag = 0;
            if(n < m)swap(n,m);//将大的杯子往前，方便比较
            B S = {s,0,0,0};
            vis[s][0][0];
            solve(S);
        }
    }
    return 0;
}
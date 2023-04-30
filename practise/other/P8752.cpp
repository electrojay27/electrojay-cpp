#include <bits/stdc++.h>
using namespace std;

int a[6],y[5];

void solve(){
    int ans = 0;
    for(int i=1;i<=5;i++){
        int cnt = 1;
        int cmp = a[i];
        while(cmp > 0){
            y[cnt++] = cmp % 10;
            cmp /= 10;
        }
        if(y[2] == y[4]&&y[1] - 1 == y[3])ans++;
    }
    printf("%d\n",ans);
}

int main(){
    for(int i=1;i<=5;i++)
        scanf("%d",&a[i]);
    solve();
    return 0;
}
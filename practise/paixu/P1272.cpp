#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e6 + 10;
int a[maxn],book[1000];
int n,m,x;

void solve()
{
    // 直接用sort
    // sort(a+1,a+1+m);
    // for(int i=1;i<=m;i++){
    //     if(i==1)printf("%d",a[i]);
    //     else printf(" %d",a[i]);
    // }printf("\n");

    //桶排序
    for(int i=1;i<=n;i++){
        if(book[i]){
            for(int j=book[i];j>0;j--)
                cout << i << " ";
        }
    }
    cout << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    memset(book,0,sizeof(book));
    while(cin >> n >> m){
        for(int i=1;i<=m;i++){
            cin >> x;
            book[x] ++;
        }
        solve();
    }
    return 0;
}
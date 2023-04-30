#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e4 + 10;
// struct stu
// {
//     string na;//记录名字
//     int id;
// }p[maxn];
map<string,string> per;
string find(string a){
    if(per[a]==a)return per[a];
    return per[a] = find(per[a]);
}//改变组别队长
int n,m,k;
int main()
{
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        string x;
        cin >> x;
        per[x] = x;//通过map来记录学生的名字和组别队长
    }
    for(int i=1;i<=m;i++){
        string a,b;
        cin >> a >> b;
        per[find(a)] = find(b);//合并
    }
    cin >> k;
    for(int i=1;i<=k;i++){
        string a,b;
        cin >> a >> b;
        if(find(a)==find(b))printf("Yes.\n");
        else printf("No.\n");
    }
    return 0;
}

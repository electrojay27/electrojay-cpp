#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

struct node
{
    int dn;
    int v[510] = {0};
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<node> p(n);
    for(int i = 0;i < n;i ++){
        int x,num;
        cin >> p[i].dn >> num;
        for(int j = 0;j < n;j ++){
            cin >> x;
            cin >> p[i].v[j];
        }
    }

    int m;
    cin >> m;
    for(int i = 0;i < m;i ++){
        string s;
        cin >> s;
        if(s[0] == '|'){

        }else if(s[0] == '&'){

        }else if(s[1] == ':'){

        }else if(s[1])
    }

    return 0;
}
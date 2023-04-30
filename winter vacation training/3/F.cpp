#include <bits/stdc++.h>
using namespace std;
map<string,string> p;
string find(string a){
    if(p[a]==a)return p[a];
    return p[a] = find(p[a]);
}
int main()
{
    char op;
    string a;
    string s;

    while(cin >> op && op != '$'){
        cin >> a;
        if(op == '#'){
            if(p[a]=="")p[a] = a;
            s = a;
        }else if(op == '+'){
            p[a] = find(s);
        }else{
            cout << a << " " << find(a) << endl;
        }
    }
    printf("\n");
    return 0;
}
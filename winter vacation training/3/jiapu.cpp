#include <bits/stdc++.h>
using namespace std;
map<string,string> all;
string find(string a){
    if(all[a]==a)return all[a];
    return all[a] = find(all[a]);
}
int main(){
    char op;
    string a,b;
    cin >> op;
    while(op != '$'){
        cin >> a;
        if(op == '#'){
            b = a;
            if(all[a]=="")all[a] = a;
        }else if(op == '+'){
            all[a] = b;
        }else{
            cout << a << ' ' << find(a) << endl;
        }
        cin >> op;
    }return 0;
}
#include <bits/stdc++.h>
using namespace std;

unordered_map<int,unordered_map<int,set<int>>> dn_val;
unordered_map<int,set<int>> dn_find;

int getnum(string s) {
    int res = 0;
    for (int i = 0; i < s.size(); i++) {
        res *= 10;
        res += s[i] - '0';
    }
    return res;
}

set<int> base(string s) {
    set<int> res;
    int to = 0;
    while (s[to] != ':' && s[to] != '~') to++;
    int a = getnum(s.substr(0,to));
    int b = getnum(s.substr(to + 1,s.size()));
    // cout << a << " " << b << endl;
    if (s[to] == ':') {
        res.insert(dn_val[a][b].begin(),dn_val[a][b].end());
    } else {
        res.insert(dn_find[a].begin(),dn_find[a].end());
        set<int> head;
        for (auto it : dn_val[a][b]) {
            if (res.count(it)) {
                head.insert(it);
            }
        }

        for (auto it : head) res.erase(it);
    }
    return res;
}

set<int> check(string s) {
    set<int> res;
    if (s[0] >= '0' && s[0] <= '9') {
        res = base(s);
    } else {
        if (s[0] == '&') {
            int to = 1;
            set<int> res1,res2;
            stack<char> st;
            st.push('(');
            while (!st.empty()) {
                to ++;
                if (s[to] == '(') {
                    st.push('(');
                } else if (s[to] == ')'){
                    st.pop();
                }
            }
            // cout << to << endl;
            res1 = check(s.substr(2,to - 2));

            int en = to + 2;
            st.push('(');
            while(!st.empty()) {
                en ++;
                if(s[en] == '(') {
                    st.push('(');
                }
                else if(s[en] == ')') {
                    st.pop();
                }
            }
            // cout << en << endl;
            res2 = check(s.substr(to + 2, en - to - 2));
            for (auto it : res1) {
                if (res2.count(it)) {
                    res.insert(it);
                }
            }
        } else {
            int to = 1;
            set<int> res1,res2;
            stack<char> st;
            st.push('(');
            while(!st.empty()) {
                to ++;
                if(s[to] == '(') {
                    st.push('(');
                }
                else if(s[to] == ')') {
                    st.pop();
                }
            }
            res1 = check(s.substr(2, to-2));
            int en = to+2;
            st.push('(');
            while(!st.empty()) {
                en ++;
                if(s[en] == '(') {
                    st.push('(');
                }
                else if(s[en] == ')') {
                    st.pop();
                }
            }
            res2 = check(s.substr(to+2, en-to-2));
            
            res.insert(res1.begin(), res1.end());
            res.insert(res2.begin(), res2.end());
        }
    }
    return res;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int dn,num;
        cin >> dn >> num;
        for (int i = 0; i < n; i++) {
            int id,val;
            cin >> id >> val;
            dn_val[id][val].insert(dn);
            dn_find[id].insert(dn);
        }
    }

    int m;
    cin >> m;
    for (int i = 0;i < m;i ++) {
        string s;
        cin >> s;
        set<int> ans = check(s);
        for (auto it : ans) {
            cout << it << " ";
        }
        cout << "\n";
    }

    return 0;
}
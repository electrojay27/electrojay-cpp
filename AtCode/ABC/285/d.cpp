#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	vector<string> s(n);
	vector<string> t(n);
	for(int i = 0;i < n;i ++){
		cin >> s[i] >> t[i];
	}

	map<string,int> st;
	for(int i = 0;i < n;i ++){
		st[s[i]] = i;
	}

	vector<int> vis(n,0);
	for(int i = 0;i < n;i ++){
		if(vis[i])continue;

		string op = t[i];
		vis[i] = 1;
		while(st.count(op)){
			vis[st[op]] = 1;
			op = t[st[op]];
			if(op == s[i]){
				cout << "No\n";
				return 0;
			}
		}
	}

	cout << "Yes\n";
}
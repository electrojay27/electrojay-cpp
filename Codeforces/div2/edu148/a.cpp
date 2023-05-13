#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve(){
	string s;
	cin >> s;

	set<int> st;
	for(int i = 0;i <= (s.size() - 2) / 2;i ++){
		if(!st.count(s[i])){
			st.insert(s[i]);
		}
	}

	if(st.size() != 1){
		cout << "YES\n";
	}else cout << "NO\n";
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;

	while(t --){
		solve();
	}

	return 0;
}
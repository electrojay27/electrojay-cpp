#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve()
{
	int n;
	cin >> n;

	map<int,int> st;
	int x;
	for(int i = 0;i < n;i ++){
		cin >> x;
		st[x] ++;
	}

	int ans = 0;
	int flag;
	for(auto it = st.begin();it != st.end();it ++){
		if(ans < it->second){
			ans = it->second;
			flag = it->first;
		}
	}

	int cnt = st.size() - 1;
	st[flag] -= cnt;
	if(!st[flag]){
		ans = cnt;
	}else if(st[flag] > 0){
		if(st[flag] > 1){
			ans = cnt + 1;
		}else{
			ans --;
		}
	}

	cout << ans << "\n";
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
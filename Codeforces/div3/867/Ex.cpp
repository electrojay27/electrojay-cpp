#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve()
{
	int n;
	string s;
	cin >> n >> s;

	if(n % 2){
		cout << "-1\n";
		return;
	}

	vector<int> str(26,0);
	for(int i = 0;i < n;i ++){
		str[s[i] - 'a'] ++;	
	}

	for(int i = 0;i < 26;i ++){
		if(str[i] > n/2){
			cout << "-1\n";
			return;
		}
	}

	int ans = 0;
	vector<pair<int,int>> dui;
	for(int i = 0;i < s.size()/2;i ++){
		if(s[i] == s[s.size() - 1 - i]){
			dui.push_back({i,s.size() - i - 1});
		}
	}

	vector<int> ret(26,0);
	int flag = 0;
	for(int i = 0;i < dui.size();i ++){
		ret[s[dui[i].first] - 'a']++;
		ans ++;
	}

	ans = (ans + 1) / 2;

	for(int i = 0;i < 26;i ++){
		if(ret[i] >= dui.size() / 2){
			ans = max(ans,ret[i]);
			break;
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
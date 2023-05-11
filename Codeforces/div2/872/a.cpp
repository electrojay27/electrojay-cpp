#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve()
{
	string s;
	cin >> s;

	vector<int> a(26,0);
	for(int i = 0;i < s.size();i ++){
		a[s[i] - 'a'] ++;
	}

	for(int i = 0;i < 26;i ++){
		if(a[i] == s.size()){
			cout << "-1\n";
			return;
		}
	}

	cout << s.size() - 1 << "\n";
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
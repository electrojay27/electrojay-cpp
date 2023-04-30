#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve()
{
	string s;

	cin >> s;

	int ans = 0;
	for(int i = 0;i < s.size();i ++){
		if(!i && s[i] == '_'){
			if(s[i + 1] == '_' || i == s.size() - 1)ans += 2;
			else ans ++;

			continue;
		}

		if(s[i] == '_'){
			if(s[i + 1] == '_' || i == s.size() - 1){
				ans ++;
			}
		}
	}

	if(s.size() == 1 && s == "^")ans ++;

	cout << ans << endl;
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
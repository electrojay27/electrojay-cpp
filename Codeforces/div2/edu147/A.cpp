#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve()
{
	string s;
	cin >> s;

	int ans = 1;
	for(int i = 0;i < s.size();i ++){
		if(!i && s[i] == '?'){
			ans *= 9;
		}else if(i && s[i] == '?'){
			ans *= 10;
		}
	}
	if(s[0] == '0'){
		cout << 0 << "\n";
		return;
	}else if(ans == 1 && s[0] != '0'){
		cout << 1 << "\n";
		return;
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
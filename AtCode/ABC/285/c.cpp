#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	string s;
	cin >> s;

	i64 ans = 0;
	for(int i = 0;i < s.size();i ++){
		ans = ans * 26 + s[i] - 'A' + 1;
	}

	cout << ans << "\n";
}
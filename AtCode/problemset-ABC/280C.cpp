#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	string s,op;
	cin >> s >> op;

	int ans = op.size();
	for(int i = 0;i < s.size();i ++){
		if(s[i] != op[i]){
			ans = i + 1;
			break;
		}
	}

	cout << ans << "\n";

	return 0;
}
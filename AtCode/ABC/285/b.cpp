#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	string s;
	cin >> n >> s;

	for(int i = 1;i < n;i ++){
		int ans = 0;
		for(int j = 0;j + i < n;j ++){
			if(s[j] != s[j + i])ans ++;
			else break;
		}
		cout << ans << "\n";
	}
}
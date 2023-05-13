#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n,m;
	cin >> n >> m;
	string s[n];
	for(int i = 0;i < n;i ++)cin >> s[i];

	int ans = 0;
	for(int i = 0;i < n;i ++){
		for(int j = 0;j < m;j ++){
			if(s[i][j] == '#')ans ++;
		}
	}	

	cout << ans << "\n";
}
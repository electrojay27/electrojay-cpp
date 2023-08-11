#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	string v[n];
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	string ans[n];
	ans[0] = v[1][0] + v[0].substr(0,n - 1);
	for (int i = 1; i < n - 1; i++) {
		ans[i] = v[i + 1][0] + v[i].substr(1,n - 2) + v[i - 1][n - 1];
	}
	ans[n - 1] = v[n - 1].substr(1,n - 1) + v[n - 2][n - 1];

	for (int i = 0; i < n; i++) {
		cout << ans[i] << "\n";
	}
}
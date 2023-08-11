#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	int a,b,c;
	cin >> a >> b >> c;

	if (max(a + b, max(b + c, c + a))>= 10) {
		cout << "YES\n";
		return;
	}
	cout << "NO\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;

	while (t--) {
		solve();
	}

	return 0;
}
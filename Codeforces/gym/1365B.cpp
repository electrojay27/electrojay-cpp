#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	int n;
	cin >> n;

	vector<int> a(n),b(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < n; i++) cin >> b[i];

	bool flag = true;
	for (int i = 0; i < n; i++) {
		if (i && a[i] < a[i - 1]) {
			flag = false;
			break;
		}
	}

	bool Flag = false;
	for (int i = 0; i < n; i++) {
		if (i && b[i] != b[i - 1]) {
			Flag = true;
			break;
		}
	}

	if (Flag || flag) cout << "YES\n";
	else cout << "NO\n";
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
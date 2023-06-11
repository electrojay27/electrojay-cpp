#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	int n;
	cin >> n;

	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	sort(a.begin(),a.end());

	i64 sum = 0;
	for (int i = 0; i < n; i++) {
		if (!i && a[i] == 1 || sum >= a[i]) {
			sum += a[i];
		} else {
			cout << "No\n";
			return;
		}
	}

	cout << "Yes\n";
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
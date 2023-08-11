#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

vector<int> a(1001,0);

void solve() {
	int n;
	cin >> n;

	cout << a[n - 1] << "\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;

	int to = 0;

	for (int i = 1; to < 1000; i++) {
		int x = i;
		if (i % 3 && i % 10 != 3) a[to ++] = i;
	}

	while (t--) {
		solve();
	}
	return 0;
}
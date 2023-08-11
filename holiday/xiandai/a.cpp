#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	int n;
	cin >> n;

	vector<vector<double>> a(n,vector<double>(n + 1));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n + 1; j++) {
			cin >> a[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		int now = i;
		while (now < n && a[now][i] == 0) {
			now ++;
		}

		if (now == n) {
			cout << "No Solution\n";
			return;
		}

		for (int j = 0; j < n + 1; j++) {
			swap(a[i][j],a[now][j]);
		}

		double ret = a[i][i];

		for (int j = 0; j < n + 1; j++) {
			a[i][j] /= ret;
		}

		for (int j = 0; j < n; j++) {
			if (i == j) continue;

			double res = a[j][i];
			for (int k = 0; k < n + 1; k++) {
				a[j][k] -= res * a[i][k];
			}
		}
	}

	for (int i = 0; i < n; i++) {
		cout << fixed << setprecision(2) << a[i][n] << "\n"; 
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	// int t;
	// cin >> t;
	int t = 1;

	while (t--) {
		solve();
	}

	return 0;
}
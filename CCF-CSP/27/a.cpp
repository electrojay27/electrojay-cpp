#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	i64 m;
	cin >> n >> m;

	vector<int> a(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}

	vector<int> c(n + 1,1);
	for (int i = 1; i <= n; i++) {
		c[i] = a[i] * c[i - 1];
	}

	vector<int> b(n);
	for (int i = 0; i < n; i++) {
		int cnt = m % c[i + 1];
		int to = 0;
		while (to < i) {
			cnt -= b[to + 1] * c[to];
			to ++;
		}
		b[i] = cnt / c[i];
	}

	for (auto it : b) {
		cout << it << " ";
	}
	cout << "\n";
}
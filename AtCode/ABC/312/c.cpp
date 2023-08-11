#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n,m;
	cin >> n >> m;

	vector<int> a(n + m);

	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	for (int i = n; i < n + m; i++) {
		cin >> a[i];
		a[i] ++;
	}

	nth_element(a.begin(), a.begin() + m - 1, a.end());
	cout << a[m - 1] << "\n";
}
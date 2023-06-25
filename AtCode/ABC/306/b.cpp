#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using ui64 = unsigned long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	vector<ui64> a(64);

	for (int i = 0; i < 64; i++) {
		cin >> a[i];
	}

	ui64 ans = 0;
	ui64 base = 1;
	for (int i = 0; i < 64; i++) {
		ans += a[i] * base;
		base *= 2;
	}

	cout << ans << "\n";
}
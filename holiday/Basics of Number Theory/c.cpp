#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	int a,b;
	cin >> a >> b;

	for (int i = b + 1; ; i++) {
		if (__gcd(a,i) == b && __gcd(i,b) == b) {
			cout << i << "\n";
			return;
		}
	}
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
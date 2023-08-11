#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	int a,b,c,d;
	cin >> a >> b >> c >> d;

	int fz = a * d + c * b;
	int fm = b * d;

	int v = __gcd(fz,fm);

	cout << fz / v << " " << fm / v << "\n";
	
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
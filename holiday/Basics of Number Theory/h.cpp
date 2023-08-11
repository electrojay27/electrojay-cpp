#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

i64 exgcd(i64 a, i64 b, i64& x, i64& y) {
	if (!b) {
		x = 1;
		y = 0;
		return a;
	}

	i64 ans = exgcd(b,a % b,x,y);
	i64 temp = x;
	x = y;
	y = temp - a / b * y;
	return ans;
}

void solve() {
	i64 x,y,n,m,l;
	cin >> x >> y >> m >> n >> l;

	i64 a = y - x;
	i64 b = m - n;
	if (b < 0) {
		b = -b;
		a = -a;
	}

	i64 ans = exgcd(b,l,x,y);
	if  (a % ans) {
		cout << "Impossible\n";
	} else {
		cout << ((x * (a / ans)) % (l / ans) + (l / ans)) % (l / ans) << "\n";
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
#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

map<array<i64, 3>, i64> f;

i64 solve(i64 a, i64 b, i64 c) {
	array<i64, 3> cnt = {a,b,c};

	if (f.count(cnt)) {
		return f[cnt];
	}

	if (a <= 0 || b <= 0 || c <= 0) {
		return f[cnt] = 1;
	} else if (a > 20 || b > 20 || c > 20) {
		return f[cnt] = solve(20,20,20);
	} else if (a < b && b < c) {
		return f[cnt] = solve(a, b, c - 1) + solve(a, b - 1, c - 1) - solve(a, b - 1, c);
	} else {
		return f[cnt] = solve(a - 1, b, c) + solve(a - 1, b - 1, c) + solve(a - 1, b, c - 1) - solve(a - 1, b - 1, c - 1);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	i64 a,b,c;
	while (cin >> a >> b >> c) {
		if (a == -1 && b == -1 && c == -1) {
			break;
		}

		cout << "w(" << a << ", " << b << ", " << c << ") = " <<  solve(a,b,c) << "\n";
	}
}
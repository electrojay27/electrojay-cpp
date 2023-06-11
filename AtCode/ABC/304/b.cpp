#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	if (n >= 1000 && n < 10000) {
		n /= 10;
		n *= 10;
	} else if (n >= 10000 && n < 100000) {
		n /= 100;
		n *= 100;
	} else if (n >= 100000 && n < 1000000) {
		n /= 1000;
		n *= 1000;
	} else if (n >= 1000000 && n < 10000000) {
		n /= 10000;
		n *= 10000;
	} else if (n >= 10000000 && n < 100000000) {
		n /= 100000;
		n *= 100000;
	} else if (n >= 100000000 && n < 1000000000) {
		n /= 1000000;
		n *= 1000000;
	}

	cout << n << "\n";
}
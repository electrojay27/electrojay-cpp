#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	i64 n;
	cin >> n;

	int k;
	cin >> k;
	for (int i = 0; i < k; i++) {
		if (n % 200) {
			n = n * 1000 + 200;
		} else {
			n /= 200;
		}
	}

	cout << n << "\n";
}
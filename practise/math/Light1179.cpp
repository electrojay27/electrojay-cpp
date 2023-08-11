#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
	int t;
	cin >> t;
	for (int j = 0; j < t; j++) {
		int n,k;
		cin >> n >> k;

		cout << "Case " << j + 1 << ": "; 
		int ans = 0;
		for (int i = 1; i <= n; i++) {
			ans = (ans + k) % i;
		}

		cout << ans + 1 << "\n";
	}
}
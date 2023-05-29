#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n,x;
	cin >> n >> x;

	vector<int> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];

	vector<int> dp(300005,0);
	dp[0] = 1;
	for (int i = 0; i < n; i++) {
		for (int j = 300000 - a[i]; j >= 0; j--) {
			if (dp[j]) {
				dp[j + a[i]] = 1;
			}
		}
	}

	for (int i = x; i <= 300000; i++) {
		if (dp[i]) {
			cout << i << "\n";
			break;
		}
	}
}
#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	vector<int> a(n,0);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 7;j ++) {
			int x;
			cin >> x;
			a[i] += x;
		}
	}

	for (int i = 0; i < n; i++) {
		cout << a[i] << " \n"[i == n - 1];
	}
}
#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void Cout(int mid,int l) {
	cout << "? ";
	cout << mid - l + 1;
	for (int i = l; i <= mid; i++) {
		cout << " " << i;
	}
	cout << endl;
}

void solve() {
	int n;
	cin >> n;

	vector<int> a(n),c(n + 1,0);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		c[i + 1] = c[i] + a[i];
	}

	int l = 1,r = n;
	while (l < r) {
		int mid = (l + r) / 2;
		Cout(mid,l);
		int x;
		cin >> x;
		if (x > c[mid] - c[l - 1]) {
			r = mid;
		} else {
			l = mid + 1;
		}
	}

	cout << "! " <<  r << endl;
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
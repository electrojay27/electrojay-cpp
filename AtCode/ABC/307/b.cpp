#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	vector<string> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			string op = a[i] + a[j];
			int flag = 0;
			for (int l = 0,r = op.size() - 1;l < r; l++,r--) {
				if (op[l] != op[r]) {
					flag = 1;
					break;
				}
			}
			if (!flag) {
				cout << "Yes\n";
				return 0;
			}

			op = a[j] + a[i];
			flag = 0;
			for (int l = 0,r = op.size() - 1;l < r; l++,r--) {
				if (op[l] != op[r]) {
					flag = 1;
					break;
				}
			}
			if (!flag) {
				cout << "Yes\n";
				return 0;
			}
		}
	}

	cout << "No\n";
}
#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	while (cin >> t) {
		vector<queue<int>> a(t);
		for (int i = 0;i < t;i ++) {
			int n;
			cin >> n;
			for (int i = 0;i < n;i ++) {
				int x;
				cin >> x;
				a[i].push(x);
			}
		}
	}
	
}
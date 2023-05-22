#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	int n,k;
	cin >> n >> k;

	vector<int> a(n);
	set<int> st;
	vector<int> ans;
	for (int i = 0;i < n;i ++) {
		cin >> a[i];
		if (!st.count(a[i])) ans.push_back(a[i]);
		st.insert(a[i]);
	}

	if (st.size() > k) {
		cout << "-1\n";
		return;
	}

	sort(ans.begin(),ans.end());
	int to = ans.size();
	for (int i = to + 1;i <= k;i ++) {
		ans.push_back(1);
	}

	cout << ans.size() * n << "\n";
	for (int i = 0;i < n;i ++) {
		for (auto it : ans) {
			cout << it << " ";
		}
	}

	cout << "\n";
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
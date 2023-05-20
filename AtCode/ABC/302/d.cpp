#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n,m;
	i64 d;
	cin >> n >> m >> d;

	vector<i64> a(n),b(m);
	for (int i = 0;i < n;i ++) cin >> a[i];
	for (int i = 0;i < m;i ++) cin >> b[i];

	sort(a.begin(),a.end());
	sort(b.begin(),b.end());

	i64 ans = 0;
	for (int i = n - 1;i >= 0;i --) {
		auto cntl = lower_bound(b.begin(),b.end(),a[i] - d);
		auto cntr = lower_bound(b.begin(),b.end(),a[i] + d);
		for (auto j = cntl;j <= cntr;j ++) {
			if (fabs(a[i] - *j) <= d) {
				ans = max(ans,a[i] + *j);
			}
		}

		if(ans)break;
	}

	if (ans) cout << ans << "\n";
	else cout << "-1\n";
}
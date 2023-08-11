#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

struct node
{
	int a,b;

	bool operator < (const node& that) const {
		return a < that.a;
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n,k;
	cin >> n >> k;

	vector<node> v(n);

	i64 limit = 0;

	for (int i = 0; i < n; i++) {
		cin >> v[i].a >> v[i].b;
		limit += v[i].b;
	}

	sort(v.begin(),v.end());

	if (limit <= k) {
		cout << 1 << "\n";
		return 0;
	}

	int ans = 0;
	for (int i = 0; i < n; i++) {
		limit -= v[i].b;
		if (limit <= k) {
			ans = v[i].a + 1;
			break;
		}
	}

	cout << ans << "\n";
}
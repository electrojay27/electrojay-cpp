#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using ui64 = unsigned __int64;

struct node
{
	int id;
	int num;

	bool operator < (const node& t) const {
		return num < t.num;
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	vector<int> a[n + 1];
	for (int i = 0; i < 3 * n; i++) {
		int x;
		cin >> x;
		a[x].push_back(i + 1);
	}

	vector<node> ans(n);
	for (int i = 0; i < n; i++) {
		ans[i].id = i + 1;
		ans[i].num = a[i + 1][1];
	}

	sort(ans.begin(),ans.end());

	for (int i = 0; i < n; i++) {
		cout << ans[i].id << " \n"[i == n - 1];
	}
}
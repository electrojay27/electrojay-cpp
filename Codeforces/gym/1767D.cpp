#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	string s;
	cin >> s;

	int l = 0;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '1') {
			l ++;
		}
	}

	if (!l || l == s.size()) {
		cout << (1 << l) << "\n";
		return 0;
	}

	int r = (1 << n) - (1 << (s.size() - l)) + 1;
	l = 1 << l;
	for (int i = l; i <= r; i++) {
		cout << i << " \n"[i == r];
	}
}
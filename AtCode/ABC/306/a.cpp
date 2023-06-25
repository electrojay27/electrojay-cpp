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

	for (int i = 0; i < n; i++) {
		cout << s[i] << s[i];
	}

	cout << "\n";
}
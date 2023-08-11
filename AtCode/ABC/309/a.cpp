#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int a,b;
	cin >> a >> b;

	if ((a - 1) / 3 == (b - 1) / 3) {
		cout << "Yes\n";
	} else cout << "No\n";
}
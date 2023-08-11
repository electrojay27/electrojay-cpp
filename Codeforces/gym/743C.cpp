#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	if (n != 1)cout << n << " " << n + 1 << " " << n * (n + 1) << "\n";
	else cout << "-1\n";
}
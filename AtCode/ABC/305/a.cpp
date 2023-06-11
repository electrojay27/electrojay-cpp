#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	int v = n / 5;
	cout << (n - v * 5 > (v + 1) * 5 - n ? (v + 1) * 5 : v * 5) << "\n";
}
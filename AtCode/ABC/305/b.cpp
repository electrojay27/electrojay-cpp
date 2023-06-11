#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	char a,b;
	cin >> a >> b;

	int v[7] = {0,3,1,4,1,5,9};
	for (int i = 1; i < 7; i++) {
		v[i] += v[i - 1];
	}

	cout << fabs(v[b - 'A'] - v[a - 'A']) << '\n';
}
#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	vector<double> a(n);
	double avg = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		avg += a[i];
	}

	avg /= 1.0 * n;

	double D = 0;
	for (int i = 0; i < n; i++) {
		D += pow(a[i] - avg,2);
	}
	D /= 1.0 * n;

	for (int i = 0; i < n; i++) {
		cout << fixed << setprecision(10) << (a[i] - avg) / sqrt(D) << "\n";
	}
}
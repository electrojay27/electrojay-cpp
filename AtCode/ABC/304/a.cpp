#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	vector<string> na(n);
	vector<int> id(n);
	int mi = 0x3f3f3f3f;
	int idmin = 0;
	for (int i = 0; i < n; i++) {
		cin >> na[i] >> id[i];
		if (mi > id[i]) {
			mi = id[i];
			idmin = i;
		}
	}

	for (int i = idmin; i < n; i++) {
		cout << na[i] << "\n";
	}

	for (int i = 0; i < idmin; i++) {
		cout << na[i] << "\n";
	}
}
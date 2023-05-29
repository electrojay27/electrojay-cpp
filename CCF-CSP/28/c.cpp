#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	vector<vector<int>> q(8,vector<int>(8,0));
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			cin >> q[i][j];
		}
	}

	int n,t;
	cin >> n >> t;

	vector<vector<int>> m(8,vector<int>(8,0));
	for (int i = 0; i <= 14; i++) {
		int cnt = 0;
		if (i > 7)cnt = i % 7;
		if (i == 14) {
			cin >> m[7][7];
			break;
		}
		if (i % 2) {
			for (int j = cnt; j <= i - cnt; j++) {
				if (!n)break;
				cin >> m[j][i - j];
				n --;
			}
		} else {
			for (int j = cnt; j <= i - cnt; j++) {
				if (!n)break;
				cin >> m[i - j][j];
				n --;
			}
		}
		if (!n)break;
	}

	if (!t) {
		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 8; j++) {
				cout <<  m[i][j] << " \n"[j == 7];
			}
		}
		return 0;
	}

	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			m[i][j] *= q[i][j];
		}
	}

	if (t == 1) {
		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 8; j++) {
				cout <<  m[i][j] << " \n"[j == 7];
			}
		}
		return 0;
	}

	vector<vector<int>> ans(8,vector<int>(8,0));
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			double res = 0;
			for (int k = 0; k < 8; k++) {
				for (int l = 0; l < 8; l++) {
					double x = sqrt(0.5),y = sqrt(0.5);
					if (k)x = 1.0;
					if (l)y = 1.0;
					res += x * y * m[k][l] * cos((acos(-1) / 8) * (1.0 * i + 0.5) * k) * cos((acos(-1) / 8) * (1.0 * j + 0.5) * l);
				}
			}
			// cout << fixed << setprecision(2) << res / 4 << " \n"[j == 7];
			ans[i][j] = int(res / 4 + 128 + 0.5);
			if (ans[i][j] > 255)ans[i][j] = 255;
			if (ans[i][j] < 0)ans[i][j] = 0;
		}
	}

	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			cout << ans[i][j] << " \n"[j == 7];
		}
	}
	return 0;
}
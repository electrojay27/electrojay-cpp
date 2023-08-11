#include <bits/stdc++.h>
#define mod 1000000007
using namespace std;

using i64 = long long;

i64 power(i64 a, i64 b) {
    i64 res = 1;
    for (; b; b /= 2, a *= a, a %= mod) {
        if (b % 2) {
            res *= a;
            res %= mod;
        }
    }
    return res;
}

void solve() {
	int n;
	cin >> n;

	vector<vector<i64>> a(n,vector<i64>(2 * n,0));
	for (int i = 0;i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
			if (i == j) {
				a[i][j + n] = 1;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		int now = i;

		while (now < n && a[now][i] == 0) {
			now ++;
		}

		if (now == n) {
			cout << "No Solution\n";
			return;
		}

		for (int j = 0; j < 2 * n; j++) {
			swap(a[i][j],a[now][j]);
		}

		i64 ret = a[i][i];
		ret = power(ret,mod - 2);

		for (int j = 0; j < n; j++) {
			a[i][j] = a[i][j] * ret % mod;
			a[i][j + n] = a[i][j + n] * ret % mod;
		}

		for (int j = 0; j < n; j++) {
			if (j != i) {
				ret = a[j][i];
				for (int k = 0; k < n; k++) {
					a[j][k] = (a[j][k] - a[i][k] * ret % mod + mod) % mod;
					a[j][k + n] = (a[j][k + n] - a[i][k + n] * ret % mod + mod) % mod;
				}
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << a[i][j + n] << " \n"[j == n - 1];	
		}
	}
}
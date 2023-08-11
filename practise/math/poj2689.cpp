#include <iostream>
#include <cmath>
#include <map>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int l,r;
	while (cin >> l >> r) {
		vector<int> v(int(sqrt(r)),0);
		vector<int> primes(int(sqrt(r)));
		int m = 0;
		for (int i = 2;i <= sqrt(r); i++) {
			if (!v[i]) {
				v[i] = i;
				primes[m++] = i;
			}

			for (int j = 0; j < m; j++) {
				if (primes[j] > i || primes[j] * i > sqrt(r)) break;
				v[primes[j] * i] = primes[j];
			}
		}

		map<int,int> vis;
		vector<int> a;
		for (int i = l; i <= r; i++) {
			if (vis[l]) continue;
			a.push_back(i + l);
			cout << i << "\n";
			for (int j = i; j <= r / i; j++) vis[i * j] = 1;
		}

		if (a.size() < 2) {
			cout << "There are no adjacent primes.\n";
		} else {
			int mx = 0;
			int mi = 0x3f3f3f3f;
			int mxl = 0,mxr = 0;
			int mil = 0,mir = 0;
			for (int i = 0; i < a.size() - 1; i++) {
				if (mx < a[i + 1] - a[i]) {
					mx = a[i + 1] - a[i];
					mxl = i;
					mxr = i + 1;
				}
				if (mi > a[i + 1] - a[i]) {
					mi = a[i + 1] - a[i];
					mil = i;
					mir = i + 1;
				}
			}

			cout << a[mil] << "," << a[mir] << " are closest, " << a[mxl] << "," << a[mxr] << " are most distant.\n";
		}
		cout << endl;
	}
}
#include <iostream>
#include <cmath>
#define ll long long
using namespace std;

const int maxn = 1e5 + 10;
int a[maxn];
int n,k;

bool check(int x) {
	int tmp = x;
	for (int i = 0; i < n; i++) {
		if (a[i] - x > 0) {
			tmp -= (int)ceil((double)(a[i] - x) / (k - 1));
		}
		if (tmp < 0) {
			return false;
		}
	}

	return true;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);


	while (cin >> n) {
		for (int i = 0; i < n; i++) cin >> a[i];
		cin >> k;
		
		int l = 0,r = 1e9;
		int ans = 0;
		while (r > l) {
			int mid = (l + r) / 2;
			if (check(mid)) {
				ans = mid;
				r = mid;
			} else {
				l = mid + 1;
			}

			// cout << r << " " << l << endl;
		}

		cout << l << endl;
	}
}
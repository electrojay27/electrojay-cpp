#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve(){
	int l,r;
	cin >> l >> r;

	int cnt1 = 0,cnt2 = 0;
	int base = 1;
	while(l){
		cnt1 += (l % 10) * base;
		l /= 10;
		base = base * 10 + 1;
	}
	base = 1;
	while(r){
		cnt2 += (r % 10) * base;
		r /= 10;
		base = base * 10 + 1;
	}

	cout << cnt2 - cnt1 << "\n";
}

int main () {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}
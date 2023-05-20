#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve(){
	int n,k;
	cin >> n >> k;

	int cnt = n - k + 1;
	if(cnt & 1 && cnt > 0){
		cout << "YES\n";
		for(int i = 0; i < k - 1;i ++){
			cout << 1 << " ";
		}
		cout << cnt << "\n";
		return;
	}

	cnt = n - 2 * (k - 1);
	if(cnt % 2 == 0 && cnt > 0){
		cout << "YES\n";
		for(int i = 0; i < k - 1;i ++){
			cout << 2 << " ";
		}
		cout << cnt << "\n";
		return;
	}

	cout << "NO\n";
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
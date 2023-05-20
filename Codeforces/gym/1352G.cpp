#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve()
{
	int n;
	cin >> n;

	if(n <= 3){
		cout << -1 << "\n";
		return;
	}

	// if(n % 2){
	// 	for(int i = 0;i < (n + 1) / 2;i ++){
	// 		cout << n - 2 * i << " ";
	// 	}
	// 	cout << 4 << " " << 2 << " ";
	// 	for(int i = 0;i < n - (n + 1) / 2 - 2;i ++){
	// 		cout << 6 + 2 * i << " ";
	// 	}
	// }else{
	// 	for(int i = 0;i < (n + 1) / 2;i ++){
	// 		cout << n - 2 * i - 1 << " ";
	// 	}
	// 	cout << 4 << " " << 2 << " ";
	// 	for(int i = 0;i < n - (n + 1) / 2 - 2;i ++){
	// 		cout << 6 + 2 * i << " ";
	// 	}
	// }

	for(int i = n;i > 0;i --){
		if(i & 1)cout << i << " ";
	}

	cout << 4 << " " << 2 << " ";
	for(int i = 6;i <= n;i += 2){
		cout << i << " ";
	}

	cout << "\n";
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;
	while(t --){
		solve();
	}

	return 0;
}
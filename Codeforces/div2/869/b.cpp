#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve()
{
	int n;
	cin >> n;

	if(n == 1){
		cout << 1 << "\n";
		return;
	}

	if(n % 2){
		cout << -1 << "\n";
		return;
	}
	for(int i = n;i > 0;i -= 2){
		cout << i - 1 << " " << i << " ";
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
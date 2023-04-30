#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve()
{
	i64 x,y;
	cin >> x >> y;

	if(x == 1 || y == 1){
		cout << 1 << endl;
		cout << x << " " << y << endl;
	}else{
		cout << 2 << endl;
		cout << x - 1 << " " << 1 << endl;
		cout << x << " " << y << endl;
	}
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
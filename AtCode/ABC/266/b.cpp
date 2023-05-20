#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	i64 n;
	cin >> n;
	i64 x = n % 998244353 - 998244353;
	while(x < 0 || x > 998244352){
		x += 998244353;
	}
	cout << x << "\n";

	return 0;
}
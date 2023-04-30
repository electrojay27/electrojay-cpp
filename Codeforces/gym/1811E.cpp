#include <bits/stdc++.h>

using i64 = long long;

void solve()
{
	i64 n;
	std::cin >> n;

	i64 ans = 0;
	i64 ret = 1;
	while(n > 0){
		ans += ret * (n % 9);
		if(n % 9 >= 4)ans += ret;
		ret *= 10;
		n /= 9;
	}

	std::cout << ans << "\n";
}

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int t;
	std::cin >> t;
	while(t --){
		solve();
	}

	return 0;
}
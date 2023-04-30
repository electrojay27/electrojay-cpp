#include <bits/stdc++.h>

using i64 = long long;

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int n;
	std::cin >> n;
	if(n % 2 || n == 2){
		std::cout << "NO\n";
	}else std::cout << "YES\n";

	return 0;
}
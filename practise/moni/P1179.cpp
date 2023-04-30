#include <bits/stdc++.h>

using i64 = long long;

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int l,r;
	std::cin >> l >> r;

	int ans = 0;
	for(int i = l;i <= r;i ++){
		int cnt = i;
		while(cnt > 0){
			int to = cnt % 10;
			cnt /= 10;
			if(to == 2)ans ++;
		}
	}

	std::cout << ans << "\n";

	return 0;
}
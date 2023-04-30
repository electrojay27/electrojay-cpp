#include <bits/stdc++.h>

using i64 = long long;

void solve(int cnt)
{
	std::cout << "Case " << cnt << ": ";

	int n,x,ans;
	ans = 0;
	std::cin >> n;

	std::vector<int> num;
	std::map<int,int> A;

	for(int i = 1;i <= n;i ++){
		std::cin >> x;
		if(!A.count(x)){
			A[x] = 1;
			num.push_back(x);
		}else{
			A[x] ++;
			// if(A[x] > x + 1){
			// 	A[x] -= x + 1;
			// 	ans += x + 1;
			// }
		}
	}

	// for(auto it : num){
	// 	ans += it + 1;
	// }

	for(auto it : num){
		ans += ((A[x] - 1) / (it + 1) + 1) * (it + 1);
	}

	std::cout << ans << std::endl;
}

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int t;
	std::cin >> t;
	for(int i = 1;i <= t;i ++){
		solve(i);
	}
}
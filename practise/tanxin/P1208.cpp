#include <bits/stdc++.h>

using i64 = long long;

struct node
{
	int dan;
	int num;

	bool operator < (const node& t)const{
		return dan < t.dan;
	}
};

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int n,m;
	std::cin >> n >> m;

	std::vector<node> a(m);
	for(int i = 0;i < m;i ++){
		std::cin >> a[i].dan >> a[i].num;
	}

	std::sort(a.begin(),a.end());

	i64 ans = 0;
	int to = 0;
	while(n > 0){
		if(n - a[to].num >= 0){
			n -= a[to].num;
			ans += 1ll * a[to].dan * a[to].num;
			to ++;
		}else{
			ans += 1ll * n * a[to].dan;
			n = 0;
		}
	}

	std::cout << ans << "\n";

	return 0;
}
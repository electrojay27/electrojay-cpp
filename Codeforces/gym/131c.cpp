#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	i64 n,m,t;
	cin >> n >> m >> t;

	int r = n + m - t;
	i64 ans = 0;
	for(int i = 0;i <= r;i ++){
		if(n - i < 4 || m - (r - i) < 1)continue;

		i64 a = 1,b = 1;
		i64 c = 1,d = 1;
		for(int j = n;j > n - i;j --,c ++){
			a *= j;
			a /= c;
		}
		for(int j = m;j > m - (r - i);j --,d ++){
			b *= j;
			b /= d;
		}

		// for(int j = i;j > 0;j --){
		// 	a /= j;
		// }
		// for(int j = r - i;j > 0;j --){
		// 	b /= j;
		// }

		// cout << "i = " << i << " " << a << " " << b << "\n";

		ans += a * b;
	}
	cout << ans << "\n";
	return 0;
}
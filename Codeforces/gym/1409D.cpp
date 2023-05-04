#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve()
{	
	i64 n,s;
	cin >> n >> s;

	// cout << n * 10 << " " << s << "\n";

	i64 ans = 0;
	i64 cnt = n;
	vector<i64> a;
	while(cnt){
		a.push_back(cnt % 10);
		cnt /= 10;
	}

	i64 sum = 0;
	// cout << a.size() << "\n";
	for(int i = a.size() - 1;i >= 0;i --){
		if(a[i] + sum <= s){
			sum += a[i];
			ans = ans * 10 + a[i];
		}else{
			// sum += a[i];
			i ++;
			sum ++;
			while(sum > s){
				sum -= a[i];
				ans /= 10;
				i ++;
				// cout << sum << "\n";
			}
			ans ++;
			while(ans < n){
				ans *= 10;
				i --;
			}
			break;
		}
	}

	cout << ans - n << "\n";

	// cout << "\n";
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
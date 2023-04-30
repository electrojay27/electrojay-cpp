#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	vector<int> h(n);
	for(int i = 0;i < n;i ++)cin >> h[i];

	sort(h.begin(),h.end());

	i64 ans = 0;
	int flag = 0;
	int now = 0;
	int l = 0,r = n - 1;
	while(l <= r){
		if(!flag){
			ans += 1ll * (h[r] - now) * (h[r] - now);
			now = h[r];
			flag = 1;
			r --;
		}else{
			ans += 1ll * (now - h[l]) * (now - h[l]);
			now = h[l];
			l ++;
			flag = 0;
		}
	}

	cout << ans << "\n";
}
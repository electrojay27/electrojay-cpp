#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve()
{
	int n;
	cin >> n;

	vector<int> l(n + 1,0);
	for(int i = 0;i < n;i ++){
		int x;
		cin >> x;
		l[x] ++;
	}

	int ans = -1;
	for(int i = 0;i < n;i ++){
		if(i)l[i] += l[i - 1];
		if(l[i] == n - i){
			ans = i;
		}
	}

	cout << ans << "\n";
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;;
	while(t --){
		solve();
	}
	return 0;
}
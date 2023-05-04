#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve()
{
	int n;
	cin >> n;

	i64 x,sum;
	priority_queue<i64, vector<i64>, greater<i64> > q;
	for(int i = 1; i <= n; i ++){
		cin >> x;
		sum += x;
		q.push(x);

		while(sum < 0){
			sum -= q.top();
			q.pop();
		}
	}

	cout << q.size() << "\n";
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	// cin >> t;
	t = 1;
	while(t --){
		solve();
	}
	return 0;
}
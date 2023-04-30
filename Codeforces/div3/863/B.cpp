#include <bits/stdc++.h>
using namespace std;

int n;
int x,y,x1,y1;

void solve()
{
	cin >> n >> x >> y >> x1 >> y1;
	int cnt1 = min(min(x - 0,n + 1 - x),min(y - 0,n + 1 - y));
	int cnt2 = min(min(x1 - 0,n + 1 - x1),min(y1 - 0,n + 1 - y1));

	cout << int(fabs(cnt1 - cnt2)) << endl;

}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;
	while(t --)
	{
		solve();
	}
	return 0;
}
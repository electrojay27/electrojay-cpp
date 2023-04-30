#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e3 + 10;
int n;
string op;
// int a[maxn];

void solve()
{
	cin >> n;
	cin >> op;
	string ans;
	int cnt = 0;
	for(int i = 1;i < n;i ++)
	{
		if(op[i] <= op[cnt])cnt = i;
	}

	ans = op[cnt] + op.substr(0,cnt) + op.substr(cnt + 1);
	cout << ans << endl;
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
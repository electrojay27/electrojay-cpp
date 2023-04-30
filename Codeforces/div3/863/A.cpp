#include <bits/stdc++.h>
using namespace std;

int n;
string m;
string op;

void solve()
{
	cin >> n >> m;
	cin >> op;
	for(int i = 0;i < n;i ++)
	{
		if(op[i] < m[0] && !i){
			cout << m << op << endl;
			return;
		}
		if(op[i] < m[0] && i > 0){
			op = op.substr(0,i) + m + op.substr(i);
			break;
		}
		if(i == op.size() - 1)
		{
			cout << op << m << endl;
			return;
		}
	}

	cout << op << endl;
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
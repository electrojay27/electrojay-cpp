#include <bits/stdc++.h>
using namespace std;

int n;

void solve()
{
	string op;
	if(n == 1){
		cin >> op;
		cout << "Yes" << endl;
	}else{
		cin >> op;
		for(int i = 1;i < op.size();i ++)
		{
			if(op[i] == op[i - 1]){
				cout << "No" << endl;
				return;
			}
		}

		cout << "Yes" << endl;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	while(cin >> n)
	{
		solve();
	}
	return 0;
}
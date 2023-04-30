#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll n,k;

void solve()
{
	cin >> n >> k;

	if(n % 2 == 0 || (k % 2 == 1 && n >= k)){
		cout << "Yes" << endl;
	}else{
		cout << "No" << endl;
	}
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
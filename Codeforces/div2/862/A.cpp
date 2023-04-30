#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e3 + 10;
int n;
int a[maxn];

void solve()
{
	cin >> n;
	
	a[0] = 0;
	for(int i = 1;i <= n;i ++){
		cin >> a[i];
		a[i] ^= a[i - 1];
	}

	if(n % 2 == 0){
		if(a[n] != 0){
			cout << -1 << endl;
		}else{
			cout << 0 << endl;
		}
	}else{
		cout << a[n] << endl;
	}
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
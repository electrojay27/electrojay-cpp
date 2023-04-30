#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll n;
ll fib[50];
ll x[2];
ll a[2],b[2];

void init()
{
	fib[0] = fib[1] = 1;
	for(int i = 2;i <= 45;i ++)fib[i] = fib[i-1] + fib[i-2];
}

void solve()
{
	cin >> n;
	cin >> x[0] >> x[1];
	a[1] = fib[n + 1];
	a[0] = fib[n];
	b[0] = b[1] = 0;
	int flag = 1;
	for(int i = n;i > 0;i --)
	{
		if(a[flag] - x[flag] >= fib[i]){
			a[flag] -= fib[i];
			// cout << a[flag] << "a ";
		}else if(x[flag] - b[flag] - 1 >= fib[i]){
			b[flag] += fib[i];
			// cout << b[flag] << "b ";
		}else{
			cout << "NO" << endl;
			return;
		}
		flag ^= 1;
	}
	cout << "YES" << endl;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	init();
	cin >> t;
	while(t --)
	{
		solve();
	}
	return 0;
}
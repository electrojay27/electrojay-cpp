#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

i64 fib[81];
i64 num[81];
i64 n;

void init(){
	fib[0] = num[0] = 0;
	fib[1] = fib[2] = 1;
	num[1] = 1;
	num[2] = 2;
	for(int i = 3;i <= 81;i ++){
		fib[i] = fib[i - 2] + fib[i - 1];
		num[i] = num[i - 1] + fib[i];
		// cout << num[i] << endl;
	}
}

void solve()
{
	for(int i = 0;i <= 80;i ++){
		for(int j = i + 1;j <= 80;j ++){
			if(num[j] - num[i] == n){
				cout << "YES" << endl;
				return;
			}
		}
	}
	cout << "NO" << endl;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	init();

	while(cin >> n){
		solve();
	}
	return 0;
}
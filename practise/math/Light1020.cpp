#include <bits/stdc++.h>
using namespace std;

int m,n;

void solve(int x)
{
	string a,b;
	a = "Alice";
	b = "Bob";
	string op;
	cin >> n >> op;
	cout << "Case " << x << ": ";
	if(op == a){
		if(n % 3 == 1){
			cout << b << endl;
		}else{
			cout << a << endl;
		}
	}else{
		if(n % 3 == 0)
			cout << a << endl;
		else cout << b << endl;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;
	for(int i = 1;i <= t;i ++)
	{
		solve(i);
	}
	return 0;
}
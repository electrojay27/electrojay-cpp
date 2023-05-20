#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n,p,q,r,s;
	cin >> n >> p >> q >> r >> s;

	vector<int> a(n + 1);
	for(int i = 1;i <= n;i ++)cin >> a[i];

	for(int i = 1;i < p;i ++){
		cout << a[i] << " ";
	}

	for(int i = r;i <= s;i ++){
		cout << a[i] << " ";
	}

	for(int i = q + 1;i < r;i ++){
		cout << a[i] << " ";
	}

	for(int i = p;i <= q;i ++){
		cout << a[i] << " ";
	}

	for(int i = s + 1;i <= n;i ++){
		cout << a[i] << " ";
	}

	cout << "\n";
}
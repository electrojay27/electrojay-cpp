#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	vector<int> N(n);
	for(int i = 0;i < n;i ++)cin >> N[i];

	for(int i = 0;i < n;i ++){
		if(i)cout << N[i] - N[i - 1] << " \n"[i == n - 1];
		else cout << N[i] << " ";
	}

	return 0;
}
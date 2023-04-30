#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int m;
	cin >> m;
	int n;
	cin >> n;

	vector<int> p(n);
	for(int i = 0;i < n;i ++)
	{
		cin >> p[i];
	}

	sort(p.begin(),p.end());

	int ans = 0;
	int l = 0;
	for(int i = n - 1;i >= l;i --){
		if(p[i] + p[l] <= m)l ++;
		ans ++;
	}

	cout << ans << "\n";
}
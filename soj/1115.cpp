#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	i64 ans[50];
	ans[0] = ans[1] = 1;
	for(int i = 2;i < 50;i ++){
		ans[i] = ans[i - 2] + ans[i - 1];
	}

	int n;
	cin >> n;
	while(n --){
		int a,b;
		cin >> a >> b;
		cout << ans[b - a] << "\n";
	}
	return 0;
}
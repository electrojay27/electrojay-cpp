#include <bits/stdc++.h>
using namespace std;

int m,n;

void solve(int x)
{
	cin >> m >> n;
	if(n == 1 || m == 1)
	{
		cout << "Case " << x << ": " << m * n << endl;
	}else if(n == 2 || m == 2)
	{
		int ans = 0;
		int flag = 0;
		int sum = n * m;
		while(sum - 4 >= 0)
		{
			if(!flag)ans += 4;
			flag ^= 1;
			sum -= 4;
		}
		if(!flag)ans += sum;
		cout << "Case " << x << ": " << ans << endl;
	}else{
		cout << "Case " << x << ": " << (m * n + 1) / 2 << endl;
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
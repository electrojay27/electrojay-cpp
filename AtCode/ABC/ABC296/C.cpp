#include <bits/stdc++.h>
using namespace std;
	
const int maxn = 2e5 + 10;
int n,x;
int a[maxn];
bool cmp(int c,int d)
{
	return c > d;
}

void solve()
{
	memset(a,0,sizeof(a));
	for(int i = 1;i <= n;i ++)cin >> a[i];

	if(x == 0){
		cout << "Yes" << endl;
		return;
	}

	sort(a + 1,a + 1 + n);
	for(int i = 1;i <= n;i ++)
	{
		int cnt = x + a[i];
		int l = 1,r = n;
		while(l <= r)
		{
			int mid = (l + r) / 2;
			if(a[mid] == cnt){
				cout << "Yes" << endl;
				return;
			}
			if(a[mid] < cnt)l = mid + 1;
			else r = mid - 1;
		}
	}

	cout << "No" << endl;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	while(cin >> n >> x)
	{
		solve();
	}
	return 0;
}
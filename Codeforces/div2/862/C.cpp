#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define eps 1e-8

const int maxn = 1e5 + 10;
ll n,m;
ll a[3][maxn];
ll k[maxn];

void solve()
{
	cin >> n >> m;
	for(int i = 1;i <= n;i ++)cin >> k[i];
	for(int i = 1;i <= m;i ++)cin >> a[0][i] >> a[1][i] >> a[2][i];

	sort(k + 1,k + 1 + n);

	for(int i = 1;i <= m;i ++)
	{
		if(a[0][i] * a[2][i] <= 0){
			cout << "NO" << endl;
		}else{
			double cnt1 = 2 * sqrt(a[0][i] * a[2][i]) + a[1][i];
			double cnt2 = a[1][i] - 2 * sqrt(a[0][i] * a[2][i]);

			ll flag = 1;
			ll l = 1,r = n;
			while(l <= r){
				ll mid = (l + r) / 2;
				if(k[mid] * 1.0 > cnt2 && k[mid] < cnt1){
					flag = 0;
					cout << "YES" << endl << k[mid] << endl;
					break;
				}
				if(k[mid] * 1.0 <= cnt2)l = mid + 1;
				else r = mid - 1;
			}
			if(flag)cout << "NO" << endl;

		}
	}
	cout << endl;
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
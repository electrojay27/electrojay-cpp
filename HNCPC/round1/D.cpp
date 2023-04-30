#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007

using i64 = long long;

i64 k[1005];
i64 k_[1005];

void init()
{
	k[0] = 0;
	k_[0] = 0;
	for(int i = 1;i <= 1000;i ++){
		k[i] = (k[i - 1] + i * i % mod) % mod;
		k_[i] = (k_[i - 1] + i) % mod;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	i64 n;
	init();
	while(cin >> n){
		i64 a1,a2,b1,b2;
		cin >> a1 >> a2 >> b1 >> b2;
		i64 ans = 0;
		for(int i = 0;i < n;i ++){
			for(int j = 0;j < n;j ++){
				ans = (ans +  (k[n - 1] * (a2 * b1) % mod + n * i * j  * a1 * b2 % mod + k_[n - 1] * i * a1 * b1 % mod + k_[n - 1] * j * a2 * b2 % mod ) % mod ) % mod;
				// cout << (k[n - 1] * (a2 * b1) % mod + i * j  * a1 * b2 % mod + k_[n - 1] * i * a1 * b1 % mod + k_[n - 1] * j * a2 * b2 % mod ) % mod << endl;
				// cout << k[n - 1] * (a2 * b1) % mod << " " << i * j  * a1 * b2 % mod << " " << k_[n - 1] * i * a1 * b1 % mod << " " << k_[n - 1] * j * a2 * b2 % mod << endl;
			}
		}

		cout << ans << endl;
	}
}
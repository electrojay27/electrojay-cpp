#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	i64 n,m;
	int ans;

	while(cin >> n >> m && n && m){
		ans = 0;

		if(n < m)swap(n,m);

		if(n % m == 0){
			ans = 0;
		}else if(n > 2 * m){
			ans = 0;
		}else{
			int flag = 1;//判断必胜态出现了没
			while(flag){
				n -= m;
				if(n < m)swap(n,m);
				if(n % m == 0){
					flag ^= 1;
				}else if(n > 2 * m){
					flag ^= 1;
				}
				ans ^= 1;
			}
		}

		cout << ( !ans ? "Stan wins" : "Ollie wins" ) << endl;
	}
	return 0;
}
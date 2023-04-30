#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	ll a,b;

	cin >> a >> b;

	ll ans = 0;

	while(a && b){
		ll v = gcd(a,b);

		if(a == b){
			ans ++;
			break;
		}else if(a - b == 1 || b - a == 1){
			ans += min(a,b);
			break;
		}else{
			ans ++;
			a -= v;
			b -= v;
		}
		
	}

	cout << ans << endl;
}
#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll t,n;
ll cnt;
ll flag;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	while(cin >> t){
		while(t --){
			cnt = 1;
			flag = -1;
			cin >> n;
			ll l = 0,r = 1e9;
			while(l <= r){
				ll mid = (l + r) / 2;
				if((mid + 1) * (mid + 1) < n)l = mid + 1;
				else if(mid * mid > n)r = mid - 1;
				else{
					if(mid * mid == n)flag = mid - 1;
					else flag = mid;
					break;
				}
			}
			cout << flag << endl;
		}
	}
	return 0;
}
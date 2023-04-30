#include <bits/stdc++.h>
using namespace std;

int sum,mn,mx,x;
int n;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	while(cin >> n){
		sum = 0;
		mn = 100;
		mx = 0;
		for(int i = 1;i <= n;i ++){
			cin >> x;
			sum += x;
			mx = max(mx,x);
			mn = min(mn,x);
		}

		cout << mx << endl << mn << endl << fixed << setprecision(2) << 1.0 * sum / n << endl;
	}
	return 0;
}
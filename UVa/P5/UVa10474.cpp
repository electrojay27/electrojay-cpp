#include <iostream>
#include <algorithm>
using namespace std;

const int maxn = 1e4 + 10;
int a[maxn],n,q,x,cnt;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cnt = 1;
	while(cin >> n >> q && n && q){
		cout << "CASE# " << cnt ++ << ":" << endl;

		for(int i = 1;i <= n;i ++)cin >> a[i];

		sort(a + 1,a + n + 1);

		for(int i = 1;i <= q;i ++){
			cin >> x;
			int ans = lower_bound(a + 1,a + n + 1,x) - a;
			if(a[ans] == x)cout << x << " found at " << ans << endl;
			else cout << x << " not found" << endl;
		}
	}
	return 0;
}
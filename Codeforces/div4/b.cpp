#include <bits/stdc++.h>
using namespace std;

int t,n,x;
// int a[110],b[110];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	while(cin >> t){
		while(t --){
			cin >> n;
			int cnt1 = 0,cnt2 = 0;
			for(int i = 1;i <= n;i ++){
				cin >> x;
				if(x % 2)cnt1 += x;
				else cnt2 += x;
			}
			if(cnt1 >= cnt2)cout << "NO" << endl;
			else cout << "YES" << endl;
		}
	}
	return 0;
}
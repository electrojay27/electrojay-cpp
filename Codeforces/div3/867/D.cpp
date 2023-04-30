#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve()
{
	int n;
	cin >> n;

	if(n != 1 && n % 2){
		cout << "-1\n";
		return;
	}

	vector<i64> a(n);
	i64 l = 0,r = n - 1;
	for(int i = 0;i < n;i ++){
		if(i % 2 == 0){
			if(!i)a[i] = n,l ++;
			else{
				int cmp = a[i - 1] % n;
				cmp = n - cmp + l;
				a[i] = a[i - 1] + cmp;
				l ++;
			}
		}else{
			int cmp = a[i - 1] % n;
			cmp = r - cmp;
			a[i] = a[i - 1] + cmp;
			r --;
		}
	}

	for(int i = 0;i < n;i ++){
		if(!i)cout << a[i] << " ";
		else cout << a[i] - a[i - 1] << " ";
	}

	cout << "\n";
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
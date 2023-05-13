#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve(){
	int n;
	cin >> n;

	vector<int> a(n);
	for(int i = 0;i < n;i ++)cin >> a[i];

	if(n == 1){
		cout << 1 << "\n";
		return;
	}

	vector<int> b;
	for(int i = 0;i < n;i ++){
		if(!i)b.push_back(a[i]);
		else if(a[i] != a[i - 1])b.push_back(a[i]);
	}

	if(b.size() == 1 || b.size() == 2){
		cout << b.size() << "\n";
		return;
	}

	n = b.size();
	int ans = 1,cnt;
	for(int i = 0;i < n;i ++){
		if(!i){
			if(b[i] < b[i + 1])cnt = 1;
			else cnt = -1;
			ans ++;
		}else{
			if(cnt == 1 && b[i - 1] > b[i] || cnt == -1 && b[i - 1] < b[i]){
				cnt *= -1;
				ans ++;
			}
		}
	}

	cout << ans << "\n";
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
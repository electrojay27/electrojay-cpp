#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve()
{
	int n;
	cin >> n;

	// vector<node> a(n);
	int v;
	string w;
	int ans = 0x3f3f3f3f;
	int a = 0x3f3f3f3f;
	int b = 0x3f3f3f3f;
	for(int i = 0;i < n;i ++){
		cin >> v >> w;
		if(w == "01"){
			a = min(a,v);
		}else if(w == "10"){
			b = min(b,v);
		}else if(w == "11"){
			ans = min(ans,v);
		}
	}

	if(a != 0x3f3f3f3f && b != 0x3f3f3f3f){
		ans = min(ans,a + b);
	}

	if(ans == 0x3f3f3f3f){
		cout << -1 << "\n";
	}else cout << ans << "\n";
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
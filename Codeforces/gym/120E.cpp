#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve(){
	int n;
	cin >> n;

	if(n % 2){
		cout << 0 << "\n";
	}else{
		cout << 1 << "\n";
	}
}

int main()
{
	freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

	int t;
	cin >> t;
	while(t --){
		solve();
	}

	return 0;
}
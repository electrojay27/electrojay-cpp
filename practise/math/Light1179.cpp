#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

i64 n,k;

i64 judge(i64 x){
	if(x == 1)return 1;
	else return ((judge(x - 1) + k) % x + 1);
}

void solve(int i)
{
	cin >> n >> k;
	cout << "Case " << i << ": ";

	k --;

	cout << judge(n) << "\n";
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t;
	cin >> t;
	for(int i = 1;i <= t;i ++){
		solve(i);
	}

	return 0;
}
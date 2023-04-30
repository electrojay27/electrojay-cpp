#include <bits/stdc++.h>
using namespace std;

int a,b;
bool vis[8];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	while(cin >> a >> b){
		int ans = 0;
		ans = (a | b);
		cout << ans << endl;
	}
	return 0;
}
#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n,a,b;
	cin >> n >> a >> b;

	vector<int> c(n);
	for(int i = 0;i < n;i ++)cin >> c[i];

	for(int i = 0;i < n;i ++){
		if(a + b == c[i]){
			cout << i + 1 << "\n";
			return 0;
		}
	}	
}
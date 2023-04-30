#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n,x;
	
	cin >> n;

	int l = 1,r = n;
	
	while(l < r - 1){
		int mid = (l + r) / 2;

		cout << "? " << mid << endl;
		cin >> x;

		if(x)r = mid;
		else l = mid;
	}

	cout << "! " << l << endl;

	return 0;
}
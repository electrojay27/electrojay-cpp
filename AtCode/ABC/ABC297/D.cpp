#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	i64 A,B;

	cin >> A >> B;

	i64 ans = 0;
	while(A != B){
		if(A > B){
			ans += (A - 1) / B;
			A -= (A - 1) / B * B;
		}else{
			ans += (B - 1) / A;
			B -= (B - 1) / A * A;
		}
	}

	cout << ans << endl;

	return 0;
}
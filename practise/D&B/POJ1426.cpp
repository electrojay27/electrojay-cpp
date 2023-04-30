#include <iostream>
using namespace std;

using i64 = long long;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	while(cin >> n){
		if(!n)break;
		i64 ans = 1;
		while(ans % n){
			if(ans & 1){
				ans *= 10;
			}else ans ++;
		}

		cout << ans << "\n";
	}
	return 0;
}
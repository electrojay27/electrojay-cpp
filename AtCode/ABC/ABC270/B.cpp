#include <bits/stdc++.h>
using namespace std;

int x,y,z;

void solve()
{
	if(x > 0){
		if(y > 0 && y < x){
			if(z > y){
				cout << -1 << endl;
			}else if(z < 0){
				cout << -z * 2 + x << endl;
			}else{
				cout << x << endl;
			}
		}else{
			cout << x << endl;
		}
	}else{
		if(y < 0 && y > x){
			if(z < y)cout << -1 << endl;
			else if(z > 0)cout << 2 * z - x;
			else cout << -x << endl;
		}else{
			cout << -x << endl;
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	while(cin >> x >> y >> z){
		solve();
	}
	return 0;
}
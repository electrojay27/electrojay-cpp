#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int a,x,y;
	cin >> a >> x >> y;

	int ans = -1;
	int to = 1;
	while(to * a < y + a){
		if(to == 1){
			if(2 * x < a && 2 * x > - a && y > 0 && y < a){
				ans = to;
				break;
			}
		}else{
			if(to % 2){
				if(x < 0 && x > -a && y < to * a && y > (to - 1) * a){
					ans = 3 * (to - 1) / 2;
					break;
				}else if(x < a && x > 0 && y < to * a && y > (to - 1) * a){
					ans = 3 * (to - 1) / 2 + 1;
					break;
				}
			}else{
				if(2 * x < a && 2 * x > - a && y > (to - 1) * a && y < to * a){
					ans = 3 * to / 2 - 1;
					break;
				}
			}
		}

		to ++;
	}


	cout << ans << "\n";
}
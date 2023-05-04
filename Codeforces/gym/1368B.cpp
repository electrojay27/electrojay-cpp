#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	i64 k;
	cin >> k;

	if(k == 1){
		cout << "codeforces\n";
		return 0;
	}

	i64 cnt = 1;
	int to = 0;
	i64 base = 2;
	bool flag = true;
	while(flag){
		for(int i = 1;i <= 10;i ++){
			cnt /= (base - 1);
			cnt *= base;
			if(cnt >= k){
				// cout << cnt << "\n";
				// cout << i << "\n";
				to = i;
				flag = 0;
				break;
			}
		}
		if(flag)base ++;
	}

	string ans = "codeforces";
	for(int i = 0;i < 10;i ++){
		if(i < to){
			i64 cmp = base;
			while(cmp --){
				cout << ans[i];
			}
		}else{
			i64 cmp = base - 1;
			while(cmp --){
				cout << ans[i];
			}
		}
	}
	cout << "\n";
}
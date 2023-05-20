#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	i64 l,r;
	cin >> l >> r;

	i64 ans = 0;

	vector<i64> sum[11];
	sum[0].push_back(4);
	sum[0].push_back(7);
	i64 cmp = 1;
	for(int i = 1;i < 11;i ++){
		cmp *= 10;
		for(int j = 0;j <= 1;j ++){
			for(int k = 0;k < sum[i - 1].size();k ++){
				if(!j)sum[i].push_back(4ll * cmp + sum[i - 1][k]);
				else sum[i].push_back(7ll * cmp + sum[i - 1][k]);

				// cout << sum[i][sum[i].size() - 1] << " ";
			}
		}
	}

	int flag = 0;
	for(int i = 0;i < 11;i ++){
		for(int k = 0;k < sum[i].size();k ++){
			if(r <= sum[i][k]){
				if(!i && !k){
					ans += (r - l + 1) * 4;
					flag = 1;
					break;
				}

				if(!k){
					ans += (r - max(sum[i - 1][sum[i - 1].size() - 1],l) + 1) * sum[i][k];
				}else{
					ans += (r - max(sum[i][k - 1],l) + 1) * sum[i][k];
				}
				flag = 1;
				break;
			}

			if(sum[i][k] >= l){
				ans += (sum[i][k] - l + 1) * sum[i][k];
				l = sum[i][k] + 1;
				// cout << l << "\n";
			}
			// cout << ans << "\n";
		}
		if(flag)break;
	}

	cout << ans << "\n";
}
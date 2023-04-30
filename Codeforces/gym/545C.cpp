#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	vector<int> x(n);
	vector<int> h(n);
	for(int i = 0;i < n;i ++){
		cin >> x[i] >> h[i];
	}

	int ans = 0;
	int flag = 0;
	vector<int> vis(n,0);
	for(int i = 0;i < n;i ++){
		if(!i || i == n - 1){
			ans ++;
			vis[i] = 1;
		}else{
			if(!vis[i - 1])h[i - 1] = 0; 
			if(!flag){
				if(x[i] - h[i] > x[i - 1]){
					ans ++;
					vis[i] = 1;
				}else if(x[i] + h[i] < x[i + 1]){
					ans ++;
					flag = 1;
					vis[i] = 1;
				}
			}else{
				if(x[i] - h[i] > x[i - 1] + h[i - 1]){
					ans ++;
					flag = 0;
					vis[i] = 1;
				}else if(x[i] + h[i] < x[i + 1]){
					ans ++;
					vis[i] = 1;
				}
			}
		}
	}

	cout << ans << "\n";
}
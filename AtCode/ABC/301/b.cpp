#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	vector<int> a(n);
	for(int i = 0;i < n;i ++)cin >> a[i];

	for(int i = 0;i < n;i ++){
		if(i == n - 1)cout << a[i] << "\n";
		else{
			if(fabs(a[i] - a[i + 1]) == 1)cout << a[i] << " ";
			else{
				if(a[i] > a[i + 1]){
					for(int j = a[i];j > a[i + 1];j --){
						cout << j << " ";
					}
				}else{
					for(int j = a[i];j < a[i + 1];j ++){
						cout << j << " ";
					}
				}
			}
		}
	}

	return 0;
}
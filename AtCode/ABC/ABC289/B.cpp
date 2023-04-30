#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n,m;
	cin >> n >> m;

	vector<int> a(m + 1);
	vector<int> p(n);

	for(int i = 0; i < m; i++){
		cin >> a[i];
	}

	int to = 0;
	for(int i = 0;i < n;i ++){
		// cout << i << endl;
		// cout << to << endl;
		if(i + 1 != a[to])p[i] = i + 1;
		else{
			while(to != m){
				if(a[to] + 1 == a[to + 1]){
					to ++;
				}else{
					break;
				}
			}

			int cnt = i;
			for(int j = a[to];j >= i;j --){
				p[cnt] = j + 1;
				cnt ++;
			}
			i = a[to];
			to ++;
		}
	}

	for(auto it : p)cout << it << " ";
	cout << endl;
	return 0;
}
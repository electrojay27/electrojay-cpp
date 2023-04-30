#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

struct node
{
	int t,c;

	bool operator <(const node& that)const{
		return t > that.t;
	}
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n,m,k;
	cin >> n >> m >> k;
	
	vector<node> a(n);
	vector<int> d(100010,0);
	for(int i = 0;i < n;i ++){
		cin >> a[i].t >> a[i].c;
		d[a[i].t] ++;
	}

	sort(a.begin(),a.end());

	// for(auto it : a){
	// 	cout << it.t << "\n";
	// }

	vector<int> c(n);
	for(int i = 0;i < n;i ++){
		if(i)c[i] = a[i].c + c[i - 1];
		else c[i] = a[i].c;
	}
	
	for(int i = 100000;i > k;i --){
		if(d[i]){
			if(m - c[d[i] - 1] >= 0){
				m -= c[d[i] - 1];
				d[i - 1] += d[i];
			}else{
				cout << i << "\n";
				return 0;
			}
		}
	}

	cout << k << "\n";
	return 0;
}
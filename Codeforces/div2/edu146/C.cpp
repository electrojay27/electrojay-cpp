#include <bits/stdc++.h>
using namespace std;
#define ll long long

int n,s1,s2;

void solve()
{
	cin >> n >> s1 >> s2;

	vector<int> r(n);

	for(int i = 0;i < n;i ++)cin >> r[i];

	vector<int> p(n);
	for(int i = 0;i < n;i ++)p[i] = i;

	sort(p.begin(),p.end(),[&](int i,int j){
		return r[i] > r[j];
	});

	vector<int> a,b;
	for(auto it : p){
		if((a.size() + 1 ) * s1 < (b.size() + 1) * s2)a.push_back(it);
		else b.push_back(it); 
	}

	cout << a.size() << " ";
	for(auto it : a)cout << it + 1 << " ";
	cout << endl;
	cout << b.size() << " ";
	for(auto it : b)cout << it + 1 << " ";
	cout << endl;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;
	while(t --)
	{
		solve();
	}
	return 0;
}
#include <bits/stdc++.h>
using namespace std;

struct node
{
	int id;
	int r;
	int c;

	bool operator <(const node & t)const{
		if(c != t.c)return c < t.c;
		if(r != t.r)return r < t.r;
		return id < t.id;
	}
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n,t;
	cin >> n >> t;

	vector<node> a(n);
	int first = 0;

	for(int i = 0;i < n;i ++){
		cin >> a[i].c;
		a[i].id = i + 1;
		if(a[i].c == t)first = 1;
	}

	if(!first)t = a[0].c;

	for(int i = 0;i < n;i ++){
		cin >> a[i].r;
	}

	sort(a.begin(),a.end());

	int ans = 0;

	for(int i = 0;i < n;i ++){
		// cout << a[i].c << " " << a[i].r << " " << a[i].id << "\n";
		if(a[i].c == t){
			while(a[i].c == t){
				ans = a[i].id;
				i ++;
			}
			break;
		}
	}

	cout << ans << "\n";

	return 0;
}
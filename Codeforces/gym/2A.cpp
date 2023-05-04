#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

struct node
{
	string name;
	int x;
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	string name;
	map<string,int> gra;
	int x,mx;
	string ans;
	vector<node> a;
	for(int i = 0;i < n;i ++){
		cin >> name >> x;
		a.push_back({name,x});
		if(!gra.count(name)){
			gra[name] = x;
		}else{
			gra[name] += x;
		}
	}

	mx = 0;
	for(auto it = gra.begin();it != gra.end(); it ++){
		if(it->second > mx){
			mx = it->second;
		}
	}

	set<string> st;
	for(auto it = gra.begin();it != gra.end(); it ++){
		if(it->second == mx){
			st.insert(it->first);
		}
	}

	gra.clear();
	for(int i = 0;i < n;i ++){
		if(st.count(a[i].name) && !gra.count(a[i].name)){
			gra[a[i].name] = a[i].x;
		}else if(st.count(a[i].name)){
			gra[a[i].name] += a[i].x;
		}
		if(st.count(a[i].name) && gra[a[i].name] >= mx){
			ans = a[i].name;
			break;
		}
	}

	cout << ans << "\n";
}
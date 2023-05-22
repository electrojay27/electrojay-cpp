#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
map<set<int>,int> ID;
vector<set<int>> Setcache;

int IDfind (set<int> x) {
	if (ID.count(x)) {
		return ID[x];
	} 
	Setcache.push_back(x);
	return ID[x] = Setcache.size() - 1;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		stack<int> s;
		while (n --) {
			string op;
			cin >> op;

			if (op == "PUSH") {
				s.push(IDfind(set<int>()));
			} else if (op == "DUP") {
				s.push(s.top());
			} else {
				set<int> a = Setcache[s.top()]; s.pop();
				set<int> b = Setcache[s.top()]; s.pop();
				set<int> x;
				if (op == "UNION") {
					set_union (a.begin(),a.end(),b.begin(),b.end(),inserter(x,x.begin()));
				} else if (op == "INTERSECT") {
					set_intersection (a.begin(),a.end(),b.begin(),b.end(),inserter(x,x.begin()));
				} else {
					x = b;
					x.insert(IDfind(a));
				}

				s.push(IDfind(x));
			}

			cout << Setcache[s.top()].size() << "\n";
		}

		cout << "***\n";
	}
}
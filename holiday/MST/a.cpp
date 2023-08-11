#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

struct edge{
	int u,v,val;

	bool operator < (const edge& t) const {
		return val < t.val;
	}
};

struct Edge{
	int u,v,id,val;

	bool operator < (const Edge& t) const {
		return val < t.val;
	}
};

struct MST
{
	vector<edge> e;
	vector<int> f;
	vector<Edge> E;
	int size_n,size_m;

	MST() {}
	MST(int n) {
		init(n,0);
	}
	MST(int n, int m) {
		init(n,m);
	}
	int Find(int x) { 
		return (f[x] == x ? f[x] : f[x] = Find(f[x]));
	}
	bool same(int x, int y) { 
		return Find(x) == Find(y);
	}
	bool merge(int x, int y) {
		x = Find(x);
        y = Find(y);
        if (x == y) return false;	
        f[y] = x;
        return true;
	}
	void add(edge x) {
		e.push_back(x);
		size_m = e.size();
	}
	void Add(Edge x) {
		E.push_back(x);
	}
	void init(int n, int m) {
		f.resize(n);
        iota(f.begin(), f.end(), 0);
		e.resize(m);
		size_n = n;
		size_m = m;
		for(int i = 0; i < m; i++) {
			cin >> e[i].u >> e[i].v >> e[i].val;
			e[i].u --;
			e[i].v --;
		}
	}

	void Kruskal() {
		sort(e.begin(),e.end());
		sort(E.begin(),E.end());
		vector<int> ans(E.size(),0);
		int to = 0;
		for (int i = 0; i < E.size(); i++) {
			while (to < size_m && E[i].val > e[to].val) {
				merge(e[to].u,e[to].v);
				to ++;
			}
			ans[E[i].id] = (!same(E[i].u,E[i].v) ? 1 : 0);
		}

		for (int i = 0; i < E.size(); i++) {
			cout << (ans[i] ? "Yes" : "No") << "\n";
		}
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n,m,q;
	cin >> n >> m >> q;
	MST mst(n,m);
	for (int i = 0; i < q; i++) {
		int u,v,val;
		cin >> u >> v >> val;
		u--,v--;
		mst.Add({u,v,i,val});
	}

	mst.Kruskal();
}
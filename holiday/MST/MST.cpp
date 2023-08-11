#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

struct edge{
	int u,v,val;

	bool operator < (const edge& t) const {
		return val < t.val;
	}
};

struct MST
{
	vector<edge> e;
	vector<int> f;
	int size_n,size_m;

	MST() {}
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
	void init(int n, int m) {
		f.resize(n);
        std::iota(f.begin(), f.end(), 0);
		e.resize(m);
		size_n = n;
		size_m = m;
		for(int i = 0; i < m; i++) {
			cin >> e[i].u >> e[i].v >> e[i].val;
			e[i].u --;
			e[i].v --;
		}
	}

	int Kruskal() {
		sort(e.begin(),e.end());
		int res = 0,num = 0;
		for (int i = 0; i < size_m; i++) {
			if (!same(e[i].u,e[i].v)) {
				merge(e[i].u,e[i].v);
				res += e[i].val;
				num ++;
			}
			if (num == size_n - 1) break;
		}
		if (num != size_n - 1) return 0;
		return res;
	}
};
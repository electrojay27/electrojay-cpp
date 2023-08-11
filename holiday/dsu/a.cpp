#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

struct DSU
{
	vector<int> f,siz;
	DSU() {}
    DSU(int n) {
        init(n);
    }
    void init(int n) {
        f.resize(n);
        std::iota(f.begin(), f.end(), 0);
        siz.assign(n, 1);
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
        siz[x] += siz[y];
        f[y] = x;
        return true;
	}
	int size(int x) {
		return siz[Find(x)];
	}
};

struct node{
	int u,v,val;

	bool operator < (const node& t) const {
		return val < t.val;
	}
};

struct MST
{
	vector<node> e;
	int size_n,size_m;
	DSU dsu;

	MST (int n,int m) {
		dsu.init(n);
		e.resize(m);
		size_n = n;
		size_m = m;
		for(int i = 0; i < m; i++) {
			cin >> e[i].u >> e[i].v >> e[i].val;
			e[i].u --;
			e[i].v --;
		}
		sort(e.begin(),e.end());
	}

	int solve() {
		int res = 0;
		for (int i = 0; i < size_m; ) {
			int j;
			int num = 0;
			for (j = i; j < size_m && e[i].val == e[j].val; j++) {
				if (!dsu.same(e[j].u,e[j].v)) {
					num ++;
				}
			}
			for (int k = i; k < j; k++) {
				if (!dsu.same(e[k].u,e[k].v)) {
					dsu.merge(e[k].u,e[k].v);
					num --;
				}
			}
			i = j;
			res += num;
		}

		return res;
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n,m;
	cin >> n >> m;
	MST mst(n,m);
	cout << mst.solve() << "\n";	
}
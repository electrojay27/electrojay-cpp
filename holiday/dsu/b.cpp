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
		dsu.init(m);
		e.resize(n);
		size_n = n;
		size_m = m;
		for(int i = 0; i < n; i++) {
			cin >> e[i].u >> e[i].v >> e[i].val;
			e[i].u --;
			e[i].v --;
		}
		sort(e.begin(),e.end());

		// for (auto it : e) {
		// 	cout << it.val << "\n";
		// }
	}

	int solve() {
		int res = 0,num = 0;
		for (int i = 0; i < size_n; i++) {
			// cout << e[i].u << " " << e[i].v << endl;
			if (!dsu.same(e[i].u,e[i].v)) {
				dsu.merge(e[i].u,e[i].v);
				res += e[i].val;
				// cout << e[i].val << endl;
				num ++;
			}

			if (num == size_m - 1) break;
		}

		if (num == size_m - 1) return res;
		else return 0;
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n,m;
	while(cin >> n >> m) {
		if (!n) break;
		MST mst(n,m);
		if (m == 1) {
			cout << 0 << "\n";
			continue;
		}
		int ans = mst.solve();
		if (ans) cout << ans << "\n";
		else cout << "?\n";
	}
}
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

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n,k;
	cin >> n >> k;
	DSU dsu(n);
	for (int i = 0; i < n; i++) {
		
	}
}
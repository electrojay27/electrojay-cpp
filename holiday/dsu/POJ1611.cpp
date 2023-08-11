#include <iostream>
#include <vector>
using namespace std;

// using i64 = long long;

struct DSU
{
	vector<int> f,siz;
	DSU() {}
    DSU(int n) {
        init(n);
    }
    void init(int n) {
        f.resize(n);
        // std::iota(f.begin(), f.end(), 0);
        for (int i = 0; i < n; i++) {
        	f[i] = i;
        }
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
	cin.tie(0);

	int n,m;
	while (cin >> n >> m) {
		if (!n && !m) break;
		DSU dsu(n);

		vector<int> a[m];
		for (int i = 0; i < m; i++) {
			int k;
			cin >> k;
			a[i].resize(k);
			for (int j = 0; j < k; j++) {
				cin >> a[i][j];
				if (j) {
					dsu.merge(a[i][j],a[i][j - 1]);
				}
			}
		}

		cout << dsu.size(0) << "\n";
	}
}


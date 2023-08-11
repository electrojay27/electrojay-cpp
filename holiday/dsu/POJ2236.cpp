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

	int n,d;
	cin >> n >> d;
	vector<int> x(n),y(n),vis(n,0);
	for (int i = 0; i < n; i++) {
		cin >> x[i] >> y[i];
	}

	int num = 0;

	DSU dsu(n);
	char op;
	while (cin >> op) {
		if (op == 'O') {
			int s;
			cin >> s;
			s--;
			vis[s] = 1;
			if (num != n - 1) {
				for (int i = 0; i < n; i++) {
					if (i != s) {
						if (vis[i] && !dsu.same(s,i) && (x[s] - x[i]) * (x[s] - x[i]) + (y[s] - y[i]) * (y[s] - y[i]) <= d * d) {
							dsu.merge(s,i);
							num ++;
						}
					}
				}
			}
		} else {
			int a,b;
			cin >> a >> b;
			a--,b--;
			if (vis[a] && vis[b]) {
				if (dsu.same(a,b) || (x[a] - x[b]) * (x[a] - x[b]) + (y[a] - y[b]) * (y[a] - y[b]) <= d * d) {
					dsu.merge(a,b);
					cout << "SUCCESS\n";
				} else {
					cout << "FAIL\n";
				}
			} else {
				cout << "FAIL\n";
			}
		}
		// cout << endl;
	}
}


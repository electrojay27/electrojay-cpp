#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int ha,wa;
	cin >> ha >> wa;

	vector<vector<char>> a(ha,vector<char>(wa));
	for (int i = 0; i < ha; i++) {
		for (int j = 0; j < wa; j++) {
			cin >> a[i][j];
		}
	}

	int hb,wb;
	cin >> hb >> wb;

	vector<vector<char>> b(hb,vector<char>(wb));
	for (int i = 0; i < hb; i++) {
		for (int j = 0; j < wb; j++) {
			cin >> b[i][j];
		}
	}

	int hx,wx;
	cin >> hx >> wx;

	vector<vector<char>> x(hx,vector<char>(wx));
	for (int i = 0; i < hx; i++) {
		for (int j = 0; j < wx; j++) {
			cin >> x[i][j];
		}
	}

	bool fa = false,fb = false;

	for (int i = 0; i < ha; i++) {
		for (int j = 0; j < wa;j ++) {
			
		}
	}
}
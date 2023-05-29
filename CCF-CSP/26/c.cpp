#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

unordered_map<string,set<string>> opp[3];
unordered_map<string,int> judge[2];
unordered_map<string,set<string>> u;
unordered_map<string,set<string>> g;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n,m,q;
	cin >> n >> m >> q;

	for (int i = 0; i < n; i++) {
		string na;
		cin >> na;
		for (int j = 0; j < 3; j++) {
			int x;
			cin >> x;
			for (int k = 0; k < x;k ++) {
				string o;
				cin >> o;
				if (j < 2 && o[0] == '*') {
					judge[j][na] = 1;
				} else if (j < 2) {
					judge[j][na] = 0;
				}
				opp[j][na].insert(o);
			}
		}
	}


	for (int i = 0; i < m; i++) {
		string na;
		cin >> na;
		int x;
		cin >> x;
		for (int j = 0;j < x;j ++) {
			char op;
			cin >> op;
			string con;
			cin >> con;
			if (op == 'u')u[con].insert(na);
			if (op == 'g')g[con].insert(na);
		}
	}

	for (int i = 0; i < q; i++) {
		int flag = 0;
		string na;
		cin >> na;
		int x;
		cin >> x;
		string s[x];
		for (int j = 0; j < x; j++) {
			cin >> s[j];
		}

		string op;
		cin >> op;
		string object;
		cin >> object;
		string a;
		cin >> a;

		for (auto it : u[na]) {
			int x = 0,y = 0,z = 0;
			if (judge[0][it] || opp[0][it].count(op)) x = 1;
			if (judge[1][it] || opp[1][it].count(object)) y = 1;
			if (!opp[2][it].size() || opp[2][it].count(a)) z = 1;

			if (x && y && z) {
				flag = 1;
				break;
			}
		}

		for (int j = 0; j < x; j++) {
			for (auto it : g[s[j]]) {
				int x = 0,y = 0,z = 0;
				if (judge[0][it] || opp[0][it].count(op)) x = 1;
				if (judge[1][it] || opp[1][it].count(object)) y = 1;
				if (!opp[2][it].size() || opp[2][it].count(a)) z = 1;

				if (x && y && z) {
					flag = 1;
					break;
				}
			}
		}


		cout << flag << "\n";
	}
}
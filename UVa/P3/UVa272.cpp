#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int flag = 0;
	string s;	
	while (getline(cin,s)) {
		for (int i = 0; i < s.size(); i++) {
			if (s[i] == '"') {
				if (!flag) {
					cout << "``";
				} else {
					cout << "''";
				}
				flag ^= 1;
			} else {
				cout << s[i];
			}
		}
		cout << endl;
	}
}
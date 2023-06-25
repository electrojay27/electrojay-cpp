#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	string s;
	cin >> s;

	string ans;
	string op;
	for (int i = 0; i < n; i++) {
		if (s[i] == '(' || op.size() && s[i] != ')') {
			op += s[i];
		} else if (op.size() && s[i] == ')') {
			cout << 
		}
	}
}
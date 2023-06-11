#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	string s = "`1234567890-=QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./";

	char op;
	while ((op = getchar()) != EOF) {
		for (int i = 0; i < s.size(); i++) {
			if (s[i] == op) {
				cout << s[i - 1];
				break;
			} else if (i == s.size() - 1) {
				cout << op;
			}
		}
	}
}
#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	string s1 = "ABCDEFGHIJKLMNOPQRSTUVWXYZ123456789";
	string s2 = "A...3..HIJ.jM.O...2TUVWXY51SE.Z..8.";

	string s;
	while (cin >> s) {
		int flag = 1;
		int cnt = 1;
		for (int i = 0; i < s.size(); i++) {
			if (s[i] != s[s.size() - 1 - i]) flag = 0;
			char op;
			for (int j = 0; j < s1.size(); j++) {
				if (s[i] == s1[j]) {
					op = s2[j];
					break;
				}
			}
			for (int j = 0; j < s2.size(); j++) {
				if (s[i] == s2[j]) {
					op = s1[j];
					break;
				}
			}

			if (op != s[s.size() - 1 - i]) cnt = 0;
		}

		if (!flag && !cnt) {
			cout << s << " -- is not a palindrome.\n";
		} else if (flag && !cnt) {
			cout << s << " -- is a regular palindrome.\n";
		} else if (!flag && cnt) {
			cout << s << " -- is a mirrored string.\n";
		} else if (flag && cnt) {
			cout << s << " -- is a mirrored palindrome.\n";
		}

		cout << endl;
	}
}
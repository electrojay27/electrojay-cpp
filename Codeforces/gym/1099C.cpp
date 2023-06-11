#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	string s;
	cin >> s;
	int k;
	cin >> k;

	int cnt = 0;

	for (int i = 0; i < s.size(); i++) {
		cnt += s[i] != '?' && s[i] != '*';
	}

	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '*' && cnt < k) {
			s.insert(i,k - cnt,s[i-1]);
			cnt = k;
		} else if (s[i] == '?' || s[i] == '*') {
			s.erase(i--,1);
			if (cnt > k) s.erase(i--,1),cnt --;
		}
	}

	cout << (cnt == k ? s : "Impossible") << "\n";

}
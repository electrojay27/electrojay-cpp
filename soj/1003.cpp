#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	string s;
	cin >> s;
	vector<int> vis(26,0),f(26,0);
	for (int i = 0; i < s.size(); i++) {
		vis[s[i] - 'a'] ++;
	}
	
	string ans;
	for (int i = 0; i < s.size(); i++) {
		if (!f[s[i] - 'a']) {
            while (!ans.empty() && ans.back() > s[i]) {
                if (vis[ans.back() - 'a'] > 0) {
                    f[ans.back() - 'a'] = 0;
                    ans.pop_back();
                } else {
                    break;
                }
            }
            f[s[i] - 'a'] = 1;
            ans += s[i];
        }
        vis[s[i] - 'a'] --;
	}

	cout << ans << "\n";
}
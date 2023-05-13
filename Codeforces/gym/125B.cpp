#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

int main()
{	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	string s;
	cin >> s;

	string ans = "";
	int flag = 1;
	for(int i = 0;i < s.size();){
		string cnt = s.substr(i,3);
		if(cnt[0] == '<' && cnt[2] == '>'){
			cout << ans << cnt << "\n";
			ans = ans + "  ";
			i += 3;
		}else{
			cnt = s.substr(i,4);
			if(ans.size())ans = ans.substr(0,ans.size() - 2);
			cout << ans << cnt << "\n";
			i += 4;
		}
	}
}
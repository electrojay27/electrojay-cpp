#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	string s;
	cin >> s;

	int ans = -1;

	for(int i = 0;i < s.size();i ++){
		int cmp = 0;
		if(s[i] == '-'){
			i ++;
			while(s[i] == 'o'){
				cmp ++;
				i ++;
			}
			if(cmp)ans = max(ans,cmp);
			i --;
		}
	}

	for(int i = s.size();i >= 0;i --){
		int cmp = 0;
		if(s[i] == '-'){
			i --;
			while(s[i] == 'o'){
				cmp ++;
				i --;
			}
			if(cmp)ans = max(ans,cmp);
			i ++;
		}
	}

	cout << ans << "\n";

	return 0;
}
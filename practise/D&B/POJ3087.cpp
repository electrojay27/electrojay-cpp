#include <iostream>
#include <cstring>
using namespace std;
#define i64 = long long;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	for(int i = 1;i <= t;i ++){
		int len;
		string s1,s2;
		string s12;
		cin >> len >> s1 >> s2 >> s12;

		int ans = 0;
		while(ans < 1000){
			if(s1 + s2 == s12){
				cout << i << " " << ans << "\n";
				break;
			}

			string temp = "";
			for(int j = 0;j < len;j ++){
				temp = temp + s2[j] + s1[j];
			}
			s1 = temp.substr(0,len);
			s2 = temp.substr(len);
			ans ++;
		}

		if(ans == 1000)cout << i << " " << "-1\n";
	}	
	return 0;
}
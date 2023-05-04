#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	string s;
	cin >> s;

	int sign = 1;
	int flag = -1;
	for(int i = 0; i < s.size(); i ++){
		if(s[i] == '-'){
			sign = -1;
		}
		if(s[i] == '.'){
			flag = i;
			break;
		}
	}

	if(flag == -1){
		if(sign == -1){
			cout << "($";
			s = s.substr(1);
			for(int i = 0; i < s.size();){
				if(!i && s.size() % 3 != 0){
					cout << s.substr(i,s.size() % 3);
					i = s.size() % 3;
				}else cout << s.substr(i,3),i += 3;

				if(i < s.size() - 1)cout << ",";
			}
			cout << ".00)\n";
		}else{
			cout << "$";
			// s = s.substr(1);
			for(int i = 0; i < s.size();){
				if(!i && s.size() % 3 != 0){
					cout << s.substr(i,s.size() % 3);
					i = s.size() % 3;
				}else cout << s.substr(i,3),i += 3;

				if(i < s.size() - 1)cout << ",";
			}
			cout << ".00\n";
		}
	}else{
		if(flag + 3 > s.size()){
			s = s + '0';
		}else{
			s = s.substr(0,flag + 3);
		}

		if(sign == -1){
			// cout << s << "'s flag = " << flag << "\n";
			cout << "($";
			s = s.substr(1);
			flag --;
			for(int i = 0; i < flag;){
				if(!i && flag % 3 != 0){
					cout << s.substr(i,flag % 3);
					i = flag % 3;
				}else{
					cout << s.substr(i,3);
					i += 3;
				}
				if(i < flag - 1)cout << ",";
			}
			cout << s.substr(flag,3) << ")\n";
		}else{
			cout << "$";
			// s = s.substr(1);
			// flag --;
			for(int i = 0; i < flag;){
				if(!i && flag % 3 != 0){
					cout << s.substr(i,flag % 3);
					i = flag % 3;
				}else cout << s.substr(i,3),i += 3;

				if(i < flag - 1)cout << ",";
			}
			cout << s.substr(flag,3) << "\n";
		}
	}

}
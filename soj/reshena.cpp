#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	string a,b;
	int cnt = 1;
	int n = 10;
	while(cin >> a >> b){
		int fa = 0,fb = 0;

		int cmp = 0;
		cout << "Case " << cnt ++ << ": ";

		if(a[0] == '-' && b[0] != '-'){
			fa = 1;
			a = a.substr(1);
		}else if(b[0] == '-' && a[0] != '-'){
			fb = 1;
			b = b.substr(1);
		}else if(a[0] == '-' && b[0] == '-'){
			string c = a.substr(1);
			a = b.substr(1);
			b = c;
		}

		vector<int> az;
		vector<int> ax;
		int flag = 1;
		for(int i = 0;i < a.size();i ++){
			if(a[i] == '.'){
				flag = 0;
				continue;
			}
			if(flag){
				az.push_back(a[i] - '0');
			}else{
				ax.push_back(a[i] - '0');
			}
		}

		vector<int> bz;
		vector<int> bx;
		flag = 1;
		for(int i = 0;i < b.size();i ++){
			if(b[i] == '.'){
				flag = 0;
				continue;
			}
			if(flag){
				bz.push_back(b[i] - '0');
			}else{
				bx.push_back(b[i] - '0');
			}
		}

		// cout << cnt - 1 << ": " << a << " " << b << "\n"; 

		if(az.size() > bz.size()){
			cmp = 1;
		}else if(az.size() < bz.size()){
			cmp = -1;
		}else{
			for(int i = 0;i < az.size();i ++){
				if(az[i] > bz[i]){
					cmp = 1;
					break;
				}else if(az[i] < bz[i]){
					cmp = -1;
					break;
				}
			}
		}

		if(cmp){
			if(cmp == 1 && !fa || cmp == -1 && fb)cout << "Bigger\n";
			else cout << "Smaller\n";
		}else{
			int len = min(ax.size(),bx.size());

			for(int i = 0;i < len;i ++){
				if(ax[i] > bx[i]){
					cmp = 1;
					break;
				}else if(ax[i] < bx[i]){
					cmp = -1;
					break;
				}
			}

			if(!cmp && ax.size() > bx.size()){
				for(int i = len;i < ax.size();i ++){
					if(ax[i] != 0){
						cmp = 1;
						break;
					}
				}
			}else if(!cmp && ax.size() < bx.size()){
				for(int i = len;i < bx.size();i ++){
					if(bx[i] != 0){
						cmp = -1;
						break;
					}
				}
			}

			if(cmp == 1 && !fa || cmp == -1 && fb)cout << "Bigger\n";
			else if(cmp == -1 && !fb || cmp == 1 && fa)cout << "Smaller\n";
			else cout << "Same\n";
		}
	}

	return 0;
}
#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

bool prime(i64 x){
	if(x == 2)return true;
	for(int i = 2;i * i <= x;i ++){
		if(x % i == 0)return false;
	}
	return true;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	i64 n;
	cin >> n;

	vector<i64> num;
	for(i64 i = 2;i <= 300000;i ++){
		if(prime(i)){
			num.push_back(i);
			// cout << i << "\n";
		}
	}

	set<i64> st;
	i64 ans = 0;
	for(int i = 0;i < num.size();i ++){
		for(int j = i + 1;j < num.size();j ++){
			for(int k = j + 1;k < num.size();k ++){
				i64 cnt = num[i] * num[i] * num[j] * num[k] * num[k];
				if(cnt <= n){
					if(!st.count(cnt)){
						st.insert(cnt);
						ans ++;
					}
				}else break;
			}
		}
	}

	cout << ans << "\n";

}
#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	string s,t;
	cin >> s >> t;

	set<int> st;
	string abc = "atcoder";
	for(int i = 0;i < abc.size();i ++){
		st.insert(abc[i] - 'a');
	}

	vector<int> op1(27,0);
	for(int i = 0;i < s.size();i ++){
		if(s[i] != '@'){
			op1[s[i] - 'a'] ++;
		}else{
			op1[26] ++;
		}
	}

	vector<int> op2(27,0);
	for(int i = 0;i < t.size();i ++){
		if(t[i] != '@'){
			op2[t[i] - 'a'] ++;
		}else op2[26] ++;
	}

	for(int i = 0;i < 26;i ++){
		if(op1[i] != op2[i]){
			if(!st.count(i)){
				cout << "No\n";
				return 0;
			}

			if(op1[i] > op2[i] && op2[26] < op1[i] - op2[i] || op1[i] < op2[i] && op1[26] < op2[i] - op1[i]){
				cout << "No\n";
				return 0;
			}
		}
	}

	cout << "Yes\n";

	return 0;
}
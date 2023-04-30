#include <bits/stdc++.h>
using namespace std;

map<string,int> tire;
vector<string> word;

string repr(string str)
{
	for(int i = 0;i < str.size();i ++)
	{
		str[i] = tolower(str[i]);
	}

	sort(str.begin(),str.end());
	return str;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	string op;

	while(cin >> op)
	{
		if(op[0] == '#')break;
		word.push_back(op);//先放进去
		op = repr(op);//再统一

		if(!tire.count(op)){
			tire[op] = 1;
		}else tire[op] ++;
	}

	vector<string> ans;

	for(int i = 0;i < word.size();i ++)
	{
		if(tire[repr(word[i])] == 1)ans.push_back(word[i]);
	}

	sort(ans.begin(),ans.end());
	for(int i = 0;i < ans.size();i ++)
	{
		cout << ans[i] << endl;
	}
	return 0;
}
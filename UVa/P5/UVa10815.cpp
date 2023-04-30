#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	set<string> tire;

	string str,word;

	while(cin >> str)
	{
		for(int i = 0;i < str.size();i ++)
		{
			if(isalpha(str[i]))str[i] = tolower(str[i]);
			else str[i] = ' ';
		}

		stringstream strs(str);
		while(strs >> word)tire.insert(word);
	}

	for(auto it = tire.begin();it != tire.end();it ++)
	{
		cout << *it << endl;
	}
	return 0;
}
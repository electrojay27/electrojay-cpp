#include <bits/stdc++.h>
using namespace std;

int n;

void solve()
{
	cin >> n;
	vector<int> arr(n);
	vector<int> ans;
	for(int i = 0;i < n - 1;i ++)
	{
		cin >> arr[i];
	}

	for(int i = 0;i < n - 1;i ++)
	{
		if(!i)ans.push_back(arr[i]);
		else{
			if(ans.size() == i + 1){
				if(ans[i] == arr[i])continue;
				if(ans[i] < arr[i])ans.push_back(arr[i]);
			}else{
				if(arr[i] <= ans[i - 1])ans.push_back(arr[i]);
				else{
					ans.push_back(0);
					ans.push_back(arr[i]);
				}
			}
		}
	}

	if(ans.size() < n)ans.push_back(0);

	for(int i = 0;i < n;i ++)cout << ans[i] << " ";

	cout << endl;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;
	while(t --)
	{
		solve();
	}
	return 0;
}
#include <bits/stdc++.h>
using namespace std;

int n,x;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	while(cin >> n && n != -1)
	{
		vector<int> num;
		map<int,int> all;
		for(int i = 1;i <= n;i ++){
			cin >> x;
			if(!all.count(x)){
				num.push_back(x);
				all[x] = 1;
			}else{
				all[x] ++;
			}
		}

		// for(auto x : num){
		// 	if(all[x] >= (n + 1) / 2){
		// 		cout << x << endl;
		// 		break;
		// 	}
		// }

		// sort(num.begin(),num.end());

		sort(num.begin(),num.end(),[](int i,int j){
			return all[i] > all[j];
		});

		cout << num[0] << endl;
	}
	return 0;
}
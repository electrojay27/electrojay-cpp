#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
const int N = 2e5 + 10;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n,q;
	cin >> n >> q;

	vector<vector<int>> box(n + 1);
	vector<set<int>> st(N);

	int op,x,y;

	for(int i = 1;i <= q;i ++){
		cin >> op;
		if(op == 1){
			cin >> x >> y;
			box[y].push_back(x);
			st[x].insert(y);
		}else if(op == 2){
			cin >> x;
			sort(box[x].begin(),box[x].end());
			for(auto it : box[x]){
				cout << it << " ";
			}
			cout << "\n";
		}else{
			cin >> x;
			for(auto it = st[x].begin();it != st[x].end();it ++){
				cout << *it << " ";
			}
			cout << "\n";
		}
	}
}
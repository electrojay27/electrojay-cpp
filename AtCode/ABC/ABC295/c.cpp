#include <bits/stdc++.h>
using namespace std;

int n,x,ans;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	while(cin >> n){
		ans = 0;
		map<int,int> a;
		for(int i = 1;i <= n;i ++){
			cin >> x;
			if(!a.count(x)){
				a[x] = 1;
			}else{
				a[x] ++;
				if(a[x] >= 2){
					ans ++;
					a[x] -= 2;
				}
			}
		}

		cout << ans << endl;
	}
	return 0;
}
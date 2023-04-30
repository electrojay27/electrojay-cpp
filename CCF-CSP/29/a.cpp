#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

struct node
{
	int x1,x2,y1,y2;
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n,a,b;
	cin >> n >> a >> b;
	int ans = 0;
	int x1,x2,y1,y2;
	for(int i = 0;i < n;i ++){
		int sa = a,sb = b,sc = 0,sd = 0;
		cin >> x1 >> y1 >> x2 >> y2;

		if(x2 <= 0 || y2 <= 0 || x1 >= a || y1 >= b)continue;
		else{
			if(y1 > sd)sd = y1;
			if(x1 > sc)sc = x1;
			if(y2 < sb)sb = y2;
			if(x2 < sa)sa = x2;
			ans += (sa - sc) * (sb - sd);
		}
	}

	cout << ans << endl;
}
#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

i64 c,b,s,i,j,k,cx,bx,sx,r;

bool judge(i64 x)
{
	i64 u = max(x * bx - b,0LL);
	i64 w = max(x * sx - s,0LL);
	i64 v = max(x * cx - c,0LL);
	if(u * i + w * j + v * k <= r)return true;

	return false;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	string op;
	cin >> op;
	cin >> b >> s >> c;
	cin >> i >> j >> k;
	cin >> r;
	cx = bx = sx = 0;
	for(int a = 0;a < op.size();a ++){
		if(op[a] == 'C'){
			cx ++;
		}else if(op[a] == 'B'){
			bx ++;
		}else sx ++;
	}

	i64 l = 0,r = 1e14;
	while(l <= r){
		i64 mid = (l + r) / 2;
		if(judge(mid))l = mid + 1;
		else r = mid - 1;
		// cout << mid << "\n";
	}

	cout << l - 1 << "\n";
}
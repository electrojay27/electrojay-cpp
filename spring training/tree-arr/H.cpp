#include <bits/stdc++.h>
using namespace std;
#define lowbit(x) ((x) & -(x))

using i64 = long long;

const int maxn = 1e6;
int n;
int ne[maxn + 1];
int now[27];
int to[27];
int num[maxn + 1];
int t[maxn + 1];

void update(int x,int d){
	while(x <= maxn){
		t[x] += d;
		x += lowbit(x);
	}
}

int query(int x)
{
	int ret = 0;
	while(x > 0){
		ret += t[x];
		x -= lowbit(x);
	}
	return ret;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	string s,op;
	cin >> n >> s >> op;
	s = '0' + s;
	op = '0' + op;
	for(int i = 1;i <= n;i ++){
		int ch = s[i] - 'A' + 1;
		if(!now[ch])now[ch] = i;//首次出现的位置
		ne[to[ch]] = i;//利用上一次的标记给下一个字母标记位置
		to[ch] = i;
	}

	for(int i = 1;i <= n;i ++){
		int ch = op[i] - 'A' + 1;
		num[now[ch]] = i;
		now[ch] = ne[now[ch]];
	}

	i64 ans = 0;
	for(int i = n;i > 0;i --){
		update(num[i],1);
		ans += query(num[i] - 1);
	}

	cout << ans << endl;

	return 0;
}
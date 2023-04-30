#include <bits/stdc++.h>
using namespace std;
#define lowbit(x) ((x) & -(x))

using i64 = long long;

const int maxn = 5e5;
struct node
{
	int id,sum;

	bool operator <(const node& t)const{
		if(sum != t.sum)return sum < t.sum;
		return id < t.id;
	}
}a[maxn + 1];
int t[maxn + 1];
int num[maxn + 1];
int n;

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

	cin >> n;

	// vector<int> a(n);
	// set<int> num;

	for(int i = 0;i < n;i ++){
		cin >> a[i].sum;
		a[i].id = i;
	}

	sort(a,a + n);
	for(int i = 0;i < n;i ++)num[a[i].id] = i + 1;//离散化
	//主要思路就是通过离散来改变相对值
	
	i64 ans = 0;

	for(int i = n - 1;i >= 0;i --){
		ans += query(num[i] - 1);
		update(num[i],1);
	}

	cout << ans << endl;

	return 0;
}
#include <iostream>
#include <cstring>
using namespace std;
#define int long long
#define lowbit(x) ((x) & -(x))

const int maxn = 1500;
int n,cnt,op;
int t[maxn][maxn];
// int a[maxn];

void update(int x,int y,int d){
	for(;x <= n;x += lowbit(x)){
		for(int i = y;i <= n;i += lowbit(i)){
			t[x][i] += d;
		}
	}
}

int query(int x,int y){
	int ret = 0;
	for(;x > 0;x -= lowbit(x)){
		for(int i = y;i > 0;i -= lowbit(i)){
			ret += t[x][i];
		}
	}
	return ret;
}

void solve()
{	
	cin >> cnt >> n;
	memset(t,0,sizeof(t));
	// t[0] = 0;

	// for(int i = 0;i < n;i ++){
	// 	for(int j = 1;j <= n;j ++){
	// 		update(i * n + j,0);
	// 	}
	// }

	int A,x,y;
	int L,B,R,T;

	while(cin >> op && op != 3){
		if(op == 1){
			cin >> x >> y >> A;
			x ++,y ++;
			update(x,y,A);
		}else if(op == 2){
			cin >> L >> B >> R >> T ;

			L ++,B ++,R ++,T ++;

			cout << query(R,T) - query(R,B-1) + query(L-1,B-1) - query(L-1,T) << endl;
		}
	}
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	solve();
	
	return 0;
}
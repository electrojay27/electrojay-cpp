#include <bits/stdc++.h>
using namespace std;

const int maxn = 5e4 + 10;
int n,m,k;

struct node{
	int sug,wat;
	int idx;//糖与水的差值

	// bool operator < (const node&t)const{
	// 	if(idx != t.idx)return idx > t.idx;
	// 	return sug < t.sug;
	// }
};

bool cmp1(node x,node y){
	if(x.idx != y.idx)return x.idx > y.idx;
	return x.sug < y.sug;
}

bool cmp2(node x,node y){
	if(x.idx != y.idx)return x.idx < y.idx;
	return x.sug > y.sug;
}

double Sum(node x,node y){
	int Ssug = x.sug + y.sug;
	int Swat = x.wat + y.wat;
	return 1.0 * Ssug / ((Ssug + Swat) * 1.0);
}

node a[maxn],b[maxn];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	while(cin >> n >> m >> k){

		for(int i = 1;i <= n;i ++){
			cin >> a[i].sug >> a[i].wat;
			a[i].idx = a[i].sug - a[i].wat;
		}

		for(int i = 1;i <= m;i ++){
			cin >> b[i].sug >> b[i].wat;
			b[i].idx = b[i].sug - b[i].wat;
		}
		if(k <= n * m / 2){
			sort(a + 1,a + 1 + n,cmp1);
			sort(b + 1,b + 1 + n,cmp1);
		}else{
			sort(a + 1,a + 1 + n,cmp2);
			sort(b + 1,b + 1 + n,cmp2);
		}

		if(k == 1)cout << fixed << setprecision(10) << Sum(a[1],b[1]) << endl;
		else{
			if(k <= n * m / 2){
			}
		}
	}
	return 0;
}
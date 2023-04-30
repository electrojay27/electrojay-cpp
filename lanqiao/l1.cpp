#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e6 + 10;
int a[maxn];
int n,m,op,q;

bool cmp(int a,int b){
	return a > b;//大优先
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	while(cin >> n >> m){
		for(int i = 1;i <= n;i ++)a[i] = i;
		for(int i = 1;i <= m;i ++){
			cin >> op >> q;
			if(op == 0){
				sort(a + 1,a + 1 + q,cmp);
			}else{
				sort(a + q,a + 1 + n);
			}
		}

		for(int i = 1;i <= n;i ++)cout << a[i] << " ";
		cout << endl;
	}
}
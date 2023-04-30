#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int maxn = 2e5 + 10;
int t,n,q;
int l,r,k;
int a[maxn];
// int a[110],b[110];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	while(cin >> t){
		while(t --){
			cin >> n >> q;
			a[0] = 0;
			for(int i = 1;i <= n;i ++){
				cin >> a[i];
				a[i] += a[i-1];//前缀和
			}
			a[n + 1] = a[n];
			for(int i = 1;i <= q;i ++){
				cin >> l >> r >> k;
				ll sum = a[n + 1] - a[r] + a[l - 1] + (r - l + 1) * k;
				if(sum % 2)cout << "YES" << endl;
				else cout << "NO" << endl;
			}
		}
	}
	return 0;
}
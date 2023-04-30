#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 10;
int a[maxn],b[maxn];
int ida[maxn],idb[maxn];
int n,m,x;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	while(cin >> n >> m){
		for(int i = 1;i <= n;i ++)cin >> a[i];
		for(int i = 1;i <= m;i ++)cin >> b[i];

		int l = 0,r = 0;
		for(int i = 1;i <= n + m;i ++){

			if(a[l + 1] < b[r + 1] && l < n && r < m)ida[++ l] = i;
			else if(a[l + 1] > b[r + 1] && r < m && l < n)idb[++ r] = i;

			if(l == n){
				while(i <= n + m){
					idb[++ r] = ++ i;
				}
			}else if(r == m){
				while(i <= n + m){
					ida[++ l] = ++ i;
				}
			}
		}

		for(int i = 1;i <= n;i ++)cout << ida[i] << " ";
		cout << endl;
		for(int i = 1;i <= m;i ++)cout << idb[i] << " ";
		cout << endl;
	}
	return 0;
}
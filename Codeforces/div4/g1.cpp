#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int maxn = 2e5 + 10;
int c[maxn];
int a[maxn];
int t,n,x;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	while(cin >> t){
		while(t --){
			cin >> n;
			for(int i = 1;i <= n;i ++){
				cin >> c[i];
			}
			sort(c + 1,c + 1 + n);
			ll sum = 0;
			int flag = 1;
			for(int i = 1;i <= n;i++){
				if(i == 1 && c[i] == 1){
					sum ++;
					continue;
				}
				if(sum < c[i]){
					flag = 0;
					cout << "NO" << endl;
					break;
				}
				sum += c[i];
			}
			if(flag)cout << "YES" << endl;

		}
	}
	return 0;
}
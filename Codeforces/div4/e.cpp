#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e3 + 10;
int sum[maxn];
int t,n,x;
int a,b,c,d;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	while(cin >> t){
		while(t --){
			cin >> n;
			sum[0] = 0;
			for(int i = 1;i <= n;i ++){
				cin >> sum[i];
				sum[i] += sum[i - 1];
			}
			sum[n + 1] = sum[n];

			int flag = 0;
			int l = 1,r = n;
			while(l < r){
				int mid = (l + r + 1) / 2;
				cout << '?' << " " << mid - l + 1 << " ";
				for(int i = l;i <= mid;i ++){
					cout << i << " ";
				}
				cout << endl;
				cin >> x;
				if(x == sum[mid] - sum[l - 1])l = mid + 1;
				else{
					r = mid;
				}
			}
			cout << "!" << " " << r << endl;
			
		}
	}
	return 0;
}
#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll ans,sum,mx;
int n,x,cnt,flag;

ll mi(int a){
	ll cmp = 1;
	for(int i = 1;i <= a;i ++){
		cmp *= 2;
	}
	return cmp;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	while(cin >> n){
		cnt = 0;
		flag = 0;
		mx = 0;
		sum = 0;
		for(int i = 1;i <= n;i ++){
			cin >> x;
			sum += x;
			if(i == mi(cnt) + flag){
				flag += mi(cnt);
				cnt ++;
				if(mx < sum){
					mx = sum;
					ans = cnt;
				}
				sum = 0;
			}else if(i == n && mx < sum)ans = cnt + 1;
		}
		cout << ans << endl;
	}
}
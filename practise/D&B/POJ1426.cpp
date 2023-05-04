#include <iostream>
#include <queue>
using namespace std;

#define i64 long long

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	while(cin >> n){
		if(!n)break;
		i64 ans = 1;
		queue<i64> q;
		q.push(ans);
		int flag = 0;
		while(!q.empty()){
			i64 cnt = q.front();
			q.pop();
			if(cnt % n == 0){
				cout << cnt << "\n";
				flag = 1;
				break;
			}
			q.push(cnt * 10);
			q.push(cnt * 10 + 1);
		}

		if(!flag)cout << -1 << "\n";
	}
	return 0;
}
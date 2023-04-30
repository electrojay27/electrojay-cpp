#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

const int maxn = 100000;
int n,m;
int t[maxn + 10];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	while(cin >> n >> m)
	{
		memset(t,0,sizeof(t));
		queue<int> q;
		q.push(n);

		int ans;

		while(!q.empty())
		{	
			int now = q.front();
			q.pop();

			if(now == m){
				ans = t[now];
				break;
			}

			if(now + 1 <= maxn && !t[now + 1])
			{
				t[now + 1] = t[now] + 1;
				// if(now + 1 == m){
				// 	ans = t[now + 1];
				// 	break;
				// }
				q.push(now + 1);
			}
			if(now - 1 >= 0 && !t[now - 1]){
				t[now - 1] = t[now] + 1;
				// if(now - 1 == m){
				// 	ans = t[now - 1];
				// 	break;
				// }
				q.push(now - 1);
			}
			if(now * 2 <= maxn && !t[now * 2])
			{
				t[now * 2] = t[now] + 1;
				// if(now * 2 == m){
				// 	ans = t[now * 2];
				// 	break;
				// }
				q.push(2 * now);
			}
		}

		cout << ans << endl;
	}
}
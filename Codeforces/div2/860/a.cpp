#include <bits/stdc++.h>
using namespace std;

const int maxn = 110;
int t;
int n;
int a[maxn],b[maxn];
bool vis[2][maxn];

bool cmp(int x){
	if((a[x] <= a[n] && b[x] <= b[n]) || (b[x] <= a[n] && a[x] <= b[n]))return true;
	else return false;
}

void solve()
{
	cin >> n;
	memset(vis,0,sizeof(vis));
	int flag = 1;
	// int mxa,mxb;
	// mxa = mxb = 0;
	for(int i = 1;i <= n;i ++)
		cin >> a[i];
	
	for(int i = 1;i <= n;i ++)
		cin >> b[i];

	for(int i = 1;i < n;i ++){
		if(!cmp(i)){
			flag = 0;
			break;
		}
	}

	if(flag)cout << "Yes" << endl;
	else cout << "No" << endl;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	while(cin >> t){
		while(t --){
			solve();
		}
	}
	return 0;
}
#include <bits/stdc++.h>
#define inf 0x3f3f3f3f
using namespace std;

using i64 = long long;

int n;int a[210];
int sum[210];
int Max[210][210];
int Min[210][210];

void init(){
	memset(Max,0,sizeof(Max));
	memset(Min,inf,sizeof(Min));
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	init();

	cin >> n;
	sum[0] = 0;
	for(int i = 1;i <= n;i ++){
		cin >> a[i];
		a[i + n] = a[i];
		Max[i][i] = 0;
		Min[i][i] = 0;
		sum[i] = sum[i - 1] + a[i];
	}

	for(int i = n + 1;i <= 2 * n;i ++){
		sum[i] = sum[i - 1] + a[i];
		Max[i][i] = 0;
		Min[i][i] = 0;
	}

	for(int len = 2;len <= n;len ++){
		for(int i = 1;i + len - 1 <= 2 * n;i ++){
			int end = i + len - 1;
			for(int j = i;j < end;j ++){
				Max[i][end] = max(Max[i][end],Max[i][j] + Max[j + 1][end]);
				Min[i][end] = min(Min[i][end],Min[i][j] + Min[j + 1][end]);
			}
			Max[i][end] += sum[end] - sum[i - 1];
			Min[i][end] += sum[end]  -sum[i - 1];
		}
	}

	int ans_min = inf,ans_max = 0;
	for(int i = 1;i <= n;i ++){
		ans_max = max(ans_max,Max[i][i + n - 1]);
		ans_min = min(ans_min,Min[i][i + n - 1]);
	}

	cout << ans_min << endl << ans_max << endl;
}
#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

int main()
{
	int n;
	double i;
	scanf("%d%lf",&n,&i);

	double ans = 0;
	double x;
	for(int j = 0;j <= n;j ++){
		cin >> x;
		ans += x * pow(1 + i,-j);
	}	

	printf("%f",ans);
}
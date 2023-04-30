#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int h,w;
	cin >> h >> w;

	string A[h];
	string B[h];

	for(int i = 0;i < h;i ++){
		cin >> A[i];
	}
	for(int i = 0;i < h;i ++){
		cin >> B[i];
	}

	for(int i = 0;i < w;i ++){
		for(int j = 0;j < h;j ++){
			string op = A[j].substr(1) + A[j].substr(0,1);
			A[j] = op;
		}

		for(int j = 0;j < h;j ++){
			if(A[0] == B[j]){
				int cnt = (j + 1) % h;
				int cmp = 1;
				while(A[cmp] == B[cnt]){
					cmp ++;
					cnt ++;
					cmp %= h;
					cnt %= h;
					if(cnt == j){
						cout << "Yes\n";
						return 0;
					}
				}
			}
		}
	}
	
	cout << "No\n";
	return 0;
}
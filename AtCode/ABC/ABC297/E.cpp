#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	i64 N,K;

	cin >> N >> K;

	vector<i64> A(N);

	for(int i = 0;i < N;i ++){
		cin >> A[i];
	}

	set<i64> num{0};
	for(int i = 0;i < K;i ++){
		i64 x = *num.begin();
		num.erase(x);//除掉里面这个数
		for(int j = 0;j < N;j ++){
			num.insert(x + A[j]);
		}
	}

	// for(auto it : num){
	// 	cout << it << " ";
	// }cout << endl;

	cout << *num.begin() << endl;

	return 0;
}
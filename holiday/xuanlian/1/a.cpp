#include <iostream>
#include <vector>
#include <queue>
#define ll long long
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	vector<vector<int>> mp(n,vector<int>(n,0));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> mp[i][j];
		}
	}

	vector<vector<int>> f(n,vector<int>(n,-1));//0是小于，1是大于
	
}
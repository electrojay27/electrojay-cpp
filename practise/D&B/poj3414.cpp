#include <iostream>
#include <set>
#include <utility>
#include <map>
#include <queue>
#include <vector>
using namespace std;
#define pii pair<int,int>
#define i64 = long long

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int a,b,c;
	cin >> a >> b >> c;
	
	if(c > a && c > b){
		cout << "impossible\n";
		return 0;
	}

	set<pii> st;
	map<pii,int> m;
	queue<pii> q;
	vector<vector<int>> vis(101,vector<int>(101,0));
	q.push({0,0});
	int flag = 0;
	while(!q.empty()){
		
	}
}
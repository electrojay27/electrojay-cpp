#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <unordered_map>
using namespace std;

char f[6][10] = {"FILL(2)","FILL(2)","DROP(1)","DROP(2)","POUR(1,2)","POUR(2,1)"};

struct node
{	
	int cnt;
	int A,B;
	queue<int> v;

	node (int c, int a, int b) {
		cnt = c;
		A = a;
		B = b;
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int a,b,c;
	cin >> a >> b >> c;

	queue<node> q;
	q.push({0,a,b});
	unordered_map<node,int> vis;
	node now(0,a,b);
	vis[now] = 1;
	while (!q.empty()) {
		node to = q.front();
		q.pop();

	}

		
}
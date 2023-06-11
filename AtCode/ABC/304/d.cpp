#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

struct node
{
	int x,y;
	int a,b;
};

bool cmp1(const node& a,const node& b) {
	return a.x < b.x;
}

bool cmp2(const node& a,const node& b) {
	return a.y < b.y;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int w,h;
	cin >> w >> h;

	int n;
	cin >> n;

	vector<node> p(n);
	for (int i = 0; i < n; i++) {
		cin >> p[i].x >> p[i].y;
		p[i].a = p[i].b = 0;
	}

	int A;
	cin >> A;
	vector<int> a(A); 
	for (int i = 0; i < A; i++) cin >> a[i];
	int B;
	cin >> B;
	vector<int> b(B);
	for (int i = 0; i < B; i++) cin >> b[i];

	int mx = 0,mn = 0x3f3f3f3f;
	int cnt = 0;
	sort(p.begin(),p.end(),cmp1);
	for (int i = 0; i < A; i++) {
		for (; cnt < n; cnt++) {
			if (p[cnt].x <= a[i]) {
				p[cnt].a = i;
			} else {
				break;
			}
		}
	}
	if (cnt != n) {
		for (; cnt < n; cnt++) {
			p[cnt].a = A;
		}
	}

	cnt = 0;
	sort(p.begin(),p.end(),cmp2);
	for (int i = 0; i < B; i++) {
		for (; cnt < n; cnt++) {
			if (p[cnt].y <= b[i]) {
				p[cnt].b = i;
			} else {
				break;
			}
		}
	}
	if (cnt != n) {
		for (; cnt < n; cnt++) {
			p[cnt].b = B;
		}
	}

	map<pair<int,int>,int> st;
	for (int i = 0; i < n; i++) {
		st[{p[i].a,p[i].b}] ++;
	}

	for (auto it : st) {
		mx = max(it.second,mx);
		mn = min(it.second,mn);
	}

	if (st.size() < 1LL * (A + 1) * (B + 1)) {
		mn = 0;
	}

	cout << mn << " " << mx << "\n";
}
#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

struct node
{
	int a,b,c;

	bool operator < (const node& that) const {
		if (a != that.a)return a < that.a;
		if (b != that.b)return b < that.b;
		if (c != that.c)return c < that.c;
	}
};

bool cmp1(const node& a1, const node& a2) {
	return a1.a < a2.a;
}

bool cmp2(const node& a1, const node& a2) {
	return a1.b < a2.b;
}


bool cmp3(const node& a1, const node& a2) {
	return a1.c < a2.c;
}



int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	vector<node> v(n);
	for (int i = 0; i < n; i++) {
		int a,b,c;
		cin >> a >> b >> c;
		if (a > b)swap(a,b);
		if (a > c)swap(a,c);
		if (b > c)swap(b,c);
		v[i].a = a;
		v[i].b = b;
		v[i].c = c;
	}

	// sort(v.begin(),v.end(),[&](int i,int j) {
	// 	return v[i].a < v[j].a;
	// });
	sort(v.begin(),v.end(),cmp1);
	for (int i = 0;i < n - 1; i++) {
		if (v[i].a < v[n - 1].a && v[i].b < v[n - 1].b && v[i].c < v[n - 1].c) {
			cout << "Yes\n";
			return 0;
		}
	}
	sort(v.begin(),v.end(),cmp2);
	for (int i = 0;i < n - 1; i++) {
		if (v[i].a < v[n - 1].a && v[i].b < v[n - 1].b && v[i].c < v[n - 1].c) {
			cout << "Yes\n";
			return 0;
		}
	}
	sort(v.begin(),v.end(),cmp2);
	for (int i = 0;i < n - 1; i++) {
		if (v[i].a < v[n - 1].a && v[i].b < v[n - 1].b && v[i].c < v[n - 1].c) {
			cout << "Yes\n";
			return 0;
		}
	}
	cout << "No\n";
}
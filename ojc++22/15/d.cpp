#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

class MyMatrix
{
private:
	int** a;
	int _size;
public:
	MyMatrix (int x) {
		_size = x;
		a = new int* [_size];
		for (int i = 0; i < _size; i++) {
			a[i] = new int[_size];
		}
	}
	~MyMatrix() {for (int i = 0; i < _size; i++) { delete[] a[i]; } delete[] a; }
	void set() {
		for (int i = 0; i < _size; i++) {
			for (int j = 0; j < _size; j++) {
				cin >> a[i][j];
			}
		}
	}
	void init() {
		for (int i = 0; i < _size; i++) {
			for (int j = 0; j < _size; j++) {
				a[i][j] = 0;
			}
		}
	}
	MyMatrix& operator= (const MyMatrix& now) {
		for (int i = 0; i < _size; i++) {
			for (int j = 0; j < _size; j++) {
				(*this).a[i][j] = now.a[i][j];
			}
		}
		return *this;
	}
	friend MyMatrix operator* (const MyMatrix& l,const MyMatrix& r) {
		MyMatrix res(l._size);
		res.init();

		for (int i = 0; i < res._size; i++) {
			for (int j = 0; j < res._size; j++) {
				for (int k = 0; k < res._size; k++) {
					res.a[i][j] += l.a[i][k] * r.a[k][j];
				}
			}
		}
		return res;
	}
	void show() {
		for (int i = 0; i < _size; i++) {
			for (int j = 0; j < _size; j++) {
				cout << a[i][j] << " \n"[j == _size - 1];
			}
		}
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t;
	cin >> t;
	int _size;
	cin >> _size;
	MyMatrix ans(_size);
	ans.set();
	for (int i = 1; i < t; i++) {
		MyMatrix p(_size);
		p.set();
		ans = ans * p;
	}
	
	ans.show();
}
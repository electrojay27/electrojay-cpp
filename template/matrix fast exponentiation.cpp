#include <bits/stdc++.h>
#define mod 1000000007
using namespace std;

using i64 = long long;

struct matrix
{
	i64 a[2][2];

	matrix() {
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < 2; j++) {
				a[i][j] = 0;
			}
		}
	}

	void init() {
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < 2; j++) {
				a[i][j] = 1;
			}
		}
		a[0][0] = 0;
	}

	void initial() {
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < 2; j++) {
				a[i][j] = 1;
			}
		}
		a[1][0] = 0;
	}

	friend ostream &operator<<(ostream& output, const matrix& m)
    { 
        output << m.a[0][0];
        return output;            
    }
};

matrix operator * (const matrix& left, const matrix& right) {
	matrix res;
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			for (int k = 0; k < 2; k++) {
				res.a[i][j] = (res.a[i][j] + (left.a[i][k] * right.a[k][j]) % mod) % mod;
			}
		}
	}
	return res;
}

matrix power(matrix a, i64 b) {
    matrix res;
    res.initial();
    for (; b; b /= 2, a = a * a) {
        if (b % 2) {
            res = res * a;
        }
    }
    return res;
}
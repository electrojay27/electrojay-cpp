#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

class CSet
{
private:
    int* data;
    int size;
public:
    CSet () {}
    CSet (int x) {
        size = x;
        data = new int[size];
    }
    void set() {
        for (int i = 0; i < size; i++) {
            cin >> data[i];
        }
    }
    void Set(vector<int> a) {
        for (int i = 0; i < a.size(); i++) {
            data[i] = a[i];
        }
    }
    void print() {
        for (int i = 0; i < size; i++) {
            cout << data[i] << " \n"[i == size - 1];
        }
    }
    void operator = (const CSet& a) {
        size = a.size;
        if (this->data != NULL) {
            delete []this->data;
        }

        size = a.size;
        this->data = new int[a.size];
        for (int i = 0; i< size; i++) {
            this->data[i] = a.data[i];
        }
    }
    CSet operator + (const CSet& a) {
        vector<int> r;
        for (int i = 0; i < this->size; i++) {
            r.push_back(this->data[i]);
        }
        for (int i = 0; i < a.size; i++) {
            int flag = 0;
            for (int j = 0; j < r.size(); j++) {
                if (r[j] == a.data[i]) {
                    flag = 1;
                    break;
                }
            }
            if (!flag) {
                r.push_back(a.data[i]);
            }
        }

        // for (auto it : r) cout << it << "\n";

        CSet res(r.size());
        res.Set(r);
        return res;
    }
    CSet operator - (const CSet& a) {
        vector<int> r;
        for (int i = 0; i < this->size; i++) {
            int flag = 0;
            for (int j = 0; j < a.size; j++) {
                if (this->data[i] == a.data[j]) {
                    flag = 1;
                    break;
                }
            }
            if (!flag) {
                r.push_back(this->data[i]);
            }
        }

        CSet res(r.size());
        res.Set(r);
        return res;
    }
    CSet operator * (const CSet& a) {
        vector<int> r;
        for (int i = 0; i < this->size; i++) {
            for (int j = 0 ; j < a.size; j++) {
                if (this->data[i] == a.data[j]) {
                    r.push_back(a.data[j]);
                    break;
                }
            }
        }

        CSet res(r.size());
        res.Set(r);
        return res;
    }    
};

void solve() {
    int n;
    cin >> n;
    CSet a(n);
    a.set();
    cin >> n;
    CSet b(n);
    b.set();
    cout << "A:";
    a.print();
    cout << "B:";
    b.print();
    cout << "A+B:";
    CSet c = a + b;
    c.print();
    cout << "A*B:";
    c = a * b;
    c.print();
    cout << "(A-B)+(B-A):";
    c = (a - b) + (b - a);
    c.print();
    cout << "\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
	return 0;
}
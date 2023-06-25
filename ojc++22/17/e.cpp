#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

class CBook
{
private:
    string name;
    string author;
    double value;
    string origin;
public:
    CBook () {}
    CBook (string na,string au,double v,string o) {
        name = na;
        author = au;
        value = v;
        origin = o;
    }
    void operator = (const CBook& a) {
        name = a.name;
        author = a.author;
        value = a.value;
        origin = a.origin;
    }
    bool operator < (const CBook& a) {
        return value < a.value;
    }
    friend void find(CBook *book, int n, int &max1index,int &max2index) {
        max1index = 0;
        max2index = 0;

        for (int i = 0; i < n; i++) {
            if (book[max1index] < book[i]) {
                max1index = i;
            }
        }

        if (max2index == max1index) max2index ++;
        for (int i = 1; i < n; i++) {
            if (book[max2index] < book[i] && i != max1index) {
                max2index = i;
            }
        }

        return;
    }

    // friend istream &operator>> ( istream &in, CBook& a) {
    //     string s;
    //     string op[4];
    //     in >> s;
    //     // cout << s << endl;
    //     int flag = 0;
    //     int cnt = 0;
    //     for (int i = 0; i < s.size(); i++) {
    //         if (i == s.size()) {
    //             a.origin = s.substr(flag,i - flag);
    //         }
    //         if (s[i] == ',') {
    //             op[cnt++] = s.substr(flag,i - flag);
    //             flag = i + 1;
    //         }
    //     }
    //     a.name = op[0];
    //     a.author = op[1];
    //     istringstream iss(op[2]);
    //     iss >> a.value; 
    //     // cout << a.name << endl;
    //     // cout << a.author << endl;
    //     // cout << a.value << endl;
    //     // cout << a.origin << endl;

    //     return in;
    // }

    friend ostream &operator<<( ostream &out, const CBook &a) {
        out << a.name << "\n";
        out << a.author << "\n";
        out << fixed << setprecision(2) << a.value << "\n";
        out << a.origin << "\n";
        return out;
    }
};

void solve() {
    int n;
    cin >> n;

    CBook* book;
    book = new CBook[n];
    for (int i = 0; i < n; i++) {
        string name;
        getline(cin,name,',');
        // cout << name << endl;
        string author;
        
        string v;getline(cin,author,',');
        // cout << author << endl;
        getline(cin,v,',');
        istringstream iss(v);
        double va;
        iss >> va;
        // cout << va << endl;
        string origin;
        getline(cin,origin);
        // cout << origin << endl;
        book[i] = CBook(name,author,va,origin);
    }
    int mx1,mx2;
    find(book,n,mx1,mx2);

    cout << book[mx1] << "\n";
    cout << book[mx2];
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
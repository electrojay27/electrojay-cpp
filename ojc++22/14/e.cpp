#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

class CXGraph
{
private: 
    int n;
public:
    CXGraph () {};
    CXGraph (int x) : n(x) {};
    friend ostream& operator<<(ostream& out,CXGraph x);
    CXGraph& operator ++ () {
        if (n <= 19) {
            n += 2;
        }
        return *this;
    }
    CXGraph operator ++ (int) {
        CXGraph c = *this;
        if (n <= 19) {
            n ++;
            n ++;
        }
        // cout << n << "\n";
        return c;
    }
    CXGraph& operator -- () {
        if(n >= 3){
            n --;
            n --;
        }
        return *this;
    }
    CXGraph operator -- (int) {
        CXGraph c = *this;
        if(n >= 3){
            n --;
            n --;
        }
        return c;
    }
    void show(){
        for (int i = 0; i < n / 2; i++) {
            // cout << "n = " << n << "\n";
            for (int j = 0; j < n; j++) {
                // cout << j << "\n";
                if (j < n - i && j>=i) cout << 'X';
                else if(j < n - i) cout << ' ';
            }
            cout << endl;
        }
        for (int i = n / 2; i >= 0 ; i--){
            for (int j = 0; j < n; j++) {
                if (j < n - i && j >= i) cout << 'X';
                else if(j < n - i) cout << ' ';
            }
            cout << endl;
        }
    }
};
ostream& operator<<(ostream& out,CXGraph x)
{
    x.show();
    return out;
}
int main()
{
    int t, n;
    string command;
    cin >> n;
    CXGraph xGraph(n);
    cin >> t;
    while (t--)
    {
        cin >> command;
        if (command == "show++")
        {
            cout << xGraph++ << endl;
        }
        else if(command == "++show")
        {
            cout << ++xGraph << endl;
        }
        else if (command == "show--")
        {
            cout << xGraph-- << endl;
        }
        else if (command == "--show")
        {
            cout << --xGraph << endl;
        }
        else if (command == "show")
        {
            cout << xGraph << endl;
        }
    }
    return 0;
}
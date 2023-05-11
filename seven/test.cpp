#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
char a[105][105];
struct P {
    int x, y, t;
    P(int x, int y, int t) :x(x), y(y), t(t) {}
};
queue<P>p;
int w[4] = { 1,0,-1,0 }, v[4] = { 0,-1,0,1 }, T[103][105];
int main()
{
    int n, x, y, t; cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
            if (a[i][j] == 'A') {
                x = i; y = j;
            }
        } 
    }
    P e = { x,y,0 };
    p.push(e);
    while (!p.empty()) {
        P e = p.front();
        if (a[e.x][e.y] == 'B')break;
        p.pop();
        T[e.x][e.y] = 1;
        t = e.t + 1;
        for (int i = 0; i < 4; i++) {
            x = e.x + w[i]; y = e.y + v[i];
            if (T[x][y] == 0 && a[x][y] != a[e.x][e.y])p.push({ x,y,t });
        }
    }
    cout << p.front().t;
}
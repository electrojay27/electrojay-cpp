#include <iostream>
#include <iomanip>
#include <cmath>
#define eps 1e-8
double f(double x);
double xpoint(double x1, double x2);
double root(double x1, double x2);
using namespace std;
double f(double x) {
    double sum;
    sum = x * x * x - 5 * x * x + 16 * x - 80;
    return sum;
}
double xpoint(double x1, double x2) {
    double xc;
    xc = (x1 * f(x2) - x2 * f(x1)) / (f(x2) - f(x1));
    return xc;
}
double root(double x1, double x2) {
    double op = xpoint(x1, x2);
    while (fabs(f(op)) >= 0.0001){
        double op = xpoint(x1, x2);
        if (f(x1) * f(op) > 0) {
            x1 = op;
        }
        if (f(op) * f(x2) > 0) {
            x2 = op;
        }
    }
    return op;
}
int main()
{
    double x1, x2;
    for (int i = 0; i < 5; i++) {
        cin >> x1 >> x2;
        if (f(x1) * f(x2) > 0) {
            cout << "reinput:" << endl;
            continue;
        }
        else {
            cout << fixed << setprecision(6) << root(x1, x2);
            return 0;
        }
    }
    cout << "exit!";
}
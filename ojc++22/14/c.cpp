#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

class CPoint
{
private:
    int x,y;
public:
    CPoint(){};
    CPoint(int xx,int yy) {
        x = xx;
        y = yy;
    }
    
    int getX(){return x;}
    int getY(){return y;}

    bool operator == (const CPoint &a) {
        return x == a.x && y == a.y;
    }
};

class CRectangle
{
private:
    CPoint leftPoint,rightPoint;
public:
    CRectangle () {};
    CRectangle(int x1, int y1, int x2, int y2) :leftPoint(x1, y1), rightPoint(x2, y2) {};

    bool operator > (CPoint& p) {
        if (p.getX() >= leftPoint.getX() && p.getX() <= rightPoint.getX()) {
            if (p.getY() <= leftPoint.getY() && p.getY() >= rightPoint.getY()) {
                return true;
            }
        }
        return false;
    }
    bool operator > (CRectangle& p) {
        if (*this > p.leftPoint) {
            if (*this > p.rightPoint) {
                return true;
            }
        }
        return false;
    }

    bool operator == (const CRectangle &a) {
        return leftPoint == a.leftPoint && rightPoint == a.rightPoint;
    }

    bool operator *(CRectangle& a) {
        int lx = leftPoint.getX();
        int ly = leftPoint.getY();
        int rx = rightPoint.getX();
        int ry = rightPoint.getY();
        if (a.rightPoint.getY() > ly || a.rightPoint.getX() < lx || a.leftPoint.getX() > rx || a.leftPoint.getY() < ry) {
            return false;
        }
        return true;
    }

    operator int() {
        return (leftPoint.getY() - rightPoint.getY()) * (rightPoint.getX() - leftPoint.getX());
    }

    friend ostream& operator <<(ostream& a, CRectangle& b) {
        a << b.leftPoint.getX() << " " << b.leftPoint.getY() << " " << b.rightPoint.getX() << " " << b.rightPoint.getY();
        return a;
    }
};


int main()
{
    int t, x1, x2, y1, y2;
    cin >> t;
    while (t--)
    {
        // 矩形1的左上角、右下角
        cin >> x1 >> y1 >> x2 >> y2;
        CRectangle rect1(x1, y1, x2, y2);
        // 矩形2的左上角、右下角
        cin >> x1 >> y1 >> x2 >> y2;
        CRectangle rect2(x1, y1, x2, y2);
        // 输出矩形1的坐标及面积
        cout << "矩形1:" << rect1 << " " << (int)rect1 << endl;
        // 输出矩形2的坐标及面积
        cout << "矩形2:" << rect2 << " " << (int)rect2 << endl;
        if (rect1 == rect2)
        {
            cout << "矩形1和矩形2相等" << endl;
        }
        else if (rect2 > rect1)
        {
            cout << "矩形2包含矩形1" << endl;
        }
        else if (rect1 > rect2)
        {
            cout << "矩形1包含矩形2" << endl;
        }
        else if (rect1 * rect2)
        {
            cout << "矩形1和矩形2相交" << endl;
        }
        else
        {
            cout << "矩形1和矩形2不相交" << endl;
        }
        cout << endl;
    }
    return 0;
}
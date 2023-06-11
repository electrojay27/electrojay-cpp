#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

// 定义矩阵类
class CMatrix
{
private:
    int n, m; // n-行，m-列
    int** data; // 存储矩阵数据
public:
    CMatrix(){};
    CMatrix(int n1, int m1);
    ~CMatrix();

    CMatrix &operator= (const CMatrix& a) {
    	m = a.m;
    	n = a.n;

    	data = new int*[n];
    	for (int i = 0; i < n; i++) {
    		data[i] = new int[m];
    	}

    	for (int i = 0; i < n; i++) {
    		for (int j = 0; j < m; j++) {
    			data[i][j] = a.data[i][j];
    		}
    	}
    	return *this;
    }

    int* operator[] (const int x) {
    	return data[x];
    }

    int operator() (int x,int y) {
    	return data[x][y];
    }
};

CMatrix::CMatrix(int n1, int m1)
{
    n = n1;
    m = m1;
    // 分配n行m列的二维数组空间
    data = new int* [n];
    for (int i = 0; i < n; i++)
    {
        data[i] = new int[m];
    }
}

CMatrix::~CMatrix()
{
    // 释放空间
    for (int i = 0; i < n; i++)
    {
        delete[] data[i];
    }
    delete[] data;
}

int main()
{
    int t, n, m, i, j;
    cin >> t;
    while (t--)
    {
        cin >> n >> m;
        // 定义矩阵对象matrixA
        CMatrix matrixA(n, m);
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < m; j++)
            {
                // 输入第i行第j列的数据
                cin >> matrixA[i][j];
            }
        }
        // 输出matrixA中的数据
        cout << "matrixA:" << endl;
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < m; j++)
            {
                cout << matrixA(i, j) << " ";
            }
            cout << endl;
        }
        // 定义矩阵对象matrixB
        CMatrix matrixB;
        matrixB = matrixA;
        // 输出marixB中的数据
        cout << "matrixB:" << endl;
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < m; j++)
            {
                cout << matrixB[i][j] << " ";
            }
            cout << endl;
        }
    }
    return 0;
}
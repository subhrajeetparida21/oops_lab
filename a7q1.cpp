#include <iostream>
using namespace std;

class MatrixA;
class MatrixB;
class Result;

class Matrix {
protected:
    int m[3][3];
public:
    void input() {
        cout << "Enter elements of 3x3 matrix:\n";
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                cin >> m[i][j];
    }

    void display() const {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++)
                cout << m[i][j] << " ";
            cout << endl;
        }
    }

    friend Result multiply(const MatrixA&, const MatrixB&);
};

class MatrixA : public Matrix {
public:
};

class MatrixB : public Matrix {
public:
};

class Result : public Matrix {
public:
};

Result multiply(const MatrixA &a, const MatrixB &b) {
    Result res;
    cout << "\nMultiplication steps:\n";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            res.m[i][j] = 0;
            for (int k = 0; k < 3; k++) {
                cout << a.m[i][k] << " * " << b.m[k][j];
                if (k < 2) cout << " + ";
                res.m[i][j] += a.m[i][k] * b.m[k][j];
            }
            cout << " = " << res.m[i][j] << endl;
        }
        cout << endl;
    }
    return res;
}

int main() {
    MatrixA A;
    MatrixB B;

    cout << "Matrix A:\n";
    A.input();

    cout << "Matrix B:\n";
    B.input();

    cout << "\nMatrix A:\n";
    A.display();
    cout << "\nMatrix B:\n";
    B.display();

    Result R = multiply(A, B);
    cout << "\nResultant Matrix:\n";
    R.display();

    return 0;
}

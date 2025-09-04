#include <iostream>
#include <vector>
#include <stdexcept>
#include <string>
#include <complex>
using namespace std;

template <class T>
class Matrix {
    int rows, cols;
    vector<vector<T>> data;

public:
    // Default constructor
    Matrix(int r = 0, int c = 0) : rows(r), cols(c), data(r, vector<T>(c)) {}

    // Copy constructor
    Matrix(const Matrix& other) : rows(other.rows), cols(other.cols), data(other.data) {}

    // Assignment operator
    Matrix& operator=(const Matrix& other) {
        if (this != &other) {
            rows = other.rows;
            cols = other.cols;
            data = other.data;
        }
        return *this;
    }

    // Input >>
    friend istream& operator>>(istream& is, Matrix& m) {
        cout << "Enter elements (" << m.rows << "x" << m.cols << "):\n";
        for (int i = 0; i < m.rows; i++)
            for (int j = 0; j < m.cols; j++)
                is >> m.data[i][j];
        return is;
    }

    // Output <<
    friend ostream& operator<<(ostream& os, const Matrix& m) {
        for (int i = 0; i < m.rows; i++) {
            for (int j = 0; j < m.cols; j++)
                os << m.data[i][j] << " ";
            os << endl;
        }
        return os;
    }

    // Compare ==
    bool operator==(const Matrix& other) const {
        return (rows == other.rows && cols == other.cols && data == other.data);
    }

    // Invert (!) -> Transpose
    Matrix operator!() const {
        Matrix<T> trans(cols, rows);
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++)
                trans.data[j][i] = data[i][j];
        return trans;
    }

    // Subscript [] with bound check
    vector<T>& operator[](int index) {
        if (index < 0 || index >= rows)
            throw out_of_range("Row index out of range!");
        return data[index];
    }

    const vector<T>& operator[](int index) const {
        if (index < 0 || index >= rows)
            throw out_of_range("Row index out of range!");
        return data[index];
    }
};

// ---------- Example Main ----------
int main() {
    Matrix<int> A(2, 2), B(2, 2);
    cin >> A;
    cin >> B;

    cout << "Matrix A:\n" << A;
    cout << "Matrix B:\n" << B;

    cout << "A == B ? " << (A == B ? "Yes" : "No") << endl;

    cout << "Transpose of A:\n" << !A;

    try {
        cout << "Access A[1][1]: " << A[1][1] << endl;
        cout << "Access A[5][5]: " << A[5][5] << endl; // out of range
    } catch (exception& e) {
        cout << "Exception: " << e.what() << endl;
    }

    Matrix<string> S(2, 2);
    cout << "Enter 2x2 string matrix:\n";
    cin >> S;
    cout << "Matrix S:\n" << S;
    cout << "Transpose of S:\n" << !S;

    Matrix<complex<double>> C(2, 2);
    cout << "Enter 2x2 complex<double> matrix (real imag pairs):\n";
    cin >> C;
    cout << "Matrix C:\n" << C;
    cout << "Transpose of C:\n" << !C;

    return 0;
}


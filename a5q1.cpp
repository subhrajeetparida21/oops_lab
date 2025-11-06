#include <iostream>
#include <cmath>
using namespace std;

class Complex {
    double real, imag;

public:
    Complex(double r = 0.0, double i = 0.0);

    Complex operator+(const Complex& c) const;
    Complex operator-(const Complex& c) const;
    Complex operator*(const Complex& c) const;
    Complex operator/(const Complex& c) const;

    Complex operator!() const;

    bool operator==(const Complex& c) const;
    bool operator!=(const Complex& c) const;

    Complex& operator=(const Complex& c);

    double operator[](int index) const;

    operator double() const;

    friend istream& operator>>(istream& in, Complex& c);
    friend ostream& operator<<(ostream& out, const Complex& c);
};

Complex::Complex(double r, double i) {
    real = r;
    imag = i;
}

Complex Complex::operator+(const Complex& c) const {
    Complex temp;
    temp.real = real + c.real;
    temp.imag = imag + c.imag;
    return temp;
}

Complex Complex::operator-(const Complex& c) const {
    Complex temp;
    temp.real = real - c.real;
    temp.imag = imag - c.imag;
    return temp;
}

Complex Complex::operator*(const Complex& c) const {
    Complex temp;
    temp.real = (real * c.real) - (imag * c.imag);
    temp.imag = (real * c.imag) + (imag * c.real);
    return temp;
}

Complex Complex::operator/(const Complex& c) const {
    Complex temp;
    double denom = (c.real * c.real) + (c.imag * c.imag);
    temp.real = ((real * c.real) + (imag * c.imag)) / denom;
    temp.imag = ((imag * c.real) - (real * c.imag)) / denom;
    return temp;
}

Complex Complex::operator!() const {
    Complex temp;
    temp.real = real;
    temp.imag = -imag;
    return temp;
}

bool Complex::operator==(const Complex& c) const {
    bool result;
    if (real == c.real && imag == c.imag) {
        result = true;
    } else {
        result = false;
    }
    return result;
}

bool Complex::operator!=(const Complex& c) const {
    bool result;
    if (real == c.real && imag == c.imag) {
        result = false;
    } else {
        result = true;
    }
    return result;
}

Complex& Complex::operator=(const Complex& c) {
    if (this != &c) {
        real = c.real;
        imag = c.imag;
    }
    return *this;
}

double Complex::operator[](int index) const {
    double value;
    if (index == 0) {
        value = real;
    } else if (index == 1) {
        value = imag;
    } else {
        value = 0;
    }
    return value;
}

Complex::operator double() const {
    double mod = sqrt((real * real) + (imag * imag));
    return mod;
}

istream& operator>>(istream& in, Complex& c) {
    cout << "Enter real part: ";
    in >> c.real;
    cout << "Enter imaginary part: ";
    in >> c.imag;
    return in;
}

ostream& operator<<(ostream& out, const Complex& c) {
    out << c.real;
    if (c.imag >= 0) {
        out << " + " << c.imag << "i";
    } else {
        out << " - " << -c.imag << "i";
    }
    return out;
}

int main() {
    Complex c1, c2;
    cout << "Enter first complex number:\n";
    cin >> c1;
    cout << "Enter second complex number:\n";
    cin >> c2;

    cout << "\nC1 = " << c1 << "\nC2 = " << c2 << "\n";

    Complex sum = c1 + c2;
    Complex diff = c1 - c2;
    Complex prod = c1 * c2;
    Complex div = c1 / c2;
    Complex conj = !c1;

    cout << "C1 + C2 = " << sum << "\n";
    cout << "C1 - C2 = " << diff << "\n";
    cout << "C1 * C2 = " << prod << "\n";
    cout << "C1 / C2 = " << div << "\n";
    cout << "Conjugate of C1 = " << conj << "\n";

    bool eq = (c1 == c2);
    bool neq = (c1 != c2);
    cout << "C1 == C2 ? " << (eq ? "True" : "False") << "\n";
    cout << "C1 != C2 ? " << (neq ? "True" : "False") << "\n";

    cout << "Real part of C1 (C1[0]) = " << c1[0] << "\n";
    cout << "Imag part of C1 (C1[1]) = " << c1[1] << "\n";

    double mod = c1;
    cout << "Modulus of C1 = " << mod << "\n";

    return 0;
}

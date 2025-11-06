#include <iostream>
using namespace std;

class Fraction {
    int num, den;

public:
    Fraction(int n = 0, int d = 1);

    Fraction operator+(const Fraction& f) const;
    Fraction operator-(const Fraction& f) const;
    Fraction operator*(const Fraction& f) const;
    Fraction operator/(const Fraction& f) const;

    Fraction operator*() const;

    bool operator==(const Fraction& f) const;
    bool operator!=(const Fraction& f) const;
    bool operator<(const Fraction& f) const;
    bool operator>(const Fraction& f) const;

    Fraction& operator=(const Fraction& f);

    int operator[](int index) const;

    operator double() const;
    operator Fraction() const;

    friend istream& operator>>(istream& in, Fraction& f);
    friend ostream& operator<<(ostream& out, const Fraction& f);
};

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

Fraction::Fraction(int n, int d) {
    num = n;
    den = d;
}

Fraction Fraction::operator+(const Fraction& f) const {
    Fraction temp;
    temp.num = num * f.den + f.num * den;
    temp.den = den * f.den;
    return *temp;
}

Fraction Fraction::operator-(const Fraction& f) const {
    Fraction temp;
    temp.num = num * f.den - f.num * den;
    temp.den = den * f.den;
    return temp;
}

Fraction Fraction::operator*(const Fraction& f) const {
    Fraction temp;
    temp.num = num * f.num;
    temp.den = den * f.den;
    return temp;
}

Fraction Fraction::operator/(const Fraction& f) const {
    Fraction temp;
    temp.num = num * f.den;
    temp.den = den * f.num;
    return temp;
}

Fraction Fraction::operator*() const {
    Fraction temp(num, den);
    int g = gcd(temp.num, temp.den);
    temp.num = temp.num / g;
    temp.den = temp.den / g;
    return temp;
}

bool Fraction::operator==(const Fraction& f) const {
    bool result;
    if (num * f.den == den * f.num) result = true;
    else result = false;
    return result;
}

bool Fraction::operator!=(const Fraction& f) const {
    bool result;
    if (num * f.den == den * f.num) result = false;
    else result = true;
    return result;
}

bool Fraction::operator<(const Fraction& f) const {
    bool result;
    if (num * f.den < den * f.num) result = true;
    else result = false;
    return result;
}

bool Fraction::operator>(const Fraction& f) const {
    bool result;
    if (num * f.den > den * f.num) result = true;
    else result = false;
    return result;
}

Fraction& Fraction::operator=(const Fraction& f) {
    if (this != &f) {
        num = f.num;
        den = f.den;
    }
    return *this;
}

int Fraction::operator[](int index) const {
    int value;
    if (index == 0) value = num;
    else if (index == 1) value = den;
    else value = 0;
    return value;
}

Fraction::operator double() const {
    double value = (double)num / den;
    return value;
}

Fraction::operator Fraction() const {
    return *this;
}

istream& operator>>(istream& in, Fraction& f) {
    cout << "Enter numerator: ";
    in >> f.num;
    cout << "Enter denominator: ";
    in >> f.den;
    return in;
}

ostream& operator<<(ostream& out, const Fraction& f) {
    out << f.num << "/" << f.den;
    return out;
}

int main() {
    Fraction f1, f2;
    cout << "Enter first fraction:\n";
    cin >> f1;
    cout << "Enter second fraction:\n";
    cin >> f2;

    Fraction sum = f1 + f2;
    Fraction diff = f1 - f2;
    Fraction prod = f1 * f2;
    Fraction div = f1 / f2;
    Fraction norm = *f1;

    cout << "f1 = " << f1 << "\n";
    cout << "f2 = " << f2 << "\n";
    cout << "f1 + f2 = " << sum << "\n";
    cout << "f1 - f2 = " << diff << "\n";
    cout << "f1 * f2 = " << prod << "\n";
    cout << "f1 / f2 = " << div << "\n";
    cout << "Normalized f1 = " << norm << "\n";
    cout << "Numerator of f1 = " << f1[0] << "\n";
    cout << "Denominator of f1 = " << f1[1] << "\n";
    cout << "f1 as double = " << double(f1) << "\n";

    return 0;
}

#include <iostream>
#include <stdexcept>
using namespace std;

class Fraction {
private:
    int num;
    int denom;
public:
    Fraction();
    Fraction(int num, int denom);
    Fraction& operator*();
    friend istream& operator>>(istream &in, Fraction &f);
    friend ostream& operator<<(ostream &out, const Fraction &f);
};

Fraction::Fraction() : num(0), denom(1) {}

Fraction::Fraction(int num, int denom) {
    if (denom == 0) throw runtime_error("Denominator cannot be zero.");
    this->num = num;
    this->denom = denom;
}

int gcd(int a, int b) {
    while(b != 0) {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

Fraction& Fraction::operator*() {
    if(num == 0) throw runtime_error("Numerator cannot be zero");
    int divisor = gcd(abs(num), abs(denom));
    num /= divisor;
    denom /= divisor;
    return *this;
}

ostream& operator<<(ostream &out, const Fraction &f) {
    out << f.num << "/" << f.denom;
    return out;
}

istream& operator>>(istream &in, Fraction &f) {
    cout<<"Enter the numerator followed by denominator :"<<endl;
    in >> f.num >> f.denom;
    if(f.denom == 0) throw runtime_error("Denominator cannot be zero.");
    if(f.num == 0) throw runtime_error("Numerator cannot be zero.");
    return in;
}

int main() {
    try {
        Fraction f1;
        cin >> f1;
        cout << f1 << endl;
        *f1;
        cout << f1 << endl;
    } catch(exception &e) {
        cout << e.what() << endl;
    }
}

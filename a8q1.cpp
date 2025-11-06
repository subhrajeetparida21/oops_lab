#include <iostream>
#include <cassert>
#include <cmath>
using namespace std;

class Complex
{
private:
    double real;
    double img;

public:
    Complex();
    Complex(double real, double img);
    bool operator>=(Complex obj);
    bool operator!=(Complex obj);
    double operator[](int pos);
    ~Complex();
};

Complex::Complex()
{
    this->real = 0;
    this->img = 0;
}

Complex::Complex(double real, double img)
{
    this->real = real;
    this->img = img;
}

bool Complex::operator>=(Complex obj)
{
    assert(!(real == obj.real && img == obj.img) && "Both complex numbers are same!");
    double mag1 = sqrt(real * real + img * img);
    double mag2 = sqrt(obj.real * obj.real + obj.img * obj.img);
    return mag1 >= mag2;
}

bool Complex::operator!=(Complex obj)
{
    assert(!(real == obj.real && img == obj.img) && "Both complex numbers are same!");
    return (real != obj.real || img != obj.img);
}

double Complex::operator[](int pos)
{
    assert(!(real == 0 || img == 0) && "Cannot subscript: real or imaginary part is zero!");
    if (pos == 0)
        return real;
    else if (pos == 1)
        return img;
    else
    {
        cout << "Invalid index! Use [0] for real, [1] for imaginary." << endl;
        exit(1);
    }
}

Complex::~Complex() {}

int main()
{
    Complex c1(12.44, 66.11);
    Complex c2(22.12, 67.00);

    if (c2 >= c1)
        cout << "c2 is greater than or equal to c1 based on magnitude." << endl;
    else
        cout << "c2 is smaller than c1 based on magnitude." << endl;

    if (c1 != c2)
        cout << "c1 and c2 are not equal." << endl;
    else
        cout << "c1 and c2 are equal." << endl;

    cout << "Real part of c2: " << c2[0] << endl;
    cout << "Imaginary part of c2: " << c2[1] << endl;

    return 0;
}

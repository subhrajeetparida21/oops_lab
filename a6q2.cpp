#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

template<typename T>
class Set {
    vector<T> set;
    void removeduplicates();
public:
    Set();
    Set(vector<T> &set);
    Set(const Set &other); // fixed: const reference
    Set<T> operator+(Set<T> &other);
    Set<T> operator-(Set<T> &other);
    Set<T> operator*(Set<T> &other);
    bool operator<=(Set<T>& other);
    bool operator<(Set<T>& other);
    bool operator>=(Set<T>& other);
    bool operator>(Set<T>& other);
    bool operator==(Set<T>& other);
    bool operator!=(Set<T>& other);
    template<typename U> friend ostream& operator<<(ostream& out, const Set<U> &s);
    template<typename U> friend istream& operator>>(istream& in, Set<U> &s);
};

template<typename T>
void Set<T>::removeduplicates() {
    sort(set.begin(), set.end());
    set.erase(unique(set.begin(), set.end()), set.end());
}

template<typename T>
Set<T>::Set() {}

template<typename T>
Set<T>::Set(vector<T> &set) {
    this->set = set;
    removeduplicates();
}

template<typename T>
Set<T>::Set(const Set &other) { // fixed copy constructor
    this->set = other.set;
}

template<typename T>
Set<T> Set<T>::operator+(Set<T> &other) {
    Set result = *this;
    result.set.insert(result.set.end(), other.set.begin(), other.set.end());
    result.removeduplicates();
    return result;
}

template<typename T>
Set<T> Set<T>::operator-(Set<T> &other) {
    Set result = *this;
    for (auto it = other.set.begin(); it != other.set.end(); ++it) {
        for (int i = result.set.size() - 1; i >= 0; --i) {
            if (result.set[i] == *it)
                result.set.erase(result.set.begin() + i);
        }
    }
    return result;
}

template<typename T>
Set<T> Set<T>::operator*(Set<T> &other) {
    Set result;
    for (auto it = other.set.begin(); it != other.set.end(); ++it) {
        bool b = false;
        for (auto i = this->set.begin(); i != this->set.end(); ++i) {
            if (*i == *it) {
                b = true;
                break;
            }
        }
        if (b) result.set.push_back(*it);
    }
    result.removeduplicates();
    return result;
}

template<typename T>
bool Set<T>::operator<=(Set<T> &other) {
    for (auto it = this->set.begin(); it != this->set.end(); ++it) {
        if (find(other.set.begin(), other.set.end(), *it) == other.set.end())
            return false;
    }
    return true;
}

template<typename T>
bool Set<T>::operator<(Set<T> &other) {
    if (this->set == other.set) return false;
    for (auto it = this->set.begin(); it != this->set.end(); ++it) {
        if (find(other.set.begin(), other.set.end(), *it) == other.set.end())
            return false;
    }
    return true;
}

template<typename T>
bool Set<T>::operator>=(Set<T> &other) {
    for (const auto &x : other.set) {
        if (find(this->set.begin(), this->set.end(), x) == this->set.end())
            return false;
    }
    return true;
}

template<typename T>
bool Set<T>::operator>(Set<T> &other) {
    if (this->set == other.set) return false;
    for (const auto &x : other.set) {
        if (find(this->set.begin(), this->set.end(), x) == this->set.end())
            return false;
    }
    return true;
}

template<typename T>
bool Set<T>::operator==(Set<T> &other) {
    return this->set == other.set;
}

template<typename T>
bool Set<T>::operator!=(Set<T> &other) {
    return this->set != other.set;
}

template<typename U>
ostream& operator<<(ostream& out, const Set<U> &s) {
    out << "{ ";
    for (U x : s.set) out << x << " ";
    out << "}";
    return out;
}

template<typename U>
istream& operator>>(istream& in, Set<U> &s) {
    int n;
    cout << "Enter number of elements: ";
    in >> n;
    s.set.resize(n);
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) in >> s.set[i];
    s.removeduplicates();
    return in;
}

class Complex {
public:
    double real, imag;
    Complex(double r = 0, double i = 0);
    bool operator==(const Complex& c) const;
    friend istream& operator>>(istream& in, Complex& c);
    friend ostream& operator<<(ostream& out, const Complex& c);
    bool operator<(const Complex &other) const {
        if (real != other.real) return real < other.real;
        return imag < other.imag;
    }
};

Complex::Complex(double r, double i) : real(r), imag(i) {}
bool Complex::operator==(const Complex& c) const { return real == c.real && imag == c.imag; }

istream& operator>>(istream& in, Complex& c) {
    cout << "Enter real and imaginary parts: ";
    in >> c.real >> c.imag;
    return in;
}

ostream& operator<<(ostream& out, const Complex& c) {
    out << "(" << c.real << " + " << c.imag << "i)";
    return out;
}

template<typename T>
void menu() {
    Set<T> set1, set2;
    int choice;
    cout << "\n--- Set Operations Menu ---\n"
         << "1. Input Set 1\n"
         << "2. Input Set 2\n"
         << "3. Display Sets\n"
         << "4. Union (Set1 + Set2)\n"
         << "5. Intersection (Set1 * Set2)\n"
         << "6. Difference (Set1 - Set2)\n"
         << "7. Subset Check (Set1 <= Set2)\n"
         << "8. Strict Subset Check (Set1 < Set2)\n"
         << "9. Superset Check (Set1 >= Set2)\n"
         << "10. Strict Superset Check (Set1 > Set2)\n"
         << "11. Equality Check (Set1 == Set2)\n"
         << "12. Inequality Check (Set1 != Set2)\n"
         << "0. Exit\n";
    do {
        cout << "\nEnter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1: cin >> set1; break;
            case 2: cin >> set2; break;
            case 3: cout << "Set 1: " << set1 << "\nSet 2: " << set2 << endl; break;
            case 4: cout << "Union: " << (set1 + set2) << endl; break;
            case 5: cout << "Intersection: " << (set1 * set2) << endl; break;
            case 6: cout << "Difference (Set1 - Set2): " << (set1 - set2) << endl; break;
            case 7: cout << (set1 <= set2 ? "Set1 is subset of Set2" : "Set1 is not subset of Set2") << endl; break;
            case 8: cout << (set1 < set2 ? "Set1 is strict subset of Set2" : "Set1 is not strict subset of Set2") << endl; break;
            case 9: cout << (set1 >= set2 ? "Set1 is superset of Set2" : "Set1 is not superset of Set2") << endl; break;
            case 10: cout << (set1 > set2 ? "Set1 is strict superset of Set2" : "Set1 is not strict superset of Set2") << endl; break;
            case 11: cout << (set1 == set2 ? "Set1 equals Set2" : "Set1 does not equal Set2") << endl; break;
            case 12: cout << (set1 != set2 ? "Set1 not equal to Set2" : "Set1 equals Set2") << endl; break;
            case 0: cout << "Exiting menu.\n"; break;
            default: cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 0);
}

int main() {
    int typeChoice;
    cout << "Select the type of set:\n";
    cout << "1. Integer\n2. String\n3. Complex\n";
    cout << "Enter choice: ";
    cin >> typeChoice;
    switch (typeChoice) {
        case 1: menu<int>(); break;
        case 2: menu<string>(); break;
        case 3: menu<Complex>(); break;
        default: cout << "Invalid type choice.\n"; return 0;
    }
    return 0;
}

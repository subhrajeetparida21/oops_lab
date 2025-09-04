#include <iostream>
#include <vector>
#include <algorithm>
#include <complex>
#include <string>
using namespace std;

template <class T>
class Set {
    vector<T> elements;

    void makeUnique() {
        sort(elements.begin(), elements.end());
        elements.erase(unique(elements.begin(), elements.end()), elements.end());
    }

public:
    // Default constructor
    Set() {}

    // Copy constructor
    Set(const Set& other) : elements(other.elements) {}

    // Assignment operator
    Set& operator=(const Set& other) {
        if (this != &other) {
            elements = other.elements;
        }
        return *this;
    }

    // Insert element
    void insert(const T& val) {
        elements.push_back(val);
        makeUnique();
    }

    // Union (+)
    Set operator+(const Set& other) const {
        Set<T> result = *this;
        result.elements.insert(result.elements.end(), other.elements.begin(), other.elements.end());
        result.makeUnique();
        return result;
    }

    // Difference (-)
    Set operator-(const Set& other) const {
        Set<T> result;
        for (auto& x : elements) {
            if (find(other.elements.begin(), other.elements.end(), x) == other.elements.end())
                result.insert(x);
        }
        return result;
    }

    // Intersection (*)
    Set operator*(const Set& other) const {
        Set<T> result;
        for (auto& x : elements) {
            if (find(other.elements.begin(), other.elements.end(), x) != other.elements.end())
                result.insert(x);
        }
        return result;
    }

    // Subset (<, <=)
    bool operator<=(const Set& other) const {
        for (auto& x : elements) {
            if (find(other.elements.begin(), other.elements.end(), x) == other.elements.end())
                return false;
        }
        return true;
    }
    bool operator<(const Set& other) const {
        return (*this <= other) && (elements.size() < other.elements.size());
    }

    // Superset (>, >=)
    bool operator>=(const Set& other) const { return (other <= *this); }
    bool operator>(const Set& other) const { return (other < *this); }

    // Compare (==, !=)
    bool operator==(const Set& other) const { return elements == other.elements; }
    bool operator!=(const Set& other) const { return !(*this == other); }

    // Output <<
    friend ostream& operator<<(ostream& os, const Set& s) {
        os << "{ ";
        for (auto& x : s.elements) os << x << " ";
        os << "}";
        return os;
    }

    // Input >>
    friend istream& operator>>(istream& is, Set& s) {
        int n;
        cout << "Enter number of elements: ";
        is >> n;
        s.elements.clear();
        for (int i = 0; i < n; i++) {
            T val;
            cout << "Enter value " << i + 1 << ": ";
            is >> val;
            s.insert(val);
        }
        return is;
    }
};

// ---------- Example Main ----------
int main() {
    Set<int> A, B;
    cin >> A;
    cin >> B;

    cout << "A = " << A << endl;
    cout << "B = " << B << endl;

    cout << "Union (A + B): " << (A + B) << endl;
    cout << "Difference (A - B): " << (A - B) << endl;
    cout << "Intersection (A * B): " << (A * B) << endl;
    cout << "A subset B ? " << ((A <= B) ? "Yes" : "No") << endl;
    cout << "A superset B ? " << ((A >= B) ? "Yes" : "No") << endl;

    Set<string> S1, S2;
    S1.insert("apple"); S1.insert("banana");
    S2.insert("banana"); S2.insert("cherry");
    cout << "S1 = " << S1 << endl;
    cout << "S2 = " << S2 << endl;
    cout << "S1 * S2 = " << (S1 * S2) << endl;

    Set<complex<double>> C1, C2;
    C1.insert({1.1, 2.2});
    C1.insert({3.3, 4.4});
    C2.insert({3.3, 4.4});
    C2.insert({5.5, 6.6});
    cout << "C1 = " << C1 << endl;
    cout << "C2 = " << C2 << endl;
    cout << "C1 + C2 = " << (C1 + C2) << endl;

    return 0;
}

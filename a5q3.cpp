#include <iostream>
#include <vector>
using namespace std;

class Set {
    vector<int> elements;

public:
    Set();
    Set(const Set& s);

    Set operator+(const Set& s) const;
    Set operator-(const Set& s) const;
    Set operator*(const Set& s) const;

    bool operator<(const Set& s) const;
    bool operator<=(const Set& s) const;
    bool operator>(const Set& s) const;
    bool operator>=(const Set& s) const;

    bool operator==(const Set& s) const;
    bool operator!=(const Set& s) const;

    Set& operator=(const Set& s);

    friend istream& operator>>(istream& in, Set& s);
    friend ostream& operator<<(ostream& out, const Set& s);
};

Set::Set() {}

Set::Set(const Set& s) {
    elements = s.elements;
}

Set Set::operator+(const Set& s) const {
    Set temp;
    temp.elements = elements;
    for (int x : s.elements) {
        bool found = false;
        for (int y : temp.elements) {
            if (x == y) {
                found = true;
                break;
            }
        }
        if (!found) {
            temp.elements.push_back(x);
        }
    }
    return temp;
}

Set Set::operator-(const Set& s) const {
    Set temp;
    for (int x : elements) {
        bool found = false;
        for (int y : s.elements) {
            if (x == y) {
                found = true;
                break;
            }
        }
        if (!found) {
            temp.elements.push_back(x);
        }
    }
    return temp;
}

Set Set::operator*(const Set& s) const {
    Set temp;
    for (int x : elements) {
        bool found = false;
        for (int y : s.elements) {
            if (x == y) {
                found = true;
                break;
            }
        }
        if (found) {
            temp.elements.push_back(x);
        }
    }
    return temp;
}

bool Set::operator<(const Set& s) const {
    bool result = true;
    for (int x : elements) {
        bool found = false;
        for (int y : s.elements) {
            if (x == y) {
                found = true;
                break;
            }
        }
        if (!found) {
            result = false;
            break;
        }
    }
    return result;
}

bool Set::operator<=(const Set& s) const {
    bool result = true;
    for (int x : elements) {
        bool found = false;
        for (int y : s.elements) {
            if (x == y) {
                found = true;
                break;
            }
        }
        if (!found) {
            result = false;
            break;
        }
    }
    return result;
}

bool Set::operator>(const Set& s) const {
    bool result = true;
    for (int x : s.elements) {
        bool found = false;
        for (int y : elements) {
            if (x == y) {
                found = true;
                break;
            }
        }
        if (!found) {
            result = false;
            break;
        }
    }
    return result;
}

bool Set::operator>=(const Set& s) const {
    bool result = true;
    for (int x : s.elements) {
        bool found = false;
        for (int y : elements) {
            if (x == y) {
                found = true;
                break;
            }
        }
        if (!found) {
            result = false;
            break;
        }
    }
    return result;
}

bool Set::operator==(const Set& s) const {
    bool result = true;
    if (elements.size() != s.elements.size()) {
        result = false;
    } else {
        for (int x : elements) {
            bool found = false;
            for (int y : s.elements) {
                if (x == y) {
                    found = true;
                    break;
                }
            }
            if (!found) {
                result = false;
                break;
            }
        }
    }
    return result;
}

bool Set::operator!=(const Set& s) const {
    bool result;
    if (*this == s) {
        result = false;
    } else {
        result = true;
    }
    return result;
}

Set& Set::operator=(const Set& s) {
    if (this != &s) {
        elements = s.elements;
    }
    return *this;
}

istream& operator>>(istream& in, Set& s) {
    int n;
    cout << "Enter number of elements: ";
    in >> n;
    s.elements.clear();
    for (int i = 0; i < n; i++) {
        int val;
        in >> val;
        bool found = false;
        for (int x : s.elements) {
            if (x == val) {
                found = true;
                break;
            }
        }
        if (!found) {
            s.elements.push_back(val);
        }
    }
    return in;
}

ostream& operator<<(ostream& out, const Set& s) {
    out << "{ ";
    for (int i = 0; i < s.elements.size(); i++) {
        out << s.elements[i];
        if (i != s.elements.size() - 1) out << ", ";
    }
    out << " }";
    return out;
}

int main() {
    Set s1, s2;
    cout << "Enter first set:\n";
    cin >> s1;
    cout << "Enter second set:\n";
    cin >> s2;

    Set uni = s1 + s2;
    Set diff = s1 - s2;
    Set inter = s1 * s2;

    cout << "s1 = " << s1 << "\n";
    cout << "s2 = " << s2 << "\n";
    cout << "s1 U s2 = " << uni << "\n";
    cout << "s1 - s2 = " << diff << "\n";
    cout << "s1 ∩ s2 = " << inter << "\n";

    bool eq = (s1 == s2);
    bool neq = (s1 != s2);
    bool sub = (s1 < s2);
    bool sup = (s1 > s2);

    cout << "s1 == s2 ? " << (eq ? "True" : "False") << "\n";
    cout << "s1 != s2 ? " << (neq ? "True" : "False") << "\n";
    cout << "s1 < s2 ? " << (sub ? "True" : "False") << "\n";
    cout << "s1 > s2 ? " << (sup ? "True" : "False") << "\n";

    return 0;
}

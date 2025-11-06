#include <iostream>
#include <cstring>
#include <limits>
using namespace std;

class MyString {
    char* str;
    int len;
public:
    MyString();
    MyString(const char* s);
    MyString(const MyString &s);
    ~MyString();
    MyString operator+(const MyString &s);
    MyString operator!();
    bool operator==(const MyString &s);
    MyString& operator=(const MyString &s);
    char& operator[](int index);
    friend istream& operator>>(istream &in, MyString &s);
    friend ostream& operator<<(ostream &out, const MyString &s);
};

MyString::MyString() {
    str = nullptr;
    len = 0;
}

MyString::MyString(const char* s) {
    len = strlen(s);
    str = new char[len + 1];
    strcpy(str, s);
}

MyString::MyString(const MyString &s) {
    len = s.len;
    str = new char[len + 1];
    strcpy(str, s.str);
}

MyString::~MyString() {
    delete[] str;
}

MyString MyString::operator+(const MyString &s) {
    MyString temp;
    temp.len = len + s.len;
    temp.str = new char[temp.len + 1];
    strcpy(temp.str, str);
    strcat(temp.str, s.str);
    return temp;
}

MyString MyString::operator!() {
    MyString temp;
    temp.len = len;
    temp.str = new char[len + 1];
    for (int i = 0; i < len; i++) {
        temp.str[i] = str[len - 1 - i];
    }
    temp.str[len] = '\0';
    return temp;
}

bool MyString::operator==(const MyString &s) {
    return strcmp(str, s.str) == 0;
}

MyString& MyString::operator=(const MyString &s) {
    if (this != &s) {
        delete[] str;
        len = s.len;
        str = new char[len + 1];
        strcpy(str, s.str);
    }
    return *this;
}

char& MyString::operator[](int index) {
    if (index < 0 || index >= len) {
        cout << "Index out of bounds" << endl;
        static char dummy = '\0';
        return dummy;
    }
    return str[index];
}

istream& operator>>(istream &in, MyString &s) {
    char buffer[1000];
    in.ignore(numeric_limits<streamsize>::max(), '\n'); // flush newline
    in.getline(buffer, 1000);
    s.len = strlen(buffer);
    delete[] s.str;
    s.str = new char[s.len + 1];
    strcpy(s.str, buffer);
    return in;
}

ostream& operator<<(ostream &out, const MyString &s) {
    out << s.str;
    return out;
}

int main() {
    MyString s1, s2, s3;

    cout << "Enter first string: ";
    cin >> s1;

    cout << "Enter second string: ";
    cin >> s2;

    s3 = s1 + s2;
    cout << "\nConcatenated string: " << s3 << endl;

    s3 = !s1;
    cout << "Reversed first string: " << s3 << endl;

    if (s1 == s2) cout << "Both strings are equal." << endl;
    else cout << "Strings are not equal." << endl;

    cout << "\nAccessing characters from first string:" << endl;
    cout << "s1[1] = " << s1[1] << endl;
    cout << "s1[20] = " << s1[20] << endl;

    return 0;
}


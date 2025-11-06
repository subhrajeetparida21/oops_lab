#include <iostream>
#include <cstring>
#include <stdexcept>
using namespace std;

class MyString
{
    char* str;

public:
    MyString()
    {
        str = nullptr;
    }

    MyString(const char* s)
    {
        if (s == nullptr)
            throw runtime_error("Improper memory allocation");
        str = new char[strlen(s) + 1];
        strcpy(str, s);
    }

    MyString(const MyString& s)
    {
        str = new char[strlen(s.str) + 1];
        strcpy(str, s.str);
    }

    MyString operator+(const MyString& s)
    {
        MyString temp;
        temp.str = new char[strlen(str) + strlen(s.str) + 1];
        strcpy(temp.str, str);
        strcat(temp.str, s.str);
        return temp;
    }

    MyString operator!()
    {
        MyString temp;
        int len = strlen(str);
        temp.str = new char[len + 1];
        for (int i = 0; i < len; i++)
            temp.str[i] = str[len - i - 1];
        temp.str[len] = '\0';
        return temp;
    }

    void display()
    {
        try
        {
            if (str == nullptr || strlen(str) == 0)
                throw runtime_error("Empty string cannot be displayed");

            for (int i = 0; i < strlen(str); i++)
            {
                if (str[i] == ' ')
                    throw runtime_error("String contains blank space");
            }

            bool palindrome = true;
            int len = strlen(str);
            for (int i = 0; i < len / 2; i++)
            {
                if (str[i] != str[len - i - 1])
                {
                    palindrome = false;
                    break;
                }
            }

            if (palindrome)
                throw runtime_error("String is palindrome");

            cout << "String: " << str << endl;
        }
        catch (runtime_error& e)
        {
            cout << "Exception: " << e.what() << endl;
        }
    }

    ~MyString()
    {
        delete[] str;
    }
};

int main()
{
    try
    {
        MyString s1("hello");
        MyString s2("world");

        MyString s3 = s1 + s2;
        cout << "After concatenation: ";
        s3.display();

        MyString s4 = !s1;
        cout << "Reversed string: ";
        s4.display();

        MyString s5("madam");
        cout << "Palindrome test: ";
        s5.display();

        MyString s6("with space");
        cout << "Blank space test: ";
        s6.display();

        MyString s7("");
        cout << "Empty string test: ";
        s7.display();
    }
    catch (bad_alloc&)
    {
        cout << "Memory allocation failed" << endl;
    }

    return 0;
}

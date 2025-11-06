#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>
using namespace std;

class Set
{
private:
    vector<string> elements;

public:
    Set(vector<string> elems)
    {
        if (elems.empty())
            throw invalid_argument(" Null Set Exception: Set cannot be empty.");

        for (size_t i = 0; i < elems.size(); i++)
        {
            for (size_t j = i + 1; j < elems.size(); j++)
            {
                if (elems[i] == elems[j])
                    throw invalid_argument(" Duplicate Element Exception: Set cannot have duplicate elements.");
            }
        }
        elements = elems;
    }

    Set(const Set &s)
    {
        elements = s.elements;
    }

    bool operator<(const Set &s) const
    {
        if (elements.size() >= s.elements.size())
            return false;

        for (auto &x : elements)
        {
            bool found = false;
            for (auto &y : s.elements)
            {
                if (x == y)
                {
                    found = true;
                    break;
                }
            }
            if (!found)
                return false;
        }
        return true;
    }

    bool operator<=(const Set &s) const
    {
        for (auto &x : elements)
        {
            bool found = false;
            for (auto &y : s.elements)
            {
                if (x == y)
                {
                    found = true;
                    break;
                }
            }
            if (!found)
                return false;
        }
        return true;
    }

    bool operator>(const Set &s) const
    {
        if (elements.size() <= s.elements.size())
            return false;

        for (auto &x : s.elements)
        {
            bool found = false;
            for (auto &y : elements)
            {
                if (x == y)
                {
                    found = true;
                    break;
                }
            }
            if (!found)
                return false;
        }
        return true;
    }

    bool operator>=(const Set &s) const
    {
        for (auto &x : s.elements)
        {
            bool found = false;
            for (auto &y : elements)
            {
                if (x == y)
                {
                    found = true;
                    break;
                }
            }
            if (!found)
                return false;
        }
        return true;
    }

    void display() const
    {
        cout << "{ ";
        for (auto &x : elements)
            cout << x << " ";
        cout << "}";
    }
};

int main()
{
    try
    {
        int n1, n2, choice;

        cout << "Enter number of elements in Set A: ";
        cin >> n1;
        vector<string> A;
        cout << "Enter elements of Set A:\n";
        for (int i = 0; i < n1; i++)
        {
            string temp;
            cin >> temp;
            A.push_back(temp);
        }

        cout << "\nEnter number of elements in Set B: ";
        cin >> n2;
        vector<string> B;
        cout << "Enter elements of Set B:\n";
        for (int i = 0; i < n2; i++)
        {
            string temp;
            cin >> temp;
            B.push_back(temp);
        }

        Set setA(A);
        Set setB(B);
        Set copyA(setA);

        cout << "Set A = ";
        setA.display();
        cout << "\nSet B = ";
        setB.display();
        cout << "\nCopy of A = ";
        copyA.display();

        cout << "\nChoose an operation to perform:\n";
        cout << "1. Check if A is a proper subset of B\n";
        cout << "2. Check if A is a subset of B\n";
        cout << "3. Check if A is a proper superset of B\n";
        cout << "4. Check if A is a superset of B\n";
        cout << "5. Check if A and B are equal\n";
        cout << "6. Check if A and B are unrelated\n";
        cout << "Enter your choice (1-6): ";
        cin >> choice;

        cout << "\nResult: ";
        switch (choice)
        {
        case 1:
            cout << (setA < setB ? "A is a proper subset of B\n" : " A is NOT a proper subset of B\n");
            break;
        case 2:
            cout << (setA <= setB ? "A is a subset of B\n" : " A is NOT a subset of B\n");
            break;
        case 3:
            cout << (setA > setB ? "A is a proper superset of B\n" : " A is NOT a proper superset of B\n");
            break;
        case 4:
            cout << (setA >= setB ? "A is a superset of B\n" : " A is NOT a superset of B\n");
            break;
        case 5:
            if (setA <= setB && setA >= setB)
                cout << "A and B are equal sets\n";
            else
                cout << "A and B are NOT equal\n";
            break;
        case 6:
            if (!(setA <= setB) && !(setA >= setB))
                cout << " A and B are unrelated (no subset/superset relation)\n";
            else
                cout << " A and B have some subset relation\n";
            break;
        default:
            cout << " Invalid choice.\n";
        }
    }
    catch (const exception &e)
    {
        cout << "\n Exception caught: " << e.what() << endl;
    }

    return 0;
}

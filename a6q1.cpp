#include <iostream>
#include <string>
#include <complex>
using namespace std;

template <class T>
class Stack {
    struct Node {
        T data;
        Node* next;
        Node(const T& d, Node* n = nullptr) : data(d), next(n) {}
    };

    Node* top;

public:
    // Default constructor
    Stack() : top(nullptr) {}

    // Copy constructor
    Stack(const Stack& other) : top(nullptr) {
        if (other.top) {
            Node* temp = other.top;
            Stack<T> tempStack;
            while (temp) {
                tempStack.push(temp->data);
                temp = temp->next;
            }
            temp = tempStack.top;
            while (temp) {
                push(temp->data);
                temp = temp->next;
            }
        }
    }

    // Destructor
    ~Stack() {
        while (!isEmpty()) pop();
    }

    // Assignment operator
    Stack& operator=(const Stack& other) {
        if (this != &other) {
            while (!isEmpty()) pop();
            Stack<T> temp(other);
            Node* cur = temp.top;
            while (cur) {
                push(cur->data);
                cur = cur->next;
            }
        }
        return *this;
    }

    // Push element
    void push(const T& value) {
        top = new Node(value, top);
    }

    // Pop element
    void pop() {
        if (!isEmpty()) {
            Node* temp = top;
            top = top->next;
            delete temp;
        }
    }

    // Peek top
    T peek() const {
        if (!isEmpty()) return top->data;
        throw runtime_error("Stack empty");
    }

    // Check empty
    bool isEmpty() const {
        return top == nullptr;
    }

    // Compare ==
    bool operator==(const Stack& other) const {
        Node* a = top;
        Node* b = other.top;
        while (a && b) {
            if (a->data != b->data) return false;
            a = a->next;
            b = b->next;
        }
        return a == nullptr && b == nullptr;
    }

    // Reverse (!)
    Stack operator!() const {
        Stack<T> rev;
        Node* cur = top;
        while (cur) {
            rev.push(cur->data);
            cur = cur->next;
        }
        return rev;
    }

    // Output <<
    friend ostream& operator<<(ostream& os, const Stack& s) {
        Node* cur = s.top;
        os << "[ ";
        while (cur) {
            os << cur->data << " ";
            cur = cur->next;
        }
        os << "]";
        return os;
    }

    // Input >>
    friend istream& operator>>(istream& is, Stack& s) {
        int n;
        cout << "Enter number of elements: ";
        is >> n;
        for (int i = 0; i < n; i++) {
            T val;
            cout << "Enter value " << i + 1 << ": ";
            is >> val;
            s.push(val);
        }
        return is;
    }
};

// ---------- Example Main ----------
int main() {
    Stack<int> s1;
    cin >> s1;
    cout << "Stack s1: " << s1 << endl;

    Stack<int> s2 = s1;  // copy constructor
    cout << "Copied Stack s2: " << s2 << endl;

    cout << "s1 == s2 ? " << (s1 == s2 ? "Yes" : "No") << endl;

    Stack<int> s3 = !s1; // reverse
    cout << "Reversed Stack s3: " << s3 << endl;

    Stack<string> s4;
    s4.push("Hello");
    s4.push("World");
    cout << "Stack of strings: " << s4 << endl;

    Stack<complex<double>> s5;
    s5.push({2.3, 4.5});
    s5.push({1.1, -3.2});
    cout << "Stack of complex numbers: " << s5 << endl;

    return 0;
}

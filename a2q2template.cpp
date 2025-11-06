#include <iostream>
using namespace std;

template <typename T>
class Stack {
    T arr[100];
    int top;
public:
    Stack() { top = -1; }
    void push(T value) {
        if (top == 99) cout << "\nStack Overflow";
        else arr[++top] = value;
    }
    void pop() {
        if (top == -1) cout << "\nStack Underflow";
        else top--;
    }
    void display() {
        cout << "\nStack: ";
        for (int i = top; i >= 0; i--) cout << arr[i] << " ";
    }
};

int main() {
    int choice, type;
    cout << "Select Data Type:\n1. int\n2. float\n3. double\n4. char\n";
    cin >> type;

    switch (type) {
        case 1: {
            Stack<int> s;
            do {
                cout << "\n1. Push\n2. Pop\n3. Display\n4. Exit\n";
                cin >> choice;
                if (choice == 1) { int val; cin >> val; s.push(val); }
                else if (choice == 2) s.pop();
                else if (choice == 3) s.display();
            } while (choice != 4);
            break;
        }
        case 2: {
            Stack<float> s;
            do {
                cout << "\n1. Push\n2. Pop\n3. Display\n4. Exit\n";
                cin >> choice;
                if (choice == 1) { float val; cin >> val; s.push(val); }
                else if (choice == 2) s.pop();
                else if (choice == 3) s.display();
            } while (choice != 4);
            break;
        }
        case 3: {
            Stack<double> s;
            do {
                cout << "\n1. Push\n2. Pop\n3. Display\n4. Exit\n";
                cin >> choice;
                if (choice == 1) { double val; cin >> val; s.push(val); }
                else if (choice == 2) s.pop();
                else if (choice == 3) s.display();
            } while (choice != 4);
            break;
        }
        case 4: {
            Stack<char> s;
            do {
                cout << "\n1. Push\n2. Pop\n3. Display\n4. Exit\n";
                cin >> choice;
                if (choice == 1) { char val; cin >> val; s.push(val); }
                else if (choice == 2) s.pop();
                else if (choice == 3) s.display();
            } while (choice != 4);
            break;
        }
    }
}

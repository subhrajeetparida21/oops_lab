#include <iostream>
using namespace std;

#define MAX 10   // maximum size of stack

class Stack {
    int arr[MAX];
    int top;
public:
    Stack() { top = -1; }
    void push(int value);
    int pop();
    void display();
    bool isEmpty();
    bool isFull();
};

void Stack::push(int value) {
    if(isFull()) {
        cout << "Stack is Full!!" << endl;
        return;
    }
    arr[++top] = value;
}

int Stack::pop() {
    if(isEmpty()) {
        cout << "Stack is Empty!!" << endl;
        return -1;
    }
    return arr[top--];
}

void Stack::display() {
    if(isEmpty()) {
        cout << "Stack is Empty!!" << endl;
        return;
    }
    cout << "Stack from top to bottom: ";
    for(int i=top;i>=0;i--)
        cout << arr[i] << "->";
    cout << "NULL" << endl;
}

bool Stack::isEmpty() {
    return (top == -1);
}

bool Stack::isFull() {
    return (top == MAX-1);
}

int main() {
    Stack s;
    int choice, val;

    do {
        cout << "\n--- Stack Menu ---" << endl;
        cout << "1. Push" << endl;
        cout << "2. Pop" << endl;
        cout << "3. Display" << endl;
        cout << "4. Check if Empty" << endl;
        cout << "5. Check if Full" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice) {
            case 1:
                cout << "Enter value to push: ";
                cin >> val;
                s.push(val);
                break;
            case 2:
                val = s.pop();
                if(val != -1)
                    cout << "Popped value: " << val << endl;
                break;
            case 3:
                s.display();
                break;
            case 4:
                cout << (s.isEmpty() ? "Stack is Empty" : "Stack is not Empty") << endl;
                break;
            case 5:
                cout << (s.isFull() ? "Stack is Full" : "Stack is not Full") << endl;
                break;
            case 0:
                cout << "Exiting program..." << endl;
                break;
            default:
                cout << "Invalid choice! Try again." << endl;
        }
    } while(choice != 0);

    return 0;
}

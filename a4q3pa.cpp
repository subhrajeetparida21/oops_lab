#include <iostream>
using namespace std;

class node {
public:
    int value;
    node *prev;
};

class Stack {
    node *top;
public:
    Stack();
    ~Stack();
    void push(int value);
    int pop();
    void display();
    bool isEmpty();
    bool isFull();
};

Stack::Stack() {
    top = nullptr;
}

Stack::~Stack() {
    while(top != nullptr) {
        node *temp = top;
        top = top->prev;
        delete temp;
    }
}

void Stack::push(int value) {
    node *newnode = new node;
    newnode->value = value;
    newnode->prev = top;
    top = newnode;
}

int Stack::pop() {
    if(top == nullptr) {
        cout << "Stack is empty!!" << endl;
        return -1;
    }
    int value = top->value;
    node *temp = top;
    top = top->prev;
    delete temp;
    return value;
}

void Stack::display() {
    if(top == nullptr) {
        cout << "Stack is empty!!" << endl;
        return;
    }
    node *temp = top;
    cout << "Stack from top to bottom: ";
    while(temp != nullptr) {
        cout << temp->value << "->";
        temp = temp->prev;
    }
    cout << "NULL" << endl;
}

bool Stack::isEmpty() {
    return (top == nullptr);
}

bool Stack::isFull() {
    node *checknode = new(nothrow) node;
    if(checknode == nullptr) return true;
    delete checknode;
    return false;
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


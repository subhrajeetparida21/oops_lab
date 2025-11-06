#include <iostream>
using namespace std;

class node {
public:
    int value;
    node* next;
};

class Queue {
    node* front;
    node* rear;
public:
    Queue();
    ~Queue();
    void push(int value);   // enqueue
    int pop();              // dequeue
    void display();
    bool isEmpty();
    bool isFull();          // check memory allocation
};

Queue::Queue() {
    front = rear = nullptr;
}

Queue::~Queue() {
    while(front != nullptr) {
        node* temp = front;
        front = front->next;
        delete temp;
    }
    rear = nullptr;
}

void Queue::push(int value) {
    node* newNode = new node();
    newNode->value = value;
    newNode->next = nullptr;

    if(rear == nullptr) {
        front = rear = newNode;
        return;
    }

    rear->next = newNode;
    rear = newNode;
}

int Queue::pop() {
    if(front == nullptr) {
        cout << "Queue is empty!" << endl;
        return -1;
    }

    int val = front->value;
    node* temp = front;
    front = front->next;

    if(front == nullptr) rear = nullptr;

    delete temp;
    return val;
}

void Queue::display() {
    if(front == nullptr) {
        cout << "Queue is empty!" << endl;
        return;
    }
    cout << "Queue (front -> rear): ";
    node* temp = front;
    while(temp != nullptr) {
        cout << temp->value << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

bool Queue::isEmpty() {
    return (front == nullptr);
}

bool Queue::isFull() {
    node* test = new(nothrow) node;
    if(test == nullptr) return true;
    delete test;
    return false;
}

int main() {
    Queue q;
    int choice, value;

    do {
        cout << "\n--- Queue Menu ---" << endl;
        cout << "1. Push (Enqueue)" << endl;
        cout << "2. Pop (Dequeue)" << endl;
        cout << "3. Display" << endl;
        cout << "4. Check if Empty" << endl;
        cout << "5. Check if Full" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice) {
            case 1:
                cout << "Enter value to enqueue: ";
                cin >> value;
                q.push(value);
                break;
            case 2:
                value = q.pop();
                if(value != -1)
                    cout << "Dequeued value: " << value << endl;
                break;
            case 3:
                q.display();
                break;
            case 4:
                cout << (q.isEmpty() ? "Queue is Empty" : "Queue is not Empty") << endl;
                break;
            case 5:
                cout << (q.isFull() ? "Queue is Full (memory exhausted)" : "Queue is not Full") << endl;
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

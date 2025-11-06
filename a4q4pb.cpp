#include <iostream>
using namespace std;

#define MAX 100   // maximum size of queue

class Queue {
    int arr[MAX];
    int front, rear;
public:
    Queue();
    void push(int value);   // enqueue
    int pop();              // dequeue
    void display();
    bool isEmpty();
    bool isFull();
};

Queue::Queue() {
    front = -1;
    rear = -1;
}

void Queue::push(int value) {
    if(isFull()) {
        cout << "Queue is Full!" << endl;
        return;
    }
    if(front == -1) front = 0;
    arr[++rear] = value;
}

int Queue::pop() {
    if(isEmpty()) {
        cout << "Queue is Empty!" << endl;
        return -1;
    }
    int val = arr[front];
    if(front == rear) {
        front = rear = -1;   // reset queue after last element is removed
    } else {
        front++;
    }
    return val;
}

void Queue::display() {
    if(isEmpty()) {
        cout << "Queue is Empty!" << endl;
        return;
    }
    cout << "Queue (front -> rear): ";
    for(int i = front; i <= rear; i++) {
        cout << arr[i] << " -> ";
    }
    cout << "NULL" << endl;
}

bool Queue::isEmpty() {
    return (front == -1);
}

bool Queue::isFull() {
    return (rear == MAX - 1);
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
                cout << (q.isFull() ? "Queue is Full" : "Queue is not Full") << endl;
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

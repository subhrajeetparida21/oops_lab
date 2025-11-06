#include <iostream>
using namespace std;

class node {
public:
    int value;
    node* prev;
    node* next;
};

class DoublyLinkedList {
    node* head;
    node* tail;

public:
    DoublyLinkedList();
    ~DoublyLinkedList();
    void insertEnd(int value);
    void insertAt(int value, int pos);
    void deleteAt(int pos);
    void displayForward();
    void displayBackward();
};

DoublyLinkedList::DoublyLinkedList() {
    head = nullptr;
    tail = nullptr;
}

DoublyLinkedList::~DoublyLinkedList() {
    while (head != nullptr) {
        node* temp = head;
        head = head->next;
        delete temp;
    }
}

void DoublyLinkedList::insertEnd(int value) {
    node* newNode = new node();
    newNode->value = value;
    newNode->next = nullptr;
    newNode->prev = tail;

    if (head == nullptr) {
        head = tail = newNode;
        return;
    }

    tail->next = newNode;
    tail = newNode;
}

void DoublyLinkedList::insertAt(int value, int pos) {
    node* newNode = new node();
    newNode->value = value;
    newNode->next = nullptr;
    newNode->prev = nullptr;

    if (pos == 1) {
        newNode->next = head;
        if (head != nullptr) head->prev = newNode;
        head = newNode;
        if (tail == nullptr) tail = newNode;
        return;
    }

    node* temp = head;
    int i = 1;
    while (temp != nullptr && i < pos - 1) {
        temp = temp->next;
        i++;
    }

    if (temp == nullptr) {
        cout << "Position out of range\n";
        delete newNode;
        return;
    }

    newNode->next = temp->next;
    newNode->prev = temp;
    if (temp->next != nullptr)
        temp->next->prev = newNode;
    temp->next = newNode;
    if (newNode->next == nullptr) tail = newNode;
}

void DoublyLinkedList::deleteAt(int pos) {
    if (head == nullptr) {
        cout << "List is empty!\n";
        return;
    }

    if (pos == 1) {
        node* temp = head;
        head = head->next;
        if (head != nullptr) head->prev = nullptr;
        else tail = nullptr;
        delete temp;
        return;
    }

    node* temp = head;
    int i = 1;
    while (temp != nullptr && i < pos) {
        temp = temp->next;
        i++;
    }

    if (temp == nullptr) {
        cout << "Position out of range!\n";
        return;
    }

    if (temp->next != nullptr) temp->next->prev = temp->prev;
    if (temp->prev != nullptr) temp->prev->next = temp->next;
    if (temp == tail) tail = temp->prev;

    delete temp;
}

void DoublyLinkedList::displayForward() {
    if (head == nullptr) {
        cout << "List is empty.\n";
        return;
    }

    node* temp = head;
    while (temp != nullptr) {
        cout << temp->value << " <-> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

void DoublyLinkedList::displayBackward() {
    if (tail == nullptr) {
        cout << "List is empty.\n";
        return;
    }

    node* temp = tail;
    while (temp != nullptr) {
        cout << temp->value << " <-> ";
        temp = temp->prev;
    }
    cout << "NULL\n";
}

int main() {
    DoublyLinkedList list;
    int choice, value, pos;

    do {
        cout << "\n--- Doubly Linked List Menu ---\n";
        cout << "1. Insert at end\n";
        cout << "2. Insert at position\n";
        cout << "3. Delete at position\n";
        cout << "4. Display Forward\n";
        cout << "5. Display Backward\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value: ";
            cin >> value;
            list.insertEnd(value);
            break;

        case 2:
            cout << "Enter value and position: ";
            cin >> value >> pos;
            list.insertAt(value, pos);
            break;

        case 3:
            cout << "Enter position: ";
            cin >> pos;
            list.deleteAt(pos);
            break;

        case 4:
            list.displayForward();
            break;

        case 5:
            list.displayBackward();
            break;

        case 0:
            cout << "Exiting...\n";
            break;

        default:
            cout << "Invalid choice!\n";
        }
    } while (choice != 0);

    return 0;
}

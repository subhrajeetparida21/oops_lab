#include <iostream>
using namespace std;

class node {
public:
    int value;
    node* next;
};

class Linkedlist {
    node *head;

public:
    Linkedlist();
    ~Linkedlist();
    void insertData(int value);
    void insertData(int value, int pos);
    void deleteData(int pos);
    void display();
};

Linkedlist::Linkedlist() {
    head = nullptr;
}

Linkedlist::~Linkedlist() {
    while (head != nullptr) {
        node *temp = head;
        head = head->next;
        delete temp;
    }
}

void Linkedlist::insertData(int value) {
    node *newNode = new node();
    newNode->value = value;
    newNode->next = nullptr;

    if (head == nullptr) {
        head = newNode;
        return;
    }

    node *temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    temp->next = newNode;
}

void Linkedlist::insertData(int value, int pos) {
    node *newNode = new node();
    newNode->value = value;
    newNode->next = nullptr;

    if (pos == 1) {
        newNode->next = head;
        head = newNode;
        return;
    }

    node *temp = head;
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
    temp->next = newNode;
}

void Linkedlist::deleteData(int pos) {
    if (head == nullptr) {
        cout << "Linked list is empty!" << endl;
        return;
    }

    if (pos == 1) {
        node *temp = head;
        head = head->next;
        delete temp;
        return;
    }

    node *temp = head;
    int i = 1;
    while (temp->next != nullptr && i < pos - 1) {
        temp = temp->next;
        i++;
    }

    if (temp->next == nullptr) {
        cout << "Position out of range!" << endl;
        return;
    }

    node *temp2 = temp->next;
    temp->next = temp->next->next;
    delete temp2;
}

void Linkedlist::display() {
    node *temp = head;
    if (temp == nullptr) {
        cout << "List is empty.\n";
        return;
    }

    while (temp != nullptr) {
        cout << temp->value << " -> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

int main() {
    Linkedlist list;
    int choice, value, pos;

    do {
        cout << "\n--- Linked List Menu ---\n";
        cout << "1. Insert at end\n";
        cout << "2. Insert at position\n";
        cout << "3. Delete at position\n";
        cout << "4. Display\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value: ";
            cin >> value;
            list.insertData(value);
            break;

        case 2:
            cout << "Enter value and position: ";
            cin >> value >> pos;
            list.insertData(value, pos);
            break;

        case 3:
            cout << "Enter position: ";
            cin >> pos;
            list.deleteData(pos);
            break;

        case 4:
            list.display();
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

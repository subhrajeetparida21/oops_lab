#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int d);
};

class SingleLinkedList {
    Node* head;
public:
    SingleLinkedList();
    SingleLinkedList(const SingleLinkedList &l);
    void append(int val);
    SingleLinkedList operator+(const SingleLinkedList &l);
    SingleLinkedList operator!();
    bool operator==(const SingleLinkedList &l);
    SingleLinkedList& operator=(const SingleLinkedList &l);
    int& operator[](int index);
    friend istream& operator>>(istream &in, SingleLinkedList &l);
    friend ostream& operator<<(ostream &out, const SingleLinkedList &l);
};

Node::Node(int d) {
    data = d;
    next = nullptr;
}

SingleLinkedList::SingleLinkedList() {
    head = nullptr;
}

SingleLinkedList::SingleLinkedList(const SingleLinkedList &l) {
    head = nullptr;
    Node* temp = l.head;
    while(temp != nullptr) {
        append(temp->data);
        temp = temp->next;
    }
}

void SingleLinkedList::append(int val) {
    Node* n = new Node(val);
    if(head == nullptr) {
        head = n;
    }
    else {
        Node* t = head;
        while(t->next != nullptr) t = t->next;
        t->next = n;
    }
}

SingleLinkedList SingleLinkedList::operator+(const SingleLinkedList &l) {
    SingleLinkedList temp(*this);
    Node* t = l.head;
    while(t != nullptr) {
        temp.append(t->data);
        t = t->next;
    }
    return temp;
}

SingleLinkedList SingleLinkedList::operator!() {
    SingleLinkedList temp;
    Node* t = head;
    while(t != nullptr) {
        Node* n = new Node(t->data);
        n->next = temp.head;
        temp.head = n;
        t = t->next;
    }
    return temp;
}

bool SingleLinkedList::operator==(const SingleLinkedList &l) {
    Node* t1 = head;
    Node* t2 = l.head;
    while(t1 != nullptr && t2 != nullptr) {
        if(t1->data != t2->data) return false;
        t1 = t1->next;
        t2 = t2->next;
    }
    return (t1 == nullptr && t2 == nullptr);
}

SingleLinkedList& SingleLinkedList::operator=(const SingleLinkedList &l) {
    if(this != &l) {
        while(head != nullptr) {
            Node* t = head;
            head = head->next;
            delete t;
        }
        head = nullptr;
        Node* t = l.head;
        while(t != nullptr) {
            append(t->data);
            t = t->next;
        }
    }
    return *this;
}

int& SingleLinkedList::operator[](int index) {
    Node* t = head;
    int count = 0;
    while(t != nullptr && count < index) {
        t = t->next;
        count++;
    }
    if(t == nullptr) {
        cout << "Index out of bounds" << endl;
        static int dummy = 0;
        return dummy;
    }
    return t->data;
}

istream& operator>>(istream &in, SingleLinkedList &l) {
    int n;
    cout << "Enter number of nodes: ";
    in >> n;
    for(int i = 0; i < n; i++) {
        int x;
        cout << "Enter value for node " << i+1 << ": ";
        in >> x;
        l.append(x);
    }
    return in;
}

ostream& operator<<(ostream &out, const SingleLinkedList &l) {
    Node* t = l.head;
    while(t != nullptr) {
        out << t->data << " ";
        t = t->next;
    }
    return out;
}

int main() {
    SingleLinkedList l1, l2, l3;
    cout << "Enter the values for the first linked list" << endl;
    cin >> l1;
    cout << "Enter the values for the second linked list" << endl;
    cin >> l2;

    cout << "Concatenated list (l1 + l2): " << (l1 + l2) << endl;
    cout << "Reversed l1: " << !l1 << endl;
    cout << "l1 == l2 ? " << (l1 == l2 ? "Equal" : "Not Equal") << endl;

    cout << "l1[1] = " << l1[1] << endl;
    cout << "Trying out of bounds: " << l1[10] << endl;

    return 0;
}

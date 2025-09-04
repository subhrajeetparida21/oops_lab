#include <iostream>
#include <string>
#include <complex>
using namespace std;

// Node structure
template <typename T>
struct Node {
    T data;
    Node* next;
    Node(T val) : data(val), next(nullptr) {}
};

// Single Linked List Template
template <typename T>
class SingleLinkedList {
private:
    Node<T>* head;

    void copyList(const SingleLinkedList& other) {
        if (!other.head) {
            head = nullptr;
            return;
        }
        head = new Node<T>(other.head->data);
        Node<T>* temp1 = head;
        Node<T>* temp2 = other.head->next;
        while (temp2) {
            temp1->next = new Node<T>(temp2->data);
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
    }

public:
    // Default constructor
    SingleLinkedList() : head(nullptr) {}

    // Copy constructor
    SingleLinkedList(const SingleLinkedList& other) {
        copyList(other);
    }

    // Assignment operator
    SingleLinkedList& operator=(const SingleLinkedList& other) {
        if (this != &other) {
            this->~SingleLinkedList();
            copyList(other);
        }
        return *this;
    }

    // Insert at end
    void insert(T val) {
        Node<T>* newNode = new Node<T>(val);
        if (!head) {
            head = newNode;
            return;
        }
        Node<T>* temp = head;
        while (temp->next) temp = temp->next;
        temp->next = newNode;
    }

    // Concatenate (+)
    SingleLinkedList operator+(const SingleLinkedList& other) const {
        SingleLinkedList result(*this); // copy first list
        Node<T>* temp = other.head;
        while (temp) {
            result.insert(temp->data);
            temp = temp->next;
        }
        return result;
    }

    // Reverse (!)
    SingleLinkedList operator!() const {
        SingleLinkedList result;
        Node<T>* temp = head;
        while (temp) {
            Node<T>* newNode = new Node<T>(temp->data);
            newNode->next = result.head;
            result.head = newNode;
            temp = temp->next;
        }
        return result;
    }

    // Compare (==)
    bool operator==(const SingleLinkedList& other) const {
        Node<T>* temp1 = head;
        Node<T>* temp2 = other.head;
        while (temp1 && temp2) {
            if (temp1->data != temp2->data) return false;
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        return (!temp1 && !temp2);
    }

    // Output operator
    friend ostream& operator<<(ostream& out, const SingleLinkedList& list) {
        Node<T>* temp = list.head;
        while (temp) {
            out << temp->data << " -> ";
            temp = temp->next;
        }
        out << "NULL";
        return out;
    }

    // Input operator
    friend istream& operator>>(istream& in, SingleLinkedList& list) {
        int n;
        cout << "Enter number of elements: ";
        in >> n;
        for (int i = 0; i < n; i++) {
            T val;
            cout << "Enter value " << i + 1 << ": ";
            in >> val;
            list.insert(val);
        }
        return in;
    }
};

// Main function
int main() {
    cout << "Integer Linked List:\n";
    SingleLinkedList<int> l1, l2;
    cin >> l1;
    cin >> l2;

    cout << "\nList 1: " << l1 << endl;
    cout << "List 2: " << l2 << endl;

    // Concatenate
    auto l3 = l1 + l2;
    cout << "Concatenated: " << l3 << endl;

    // Reverse
    auto l4 = !l1;
    cout << "Reversed List1: " << l4 << endl;

    // Compare
    cout << "List1 == List2 ? " << (l1 == l2 ? "Yes" : "No") << endl;

    cout << "\nString Linked List:\n";
    SingleLinkedList<string> s1, s2;
    cin >> s1;
    cin >> s2;

    cout << "Concatenated String List: " << (s1 + s2) << endl;

    cout << "\nComplex Number Linked List:\n";
    SingleLinkedList<complex<double>> c1, c2;
    cin >> c1;
    cin >> c2;

    cout << "Concatenated Complex List: " << (c1 + c2) << endl;

    return 0;
}


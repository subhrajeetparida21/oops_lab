#include <iostream>
using namespace std;

void push(int stack[], int &top, int val) {
    stack[++top] = val;
}

void push(float stack[], int &top, float val) {
    stack[++top] = val;
}

void push(double stack[], int &top, double val) {
    stack[++top] = val;
}

void push(char stack[], int &top, char val) {
    stack[++top] = val;
}

void push(short stack[], int &top, short val) {
    stack[++top] = val;
}

void push(long stack[], int &top, long val) {
    stack[++top] = val;
}

void pop(int &top) {
    if (top >= 0) top--;
}

void pop(float &top) {
    if (top >= 0) top--;
}

void pop(double &top) {
    if (top >= 0) top--;
}

void pop(char &top) {
    if (top >= 0) top--;
}

void pop(short &top) {
    if (top >= 0) top--;
}

void pop(long &top) {
    if (top >= 0) top--;
}

void display(int stack[], int top) {
    cout << "Stack: ";
    for (int i = 0; i <= top; i++) cout << stack[i] << " ";
    cout << "\n";
}

void display(float stack[], int top) {
    cout << "Stack: ";
    for (int i = 0; i <= top; i++) cout << stack[i] << " ";
    cout << "\n";
}

void display(double stack[], int top) {
    cout << "Stack: ";
    for (int i = 0; i <= top; i++) cout << stack[i] << " ";
    cout << "\n";
}

void display(char stack[], int top) {
    cout << "Stack: ";
    for (int i = 0; i <= top; i++) cout << stack[i] << " ";
    cout << "\n";
}

void display(short stack[], int top) {
    cout << "Stack: ";
    for (int i = 0; i <= top; i++) cout << stack[i] << " ";
    cout << "\n";
}

void display(long stack[], int top) {
    cout << "Stack: ";
    for (int i = 0; i <= top; i++) cout << stack[i] << " ";
    cout << "\n";
}

int main() {
    int stackInt[50], topInt = -1;
    float stackFloat[50]; int topFloat = -1;
    double stackDouble[50]; int topDouble = -1;
    char stackChar[50]; int topChar = -1;
    short stackShort[50]; int topShort = -1;
    long stackLong[50]; int topLong = -1;

    int dtype;
    cout << "Choose a data type:\n1. Integer\n2. Float\n3. Double\n4. Character\n5. Short\n6. Long\n";
    cin >> dtype;

    int choice;
    while (true) {
        cout << "\nChoose an operation:\n1. Push\n2. Pop\n3. Display\n4. Exit\n";
        cin >> choice;

        if (choice == 4) break;

        if (dtype == 1) {
            if (choice == 1) { int val; cout << "Enter value: "; cin >> val; push(stackInt, topInt, val); }
            else if (choice == 2) { pop(topInt); }
            else if (choice == 3) { display(stackInt, topInt); }
        }
        else if (dtype == 2) {
            if (choice == 1) { float val; cout << "Enter value: "; cin >> val; push(stackFloat, topFloat, val); }
            else if (choice == 2) { pop(topFloat); }
            else if (choice == 3) { display(stackFloat, topFloat); }
        }
        else if (dtype == 3) {
            if (choice == 1) { double val; cout << "Enter value: "; cin >> val; push(stackDouble, topDouble, val); }
            else if (choice == 2) { pop(topDouble); }
            else if (choice == 3) { display(stackDouble, topDouble); }
        }
        else if (dtype == 4) {
            if (choice == 1) { char val; cout << "Enter value: "; cin >> val; push(stackChar, topChar, val); }
            else if (choice == 2) { pop(topChar); }
            else if (choice == 3) { display(stackChar, topChar); }
        }
        else if (dtype == 5) {
            if (choice == 1) { short val; cout << "Enter value: "; cin >> val; push(stackShort, topShort, val); }
            else if (choice == 2) { pop(topShort); }
            else if (choice == 3) { display(stackShort, topShort); }
        }
        else if (dtype == 6) {
            if (choice == 1) { long val; cout << "Enter value: "; cin >> val; push(stackLong, topLong, val); }
            else if (choice == 2) { pop(topLong); }
            else if (choice == 3) { display(stackLong, topLong); }
        }
    }

    return 0;
}

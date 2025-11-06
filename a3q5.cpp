#include <iostream>
#include <string>
using namespace std;

template <typename T>
class Stack {
private:
    T* arr;
    int idx;
    int maxSize;
public:
    Stack(int n) {
        arr = new T[n];
        idx = -1;
        maxSize = n;
    }
    void push(T val) {
        if (idx == maxSize - 1) {
            cout << "Stack is Full!!" << endl;
            return;
        }
        idx++;
        arr[idx] = val;
    }
    void pop() {
        if (idx == -1) {
            cout << "Empty Stack!!" << endl;
            return;
        }
        cout << arr[idx] << " is popped from the Stack!!" << endl;
        idx--;
    }
    void peek() {
        if (idx == -1) {
            cout << "Empty Stack!!" << endl;
            return;
        }
        cout << "Top element: " << arr[idx] << endl;
    }
    int size() {
        return idx + 1;
    }
};

int main() {
    int n, choice;
    cout << "Enter Size of the Stack: ";
    cin >> n;

    cout << "------------------------" << endl;
    cout << "1. Integer" << endl;
    cout << "2. Float " << endl;
    cout << "3. String" << endl;
    cout << "4. Character" << endl;
    cout << "------------------------" << endl;

    string dataType = "";
    int field = 0;

    Stack<int> intStack(n);
    Stack<float> floatStack(n);
    Stack<string> stringStack(n);
    Stack<char> charStack(n);

    while (true) {
        cout << "Select Your Stack Data Type: ";
        cin >> choice;
        if (choice == 1) { field = 1; dataType = "Integer"; break; }
        else if (choice == 2) { field = 2; dataType = "Float"; break; }
        else if (choice == 3) { field = 3; dataType = "String"; break; }
        else if (choice == 4) { field = 4; dataType = "Character"; break; }
        else cout << "Invalid Choice!! Please!!" << endl;
    }

    cout << "------------------------" << endl;
    cout << "1. Push" << endl;
    cout << "2. Pop " << endl;
    cout << "3. Current Size of The Stack" << endl;
    cout << "4. Peek" << endl;
    cout << "5. Exit" << endl;
    cout << "------------------------" << endl;

    bool flag = true;
    while (flag) {
        cout << "Select Your Choice: ";
        cin >> choice;

        string val3;
        int val;
        float val2;
        char val4;

        switch (choice) {
        case 1:
            if (field == 1) {
                cout << "Enter a Value(" << dataType << "): ";
                cin >> val;
                intStack.push(val);
            }
            else if (field == 2) {
                cout << "Enter a Value(" << dataType << "): ";
                cin >> val2;
                floatStack.push(val2);
            }
            else if (field == 3) {
                cout << "Enter a Value(" << dataType << "): ";
                cin >> val3;
                stringStack.push(val3);
            }
            else {
                cout << "Enter a Value(" << dataType << "): ";
                cin >> val4;
                charStack.push(val4);
            }
            break;

        case 2:
            if (field == 1) intStack.pop();
            else if (field == 2) floatStack.pop();
            else if (field == 3) stringStack.pop();
            else charStack.pop();
            break;

        case 3:
            if (field == 1) cout << "Current Size of the " << dataType << " Stack is: " << intStack.size() << endl;
            else if (field == 2) cout << "Current Size of the " << dataType << " Stack is: " << floatStack.size() << endl;
            else if (field == 3) cout << "Current Size of the " << dataType << " Stack is: " << stringStack.size() << endl;
            else cout << "Current Size of the " << dataType << " Stack is: " << charStack.size() << endl;
            break;

        case 4:
            if (field == 1) intStack.peek();
            else if (field == 2) floatStack.peek();
            else if (field == 3) stringStack.peek();
            else charStack.peek();
            break;

        case 5:
            cout << "Exiting..." << endl;
            flag = false;
            break;

        default:
            cout << "Please Enter a Valid Choice!!" << endl;
        }
    }
    return 0;
}

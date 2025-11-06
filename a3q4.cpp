#include <iostream>
#include <string>
using namespace std;

template <typename T>
class Array {
private:
    T* arr;
    int idx;
    int maxSize;
public:
    Array(int n) {
        arr = new T[n];
        idx = -1;
        maxSize = n;
    }
    void push(T val) {
        if (idx + 1 == maxSize) {
            cout << "Array is Full!!" << endl;
            return;
        }
        idx++;
        arr[idx] = val;
    }
    void pop() {
        if (idx == -1) {
            cout << "Empty Array!!" << endl;
            return;
        }
        cout << arr[idx] << " is popped from the Array!!" << endl;
        idx--;
    }
    void display() {
        if (idx == -1) {
            cout << "Empty Array!!" << endl;
            return;
        }
        cout << "Elements Present in the Array are: ";
        for (int i = 0; i <= idx; i++) cout << arr[i] << " ";
        cout << endl;
    }
    int size() {
        return idx + 1;
    }
};

int main() {
    int n, choice;
    cout << "Enter Size of the Array: ";
    cin >> n;

    cout << "------------------------" << endl;
    cout << "1. Integer" << endl;
    cout << "2. Float " << endl;
    cout << "3. String" << endl;
    cout << "4. Character" << endl;
    cout << "------------------------" << endl;

    string dataType = "";
    int field = 0;

    Array<int> intArr(n);
    Array<float> floatArr(n);
    Array<string> stringArr(n);
    Array<char> charArr(n);

    while (true) {
        cout << "Select Your Array Data Type: ";
        cin >> choice;
        if (choice == 1) { field = 1; dataType = "Integer"; break; }
        else if (choice == 2) { field = 2; dataType = "Real"; break; }
        else if (choice == 3) { field = 3; dataType = "String"; break; }
        else if (choice == 4) { field = 4; dataType = "Character"; break; }
        else cout << "Invalid Choice!! Please!! ";
    }

    cout << "------------------------" << endl;
    cout << "1. Push" << endl;
    cout << "2. Pop " << endl;
    cout << "3. Current Size of The Array" << endl;
    cout << "4. Display" << endl;
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
                cin >> val; intArr.push(val); 
            }
            else if (field == 2) { 
                cout << "Enter a Value(" << dataType << "): "; 
                cin >> val2; floatArr.push(val2); 
            }
            else if (field == 3) { 
                cout << "Enter a Value(" << dataType << "): "; 
                cin >> val3; stringArr.push(val3); 
            }
            else { 
                cout << "Enter a Value(" << dataType << "): ";
                cin >> val4; charArr.push(val4); 
            }
            break;

        case 2:
            if (field == 1) intArr.pop();
            else if (field == 2) floatArr.pop();
            else if (field == 3) stringArr.pop();
            else charArr.pop();
            break;

        case 3:
            if (field == 1) cout << "Current Size of the " << dataType << " Array is: " << intArr.size() << endl;
            else if (field == 2) cout << "Current Size of the " << dataType << " Array is: " << floatArr.size() << endl;
            else if (field == 3) cout << "Current Size of the " << dataType << " Array is: " << stringArr.size() << endl;
            else cout << "Current Size of the " << dataType << " Array is: " << charArr.size() << endl;
            break;

        case 4:
            if (field == 1) intArr.display();
            else if (field == 2) floatArr.display();
            else if (field == 3) stringArr.display();
            else charArr.display();
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

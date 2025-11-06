#include <iostream>
using namespace std;

void bubbleSort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++)
        for (int j = 0; j < size - i - 1; j++)
            if (arr[j] > arr[j + 1])
                swap(arr[j], arr[j + 1]);
}

void bubbleSort(float arr[], int size) {
    for (int i = 0; i < size - 1; i++)
        for (int j = 0; j < size - i - 1; j++)
            if (arr[j] > arr[j + 1])
                swap(arr[j], arr[j + 1]);
}

void bubbleSort(double arr[], int size) {
    for (int i = 0; i < size - 1; i++)
        for (int j = 0; j < size - i - 1; j++)
            if (arr[j] > arr[j + 1])
                swap(arr[j], arr[j + 1]);
}

void bubbleSort(char arr[], int size) {
    for (int i = 0; i < size - 1; i++)
        for (int j = 0; j < size - i - 1; j++)
            if (arr[j] > arr[j + 1])
                swap(arr[j], arr[j + 1]);
}

void bubbleSort(short arr[], int size) {
    for (int i = 0; i < size - 1; i++)
        for (int j = 0; j < size - i - 1; j++)
            if (arr[j] > arr[j + 1])
                swap(arr[j], arr[j + 1]);
}

void bubbleSort(long arr[], int size) {
    for (int i = 0; i < size - 1; i++)
        for (int j = 0; j < size - i - 1; j++)
            if (arr[j] > arr[j + 1])
                swap(arr[j], arr[j + 1]);
}

void display(int arr[], int size) {
    cout << "\nArray : ";
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
}

void display(float arr[], int size) {
    cout << "\nArray : ";
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
}

void display(double arr[], int size) {
    cout << "\nArray : ";
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
}

void display(char arr[], int size) {
    cout << "\nArray : ";
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
}

void display(short arr[], int size) {
    cout << "\nArray : ";
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
}

void display(long arr[], int size) {
    cout << "\nArray : ";
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
}

int main() {
    int arrInt[50];
    float arrFloat[50];
    double arrDouble[50];
    char arrChar[50];
    short arrShort[50];
    long arrLong[50];

    int dtype;
    cout << "Choose a data type :\n"
         << "1. Integer\n"
         << "2. Float\n"
         << "3. Double\n"
         << "4. Character\n"
         << "5. Short\n"
         << "6. Long\n";
    cin >> dtype;

    int sizeInt=0, sizeDouble=0, sizeFloat=0, sizeChar=0, sizeShort=0, sizeLong=0;
    int choice;

    while (true) {
        cout << "\nChoose an operation :\n"
             << "1. Input Array\n"
             << "2. Sort Array\n"
             << "3. Display Array\n"
             << "4. Exit\n";
        cin >> choice;

        if (choice == 4)
            break;

        if (dtype == 1) {
            if (choice == 1) {
                cout << "Enter size: ";
                cin >> sizeInt;
                cout << "Enter elements: ";
                for (int i = 0; i < sizeInt; i++) cin >> arrInt[i];
            }
            else if (choice == 2) {
                bubbleSort(arrInt, sizeInt);
            }
            else if (choice == 3) {
                display(arrInt, sizeInt);
            }
        }
        else if (dtype == 2) {
            if (choice == 1) {
                cout << "Enter size: ";
                cin >> sizeFloat;
                cout << "Enter elements: ";
                for (int i = 0; i < sizeFloat; i++) cin >> arrFloat[i];
            }
            else if (choice == 2) {
                bubbleSort(arrFloat, sizeFloat);
            }
            else if (choice == 3) {
                display(arrFloat, sizeFloat);
            }
        }
        else if (dtype == 3) {
            if (choice == 1) {
                cout << "Enter size: ";
                cin >> sizeDouble;
                cout << "Enter elements: ";
                for (int i = 0; i < sizeDouble; i++) cin >> arrDouble[i];
            }
            else if (choice == 2) {
                bubbleSort(arrDouble, sizeDouble);
            }
            else if (choice == 3) {
                display(arrDouble, sizeDouble);
            }
        }
        else if (dtype == 4) {
            if (choice == 1) {
                cout << "Enter size: ";
                cin >> sizeChar;
                cout << "Enter elements: ";
                for (int i = 0; i < sizeChar; i++) cin >> arrChar[i];
            }
            else if (choice == 2) {
                bubbleSort(arrChar, sizeChar);
            }
            else if (choice == 3) {
                display(arrChar, sizeChar);
            }
        }
        else if (dtype == 5) {
            if (choice == 1) {
                cout << "Enter size: ";
                cin >> sizeShort;
                cout << "Enter elements: ";
                for (int i = 0; i < sizeShort; i++) cin >> arrShort[i];
            }
            else if (choice == 2) {
                bubbleSort(arrShort, sizeShort);
            }
            else if (choice == 3) {
                display(arrShort, sizeShort);
            }
        }
        else if (dtype == 6) {
            if (choice == 1) {
                cout << "Enter size: ";
                cin >> sizeLong;
                cout << "Enter elements: ";
                for (int i = 0; i < sizeLong; i++) cin >> arrLong[i];
            }
            else if (choice == 2) {
                bubbleSort(arrLong, sizeLong);
            }
            else if (choice == 3) {
                display(arrLong, sizeLong);
            }
        }
    }
    return 0;
}

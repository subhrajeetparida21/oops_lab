#include <iostream>
using namespace std;

int binarySearch(int arr[], int size, int key) 
{
    int low = 0;
    int high = size - 1;
    while (low <= high) 
    {
        int mid = (low + high) / 2;
        if (arr[mid] == key)
            return mid;
        else if (arr[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}

int binarySearch(float arr[], int size, float key) 
{
    int low = 0;
    int high = size - 1;
    while (low <= high) 
    {
        int mid = (low + high) / 2;
        if (arr[mid] == key)
            return mid;
        else if (arr[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}

int binarySearch(double arr[], int size, double key) 
{
    int low = 0;
    int high = size - 1;
    while (low <= high) 
    {
        int mid = (low + high) / 2;
        if (arr[mid] == key)
            return mid;
        else if (arr[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}

int binarySearch(char arr[], int size, char key) 
{
    int low = 0;
    int high = size - 1;
    while (low <= high) 
    {
        int mid = (low + high) / 2;
        if (arr[mid] == key)
            return mid;
        else if (arr[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}

int binarySearch(short arr[], int size, short key) 
{
    int low = 0;
    int high = size - 1;
    while (low <= high) 
    {
        int mid = (low + high) / 2;
        if (arr[mid] == key)
            return mid;
        else if (arr[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}

int binarySearch(long arr[], int size, long key) 
{
    int low = 0;
    int high = size - 1;
    while (low <= high) 
    {
        int mid = (low + high) / 2;
        if (arr[mid] == key)
            return mid;
        else if (arr[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}

int main() 
{
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

    int sizeInt = 0, sizeDouble = 0, sizeFloat = 0, sizeChar = 0, sizeShort = 0, sizeLong = 0;
    int choice;

    while (true) 
    {
        cout << "\nChoose an operation :\n"
             << "1. Input Sorted Array\n"
             << "2. Search Element\n"
             << "3. Exit\n";
        cin >> choice;

        if (choice == 3)
            break;

        if (dtype == 1) 
        {
            if (choice == 1) 
            {
                cout << "Enter size: ";
                cin >> sizeInt;
                cout << "Enter sorted elements: ";
                for (int i = 0; i < sizeInt; i++) cin >> arrInt[i];
            }
            else if (choice == 2) 
            {
                int key;
                cout << "Enter key: ";
                cin >> key;
                int result = binarySearch(arrInt, sizeInt, key);
                if (result != -1) cout << "Found at index " << result;
                else cout << "Not found";
            }
        }
        else if (dtype == 2) 
        {
            if (choice == 1) 
            {
                cout << "Enter size: ";
                cin >> sizeFloat;
                cout << "Enter sorted elements: ";
                for (int i = 0; i < sizeFloat; i++) cin >> arrFloat[i];
            }
            else if (choice == 2) 
            {
                float key;
                cout << "Enter key: ";
                cin >> key;
                int result = binarySearch(arrFloat, sizeFloat, key);
                if (result != -1) cout << "Found at index " << result;
                else cout << "Not found";
            }
        }
        else if (dtype == 3) 
        {
            if (choice == 1) 
            {
                cout << "Enter size: ";
                cin >> sizeDouble;
                cout << "Enter sorted elements: ";
                for (int i = 0; i < sizeDouble; i++) cin >> arrDouble[i];
            }
            else if (choice == 2) 
            {
                double key;
                cout << "Enter key: ";
                cin >> key;
                int result = binarySearch(arrDouble, sizeDouble, key);
                if (result != -1) cout << "Found at index " << result;
                else cout << "Not found";
            }
        }
        else if (dtype == 4) 
        {
            if (choice == 1) 
            {
                cout << "Enter size: ";
                cin >> sizeChar;
                cout << "Enter sorted elements: ";
                for (int i = 0; i < sizeChar; i++) cin >> arrChar[i];
            }
            else if (choice == 2) 
            {
                char key;
                cout << "Enter key: ";
                cin >> key;
                int result = binarySearch(arrChar, sizeChar, key);
                if (result != -1) cout << "Found at index " << result;
                else cout << "Not found";
            }
        }
        else if (dtype == 5) 
        {
            if (choice == 1) 
            {
                cout << "Enter size: ";
                cin >> sizeShort;
                cout << "Enter sorted elements: ";
                for (int i = 0; i < sizeShort; i++) cin >> arrShort[i];
            }
            else if (choice == 2) 
            {
                short key;
                cout << "Enter key: ";
                cin >> key;
                int result = binarySearch(arrShort, sizeShort, key);
                if (result != -1) cout << "Found at index " << result;
                else cout << "Not found";
            }
        }
        else if (dtype == 6) 
        {
            if (choice == 1) 
            {
                cout << "Enter size: ";
                cin >> sizeLong;
                cout << "Enter sorted elements: ";
                for (int i = 0; i < sizeLong; i++) cin >> arrLong[i];
            }
            else if (choice == 2) 
            {
                long key;
                cout << "Enter key: ";
                cin >> key;
                int result = binarySearch(arrLong, sizeLong, key);
                if (result != -1) cout << "Found at index " << result;
                else cout << "Not found";
            }
        }
    }

    return 0;
}

#include <iostream>
using namespace std;

template <typename T>
void insert(T arr[], int *size, T value) 
{
    arr[(*size)++] = value;
}

template <typename T>
void deletevalue(T arr[], int *size, T value) 
{
    if (*size == 0) 
    {
        cout << "\nNo element present";
        return;
    }

    for (int i = 0; i < *size; i++) 
    {
        if (arr[i] == value) 
        {
            for (int j = i; j < (*size) - 1; j++) 
            {
                arr[j] = arr[j + 1];
            }
            (*size)--;
            i--; 
        }
    }
}

template <typename T>
void display(T arr[], int *size) 
{
    cout << "\nArray : ";
    for (int i = 0; i < *size; i++) 
    {
        cout << arr[i] << "->";
    }
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
             << "1. Insert\n"
             << "2. Delete\n"
             << "3. Display\n"
             << "4. Exit\n";
        cin >> choice;

        if (choice == 4) 
            break;

        if (dtype == 1) 
        {
            int val;
            if (choice == 1) 
            { 
                cout << "Enter value: "; 
                cin >> val; 
                insert(arrInt, &sizeInt, val); 
            }
            else if (choice == 2) 
            { 
                cout << "Enter value: "; 
                cin >> val; 
                deletevalue(arrInt, &sizeInt, val); 
            }
            else if (choice == 3) 
            { 
                display(arrInt, &sizeInt); 
            }
        }
        else if (dtype == 2) 
        {
            float val;
            if (choice == 1) 
            { 
                cout << "Enter value: "; 
                cin >> val; 
                insert(arrFloat, &sizeFloat, val); 
            }
            else if (choice == 2) 
            { 
                cout << "Enter value: "; 
                cin >> val; 
                deletevalue(arrFloat, &sizeFloat, val); 
            }
            else if (choice == 3) 
            { 
                display(arrFloat, &sizeFloat); 
            }
        }
        else if (dtype == 3) 
        {
            double val;
            if (choice == 1) 
            { 
                cout << "Enter value: "; 
                cin >> val; 
                insert(arrDouble, &sizeDouble, val); 
            }
            else if (choice == 2) 
            { 
                cout << "Enter value: "; 
                cin >> val; 
                deletevalue(arrDouble, &sizeDouble, val); 
            }
            else if (choice == 3) 
            { 
                display(arrDouble, &sizeDouble); 
            }
        }
        else if (dtype == 4) 
        {
            char val;
            if (choice == 1) 
            { 
                cout << "Enter value: "; 
                cin >> val; 
                insert(arrChar, &sizeChar, val); 
            }
            else if (choice == 2) 
            { 
                cout << "Enter value: "; 
                cin >> val; 
                deletevalue(arrChar, &sizeChar, val); 
            }
            else if (choice == 3) 
            { 
                display(arrChar, &sizeChar); 
            }
        }
        else if (dtype == 5) 
        {
            short val;
            if (choice == 1) 
            { 
                cout << "Enter value: "; 
                cin >> val; 
                insert(arrShort, &sizeShort, val); 
            }
            else if (choice == 2) 
            { 
                cout << "Enter value: "; 
                cin >> val; 
                deletevalue(arrShort, &sizeShort, val); 
            }
            else if (choice == 3) 
            { 
                display(arrShort, &sizeShort); 
            }
        }
        else if (dtype == 6) 
        {
            long val;
            if (choice == 1) 
            { 
                cout << "Enter value: "; 
                cin >> val; 
                insert(arrLong, &sizeLong, val); 
            }
            else if (choice == 2) 
            { 
                cout << "Enter value: "; 
                cin >> val; 
                deletevalue(arrLong, &sizeLong, val); 
            }
            else if (choice == 3) 
            { 
                display(arrLong, &sizeLong); 
            }
        }
    }

    return 0;
}

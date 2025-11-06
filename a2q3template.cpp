#include <iostream>
using namespace std;

template <typename T>
void bubbleSort(T arr[], int size) 
{
    for (int i = 0; i < size - 1; i++) 
    {
        for (int j = 0; j < size - i - 1; j++) 
        {
            if (arr[j] > arr[j + 1]) 
            {
                T temp     = arr[j];
                arr[j]     = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

template <typename T>
void display(T arr[], int size) 
{
    for (int i = 0; i < size; i++) 
    {
        cout << arr[i] << "  ";
    }
    cout << endl;
}

int main() 
{
    int choice, size;
    cout << "\n--- Bubble Sort using Function Template ---\n";
    cout << "1. int\n2. float\n3. double\n4. char\n5. short\n6. long\n";
    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice) 
    {
        case 1:
        {
            cout << "Enter size: ";
            cin >> size;
            int arr[size];
            cout << "Enter " << size << " integers: ";
            for (int i = 0; i < size; i++) cin >> arr[i];
            bubbleSort(arr, size);
            cout << "Sorted int array: ";
            display(arr, size);
            break;
        }
        case 2:
        {
            cout << "Enter size: ";
            cin >> size;
            float arr[size];
            cout << "Enter " << size << " floats: ";
            for (int i = 0; i < size; i++) cin >> arr[i];
            bubbleSort(arr, size);
            cout << "Sorted float array: ";
            display(arr, size);
            break;
        }
        case 3:
        {
            cout << "Enter size: ";
            cin >> size;
            double arr[size];
            cout << "Enter " << size << " doubles: ";
            for (int i = 0; i < size; i++) cin >> arr[i];
            bubbleSort(arr, size);
            cout << "Sorted double array: ";
            display(arr, size);
            break;
        }
        case 4:
        {
            cout << "Enter size: ";
            cin >> size;
            char arr[size];
            cout << "Enter " << size << " characters: ";
            for (int i = 0; i < size; i++) cin >> arr[i];
            bubbleSort(arr, size);
            cout << "Sorted char array: ";
            display(arr, size);
            break;
        }
        case 5:
        {
            cout << "Enter size: ";
            cin >> size;
            short arr[size];
            cout << "Enter " << size << " shorts: ";
            for (int i = 0; i < size; i++) cin >> arr[i];
            bubbleSort(arr, size);
            cout << "Sorted short array: ";
            display(arr, size);
            break;
        }
        case 6:
        {
            cout << "Enter size: ";
            cin >> size;
            long arr[size];
            cout << "Enter " << size << " longs: ";
            for (int i = 0; i < size; i++) cin >> arr[i];
            bubbleSort(arr, size);
            cout << "Sorted long array: ";
            display(arr, size);
            break;
        }
        default:
            cout << "Invalid choice!\n";
    }
    return 0;
}

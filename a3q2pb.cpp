#include <iostream>
using namespace std;

void replaceValuesDMA(int* arr, int* brr, int n) {
    int* hel = new int[n];
    for(int i=0; i<n; i++)
        *(hel + (*(brr+i))) = *(arr+i);
    for(int i=0; i<n; i++)
        *(arr+i) = *(hel+i);
    delete[] hel;
}

int main() {
    int n;
    cout << "Enter Number of Elements: ";
    cin >> n;

    int* arr = new int[n];
    int* brr = new int[n];

    cout << "Enter the Elements: ";
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }
    cout << "Enter the Indexes to Change the Element Places: ";
    for(int i=0; i<n; i++) {
        cin >> brr[i];
    }

    cout << "Elements Before Replace using DMA: ";
    for(int i=0; i<n; i++) cout << arr[i] << " ";
    cout << endl;

    replaceValuesDMA(arr, brr, n);

    cout << "Elements After Replace using DMA: ";
    for(int i=0; i<n; i++) cout << arr[i] << " ";
    cout << endl;

    delete[] arr;
    delete[] brr;
    return 0;
}

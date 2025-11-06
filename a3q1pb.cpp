#include <iostream>
using namespace std;

void oddEvenDMA(int* arr, int n) {
    int oddEle = 0, evenEle = 0;
    for(int i=0; i<n; i++) {
        if((*(arr+i)) & 1) oddEle++;
        else evenEle++;
    }
    cout << "Number of Odd Numbers in the Array is, using DMA: " << oddEle << endl;
    cout << "Number of Even Numbers in the Array is, using DMA: " << evenEle << endl;
}

int main() {
    int n;
    cout << "Enter Size of Array: ";
    cin >> n;

    int* arr = new int[n];
    cout << "Enter The Elements: ";
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }

    oddEvenDMA(arr, n);

    delete[] arr;
    return 0;
}

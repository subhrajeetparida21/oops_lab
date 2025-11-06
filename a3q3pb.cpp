#include <iostream>
using namespace std;

int* funcDMA(int* arr, int n) {
    int sz = 0;
    for(int i=1; i<n-1; i++)
        if(arr[i-1] > arr[i] && arr[i] < arr[i+1])
            sz++;

    int* ans = new int[sz+1];
    ans[0] = sz;

    int k = 1;
    for(int i=1; i<n-1; i++)
        if(arr[i-1] > arr[i] && arr[i] < arr[i+1])
            ans[k++] = arr[i];

    return ans;
}

int main() {
    int n;
    cout << "Enter Size of the Array: ";
    cin >> n;

    int* arr = new int[n];
    cout << "Enter Elements of The Array: ";
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }

    int* res = funcDMA(arr, n);

    cout << "Output using DMA: ";
    for(int i=1; i<=res[0]; i++)
        cout << res[i] << " ";
    cout << endl;

    delete[] arr;
    delete[] res;
    return 0;
}

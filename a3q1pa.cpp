#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void oddEvenVector(vector<int>& arr) {
    int oddEle = count_if(arr.begin(), arr.end(), [](int i){ return i & 1; });
    int evenEle = count_if(arr.begin(), arr.end(), [](int i){ return !(i & 1); });
    cout << "Number of Odd Numbers in the Array is, using Vector: " << oddEle << endl;
    cout << "Number of Even Numbers in the Array is, using Vector: " << evenEle << endl;
}

int main() {
    int n;
    cout << "Enter Size of Array: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter The Elements: ";
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }

    oddEvenVector(arr);
    return 0;
}

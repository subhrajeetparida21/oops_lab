#include <iostream>
#include <vector>
using namespace std;

void replaceValuesVector(vector<int>& arr, vector<int>& brr) {
    int n = arr.size();
    vector<int> hel(n);
    for(int i=0; i<n; i++)
        hel[brr[i]] = arr[i];
    arr = hel;
}

int main() {
    int n;
    cout << "Enter Number of Elements: ";
    cin >> n;

    vector<int> arr(n), brr(n);
    cout << "Enter the Elements: ";
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }
    cout << "Enter the Indexes to Change the Element Places: ";
    for(int i=0; i<n; i++) {
        cin >> brr[i];
    }

    cout << "Elements Before Replace using Vector: ";
    for(int ele: arr) cout << ele << " ";
    cout << endl;

    replaceValuesVector(arr, brr);

    cout << "Elements After Replace using Vector: ";
    for(int ele: arr) cout << ele << " ";
    cout << endl;

    return 0;
}

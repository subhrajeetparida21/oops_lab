#include <iostream>
#include <vector>
using namespace std;

vector<int> funcVector(vector<int>& arr) {
    vector<int> ans;
    int n = arr.size();
    for(int i=1; i<n-1; i++)
        if(arr[i-1] > arr[i] && arr[i] < arr[i+1])
            ans.push_back(arr[i]);
    return ans;
}

int main() {
    int n;
    cout << "Enter Size of the Array: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter Elements of The Array: ";
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }

    vector<int> ans = funcVector(arr);

    cout << "Output using Vector: ";
    for(int ele: ans) cout << ele << " ";
    cout << endl;

    return 0;
}

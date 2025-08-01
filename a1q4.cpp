#include <iostream>
using namespace std;

int main()
{
      int n;
      cout<<"Enter the size of the array :";
      cin>>n;
      int arr[n];
      cout<<"Enter the array elements :"<<endl;
      for(int i=0;i<n;i++)
      {
            cin>>arr[i];
      }
      for(int i=0;i<n-1;i++)
      {
            for(int j=0;j<n-1-i;j++)
            {
                  if(arr[j]>arr[j+1])
                  swap(arr[j+1],arr[j]);
            }
      }
      cout<<"After bubble sort :\n";
      for(int i=0;i<n;i++)
      {
            cout<<arr[i]<<endl;
      }
      return 0;
}

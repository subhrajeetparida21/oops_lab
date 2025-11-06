#include <iostream>
using namespace std;

int main()
{
      int n1,n2,i=0;
      cout<<"Enter the size of two array : "<<endl;
      cin>>n1>>n2;
      int arr1[n1], arr2[n2];
      cout<<"Enter the elememts of the first array :"<<endl;
      for(i=0;i<n1;i++)
            cin>>arr1[i];
      cout<<"Enter the elements of the second arry :"<<endl;
      for(i=0;i<n2;i++)
            cin>>arr2[i];
      
      //check if first is subset of second
      bool ab=true;
      for(i=0;i<n1;i++)
      {
            bool found=false;
            for(int j=0;j<n2;j++)
            {
                  if(arr1[i]==arr2[j])
                  {
                        found=true;
                        break;
                  }
            }
            if(!found)
            {
                  ab=false;
                  break;
            }
      }

      //check if second is subset of first
      bool ba=true;
      for(i=0;i<n2;i++)
      {
            bool found=false;
            for(int j=0;j<n1;j++)
            {
                  if(arr2[i]==arr1[j])
                  {
                        found = true;
                        break;
                  }
            }
            if(!found)
            {
                  ba=false;
                  break;
            }
      }
      if(ab && ba)
            cout<<"Both arrays are equal";
      else if(ab)
            cout<<"First array is subset of second array";
      else if(ba)
            cout<<"Second array is subset of first array";
      else
            cout<<"Both arrays are different";
      return 0;

}
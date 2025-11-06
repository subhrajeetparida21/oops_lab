#include <iostream>
using namespace std;

int main()
{
      int n1,n2,n3,n4;
      cout<<"Enter the size of the first matrix :"<<endl;
      cin>>n1>>n2;
      cout<<"Enter the size of the second matrix :"<<endl;
      cin>>n3>>n4;
      int arr1[n1][n2], arr2[n3][n4];
      cout<<"Enter the elements of the first matrix :"<<endl;
      for(int i=0;i<n1;i++)
      {
            for(int j=0;j<n2;j++)
                  cin>>arr1[i][j];
      }
      cout<<"Enter the elements of the second matrix :"<<endl;
      for(int i=0;i<n3;i++)
      {
            for(int j=0;j<n4;j++)
                  cin>>arr2[i][j];
      }

      cout<<"First Matrix :"<<endl;
      for(int i=0;i<n1;i++)
      {
            for(int j=0;j<n2;j++)
                  cout<<arr1[i][j]<<" ";
            cout<<endl;
      }
      cout<<"Second Matrix :"<<endl;
      for(int i=0;i<n3;i++)
      {
            for(int j=0;j<n4;j++)
                  cout<<arr2[i][j]<<" ";
            cout<<endl;
      }

      if(n1!=n3 && n2!=n4)
            cout<<"Both the matrix cannot be added or subtracted"<<endl;
      else
      {
            cout<<"Sum of the two matrix : "<<endl;
            for(int i=0;i<n1;i++)
            {
                  for(int j=0;j<n2;j++)
                        cout<<arr1[i][j]+arr2[i][j]<<"  ";
                  cout<<endl;
            }
            cout<<"Subtraction of the first matrix from the second matrix : "<<endl;
            for(int i=0;i<n1;i++)
            {
                  for(int j=0;j<n2;j++)
                        cout<<arr2[i][j]-arr1[i][j]<<"  ";
                  cout<<endl;
            }
      }
      if(n2!=n3)
            cout<<"Both arrays cannnot be mulitplied";
      else
      {
            cout<<"Multiplication of matrix :"<<endl;
            for(int i=0;i<n1;i++)
            {
                  for(int j=0;j<n4;j++)
                  {
                        int val = 0;
                        for(int k=0;k<n2;k++)
                              val=val+arr1[i][k]*arr2[k][j];
                        cout<<val<<"  ";
                  }
                  cout<<endl;
            }
      }
            return 0;
}

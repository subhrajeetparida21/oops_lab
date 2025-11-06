#include <iostream>
using namespace std;

int main()
{
      int n, count=1;
      cout <<"Enter the no of lines"<<endl;
      cin >> n;
      for(int i=0;i<n;i++)
      {
            for(int space=n-i-1;space>=0;space--)
            {
                  cout<<" ";
            }
            for(int pattern=1;pattern<=count;pattern++)
            {
                  cout<<"*";
            }
            cout<<endl;
            count+=2;
      }

      return 0;

}
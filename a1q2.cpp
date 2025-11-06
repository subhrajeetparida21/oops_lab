#include <iostream>
using namespace std;
int main()
{
      int n,k=1;
      cout << "Enter the number of lines :";
      cin>>n;
      for(int i=0;i<n;i+=2)
      {
            for(int space=n-i-1;space>=0;space--)
                  cout<<" ";
            for(int pattern=k;pattern>0;pattern--)
                  cout<<pattern;
            for(int pattern=2;pattern<=k;pattern++)
                  cout<<pattern;
            k+=2;
            cout<<endl;
      }
      k=2;
      for(int i=1;i<n;i+=2)
      {
            for(int space=0;space<=k;space++)
            {
                  cout<<" ";
            }
            for(int pattern =n-k;pattern>0;pattern--)
            {
                  cout<<pattern;
            }
           for(int pattern=2;pattern<=n-k;pattern++)
           {
                  cout<<pattern;
           }
           cout<<endl;
           k+=2;
      }
      return 0;
}

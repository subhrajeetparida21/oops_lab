#include <iostream>
using namespace std;

int fact(int i)
{
      if(i==0)
            return 1;
      else
            return i*fact(i-1);
}

int main()
{
      int line;
      cout<<"Enter the number of lines :"<<endl;
      cin>>line;

      for(int i=0;i<line;i++)
      {
            for(int space=0;space<line-1-i;space++)
                  cout<<" ";
            
            for(int j=0;j<=i;j++)
            {
                  cout<<fact(i)/(fact(j)*fact(i-j))<<" ";
            }
            cout<<endl;
      }

      return 0;
}
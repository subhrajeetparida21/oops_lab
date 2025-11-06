#include <iostream>
using namespace std;

int main()
{
      string s1,s2;
      cout << "Enter first string : "<<endl;
      cin>>s1;
      cout << "Enter second string :"<<endl;
      cin>>s2;
      if(s1==s2)
            cout<<"Both the strings are equal";
      else
            cout<<"Both the strings are not equal";
      return 0;
}
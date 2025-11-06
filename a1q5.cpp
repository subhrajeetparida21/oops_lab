#include <iostream>
#include <bits/stdc++.h>
#include <string>

using namespace std;
string answer;
int main()
{
      int dec;
      cout<<"Enter a decimal number : ";
      cin>>dec;
      int copy=dec;
      char arr[]={'A','B','C','D','E','F'};
      string hex;
      while(copy!=0)
      {
            int rem = copy%16;
            if(rem>9&&rem<16)
            {
                  hex=arr[rem-10]+hex;
            }
            else
            {
                 char c = '0'+rem;
                 hex=c+hex;
            }
            copy/=16;
      }
      cout<<"Hexadecimal equivalent : "<<hex;
      return 0;
}

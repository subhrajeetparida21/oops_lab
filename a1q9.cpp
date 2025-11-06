#include <iostream>
using namespace std;

int main()
{
      int size, check=0;
      cout<<"Enter the size of the array :"<<endl;
      cin>>size;
      string det[size];
      cout<<"Enter the names to be sorted :"<<endl;
      for(int i=0;i<size;i++)
            cin>>det[i];
      for(int i=0;i<size-1;i++)
      {
            for(int j=0;j<size-i-1;j++)
            {
                  string str1=det[j],str2 = det[j+1];
                  if(str1.compare(str2)>=0)
                  {
                        swap(det[j], det[j+1]);
                        check=1;
                  }
            }
            if(check!=1)
                  break;
      }
      cout<<endl<<"Names after sorting : ";
      for(int i=0;i<size;i++)
            cout<<det[i]<<"->";


      return 0;
}
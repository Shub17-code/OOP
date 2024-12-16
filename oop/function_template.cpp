#include<iostream>
using namespace std;
template<typename T>
void sort(T a[],int n)
{
    int pos_min,i;
    T temp;
    for(int i=0;i<n-1;i++)
    {
        pos_min=i;
        for(int j=i+1;j<n;j++)
        {
            if (a[j]<a[pos_min])
                pos_min=j;
        }
        if(pos_min!=i)
        {
            temp=a[i];
            a[i]=a[pos_min];
            a[pos_min]=temp;
        }
    }
    cout<<"\n Sorted elements are:\n";
    for(i=0;i<n;i++)
       cout<<"\t"<<a[i];
}
int main()
{
   int n,i,ch;
   int a[10];
   float b[10];
   do
   {
       cout<<"\n Selection sort using function template";
       cout<<"\n 1. Sort integer numbers";
       cout<<"\n 2. Sort float numbers";
       cout<<"\n 3. Exit";
       cout<<"\n Enter your choice:";
       cin>>ch;
       switch(ch)
       {
           case 1: cout<<"\n Sorting integer numbers";
                  cout<<"\n Enter how many numbers";
                  cin>>n;
                  cout<<"Enter numbers:";
                  for(int i=0;i<n;i++)
                     cin>>a[i];
                  sort<int>(a,n);
                  break;
          case 2:cout<<"\n Sorting float numbers";
                  cout<<"\n Enter how many numbers";
                  cin>>n;
                  cout<<"Enter numbers:";
                  for(int i=0;i<n;i++)
                     cin>>b[i];
                  sort<float>(b,n);
                  break;
         case 3:exit(0);
      }
  }while (ch!=3);
  return 0;
}